/*
 *      MetroSim.h
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#ifndef METROSIM_H
#define METROSIM_H

#include "PassengerQueue.h"
#include <vector>
#include <string>
#include <fstream>



// Put any other necessary includes here


// Put any other structs you need here

class MetroSim {
public:
    
    // Constructor
    MetroSim(const std::string& stationsFile, const std::string& outputFile, 
        const std::string& commandsFile);
    
    // Destructor
    ~MetroSim();

    // Run the simulation
    void run();
    
    // Process a single command
    bool processCommand(std::istream& input);
    
    // Print the current state of the simulation
    void printMetroSim();

    // Add a passenger to the simulation
    void addPassenger(int arrivalStation, int departureStation);
    
    // Move a train to the next station
    void moveTrain();
    
    // End the simulation
    void endSim();
    
    // Print that a Passenger has left the train to the output file
    void writePassengerToOutputFile(int passengerID, const std::string& 
        stationName);
    


private:
    
    // train: a vector of PassengerQueues
    std::vector<PassengerQueue> train;

    // stations: a vector of PassengerQueues
    std::vector<PassengerQueue> stations;

    // the station at which the train is currently located
    int currentStation;

    // the output file to write to
    std::ofstream output;

    // the commands file to read from
    std::string commandsFile;



    // the number of passengers in the simulation
    int numPassengers;

};

#endif // METROSIM_H
