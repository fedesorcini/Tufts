/*
 *      MetroSim.cpp
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#include "MetroSim.h"
#include <iostream>
#include <sstream>

/* MetroSim Constructor
 * Purpose: Initializes the MetroSim object
 * Parameters: the stationsfile, the outputfile, and the commandsfile 
 *      (optional)
 * Other information: checks whether all input and output files are valid, 
 *      initializes the train and the stations, 
 *      and puts the train at station 0
 */
MetroSim::MetroSim(const std::string& stationsFile, const std::string& 
    outputFile, const std::string& commandsFile) : commandsFile(commandsFile) {
        currentStation = 0;
        numPassengers = 1;
        std::ifstream stationInput(stationsFile);
        if (not stationInput.is_open()) {
            std::cerr << "Error: could not open file " << stationsFile 
                << std::endl;
            exit(EXIT_FAILURE);
        }
        std::string stationName;
        while (getline(stationInput, stationName)) {
            PassengerQueue stationQueue;
            stationQueue.name = stationName;
            stations.push_back(stationQueue);
        }
        stationInput.close();

        std::ifstream commandsInput(commandsFile);
        if ((not commandsFile.empty()) and (not commandsInput.is_open())) {
            std::cerr << "Error: could not open file " << commandsFile << 
                std::endl;
            exit(EXIT_FAILURE);
        }

        output.open(outputFile);
        if (not output.is_open()) {
            std::cerr << "Error: could not open file " << outputFile 
                << std::endl;
            exit(EXIT_FAILURE);
        }

        train.resize(stations.size());
}

/* MetroSim Destructor
 * Purpose: Destructor for the MetroSim object
 */
MetroSim::~MetroSim() {
    output.close();
}

/* run
 * Purpose: begins running the MetroSim object 
 * Other information: depending on whether a commands file is provided, 
 *      it continues to process commands from the input stream until either 
 *      the end of the commands file is reached, the command 'm f' is entered
 */
void MetroSim::run() {
    std::string command;
    if (commandsFile.empty()) {
        printMetroSim();
        while (processCommand(std::cin)) {
            printMetroSim();
        }
    } else {
        printMetroSim();
        std::ifstream commandsInput(commandsFile);
        if (not commandsInput.is_open()) {
            std::cerr << "Error: could not open file " << commandsFile << 
                std::endl;
            exit(EXIT_FAILURE);
        } else {
            while (processCommand(commandsInput)) {
                printMetroSim();
            }
        }
    }
}

/* processCommand
 * Purpose: to process a single command from the input stream
 * Parameters: the input stream
 * Returns: a boolean value indicating whether the simulation 
 *      should continue (true) or whether it should end (false)
 * Other information: if any incorrect command is entered, the 
 *      user will be prompted with: "Invalid command. Try again."
 */
bool MetroSim::processCommand(std::istream& input) {
    std::cout << "Command? ";
    std::string command;
    input >> command;
    if (command == "p") {
        int arrival, departure;
        if (input >> arrival >> departure) {
            addPassenger(arrival, departure);
            return true;
        }
    } else if (command == "m") {
        std::string command2;
        if (input >> command2) {
            if (command2 == "m") {
                moveTrain();
                return true;
            } else if (command2 == "f") {
                endSim();
                return false;
            }
        }
    } else if (input.eof()) {
        endSim();
        return false;
    }
    std::cout << "Invalid command. Try again." << std::endl;
    return true;
}

/* printMetroSim
 * Purpose: to print the current state of the simulation to cout
 */
void MetroSim::printMetroSim() {
    std::cout << "Passengers on the train: {";
    for (int i = 0; i < train.size(); i++) {
        train[i].print(std::cout);
    }
    std::cout << "}" << std::endl;
    for (int i = 0; i < stations.size(); i++) {
        if (i == currentStation) {
            std::cout << "TRAIN: ";
        } else {
            std::cout << "       ";
        }
        std::cout << "[" << i << "] " << stations[i].name << " {";
        stations[i].print(std::cout);
        std::cout << "}" << std::endl;
    }
}

/* addPassenger
 * Purpose: to add a Passenger to the station that matches the Passeneger's 
 *       arrival station
 * Parameters: the Passenger's arrival station and the Passenger's departure 
 *      station
 * Other information: increases the passenger count by 1
 */
void MetroSim::addPassenger(int arrivalStation, int departureStation) {
    if ((arrivalStation < 0 or arrivalStation > stations.size()) and 
        (departureStation < 0 or departureStation > stations.size())) {
        std::cerr << "Error: arrival and departure stations out of range" 
            << std::endl;
    } else if (arrivalStation < 0 or arrivalStation > stations.size()) {
        std::cerr << "Error: arrival station out of range" << std::endl;
    } else if (departureStation < 0 or departureStation > stations.size()) {
        std::cerr << "Error: departure station out of range" << std::endl;
    } else {
        Passenger newPassenger(numPassengers, arrivalStation, 
            departureStation);
        stations[arrivalStation].enqueue(newPassenger);
        numPassengers++;
    }
}

/* moveTrain
 * Purpose: to enqueue all Passengers who are at the station the train is about
        to leave from, to move the train to the next station, and then to 
        dequeue all Passengers whose departure station is the station the 
        train arrives at
 */
void MetroSim::moveTrain() {
    while (stations[currentStation].size() > 0) {
        train[stations[currentStation].front().to].
            enqueue(stations[currentStation].front());
        stations[currentStation].dequeue();
    }
    currentStation = (currentStation + 1) % stations.size();
    while (train[currentStation].size() > 0) {
        writePassengerToOutputFile(train[currentStation].front().id, 
            stations[currentStation].name);
        train[currentStation].dequeue();
    }
}

/* endSim
 * Purpose: to end the simulation
 * Other information: dequeues all Passengers from the train and from the 
 *      stations
 */
void MetroSim::endSim() {
    for (int i = 0; i < train.size(); i++) {
        while (train[i].size() > 0) {
            train[i].dequeue();
        }
    }
    for (int i = 0; i < stations.size(); i++) {
        while (stations[i].size() > 0) {
            stations[i].dequeue();
        }
    }
}

/* writePassengerToOutputFile
 * Purpose: to write a Passenger that has left the train to the output file
 * Parameters: the Passenger's id, and the name of the station the Passenger 
 *      left the train at
 */
void MetroSim::writePassengerToOutputFile(int passengerID, 
    const std::string& stationName) {
        output << "Passenger " << passengerID << " left train at station " 
            << stationName << std::endl;
}
