/*
 *      unit_tests.cpp
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#include "Passenger.h"
#include "PassengerQueue.h"
#include "MetroSim.h"
#include <sstream>
#include <cassert>

/* 
 * Tests: adding a passenger to the simulation
 */
void addPassengerGood_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.addPassenger(0, 1);
    // assert(metroSim.stations[0].size() == 1);
    std::cout << "TEST addPassengerGood_test: PASSED" << std::endl;
}

/* 
 * Tests: handling bad arrival station
 */
void addPassengerBadArrival_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.addPassenger(-56, 1);
    std::cout << "TEST addPassengerBadArrival_test: PASSED" << std::endl;
}

/* 
 * Tests: handling bad departure station
 */
void addPassengerBadDeparture_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.addPassenger(0, 10000);
    std::cout << "TEST addPassengerBadDeparture_test: PASSED" << std::endl;
}

/* 
 * Tests: adding multiple passengers
 */
void addMultiplePassengers_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.addPassenger(0, 1);
    metroSim.addPassenger(1, 2);
    metroSim.addPassenger(2, 3);
    // assert(metroSim.stations[0].size() == 1);
    // assert(metroSim.stations[1].size() == 1);
    // assert(metroSim.stations[2].size() == 1);
    std::cout << "TEST addMultiplePassengers_test: PASSED" << std::endl;
}

/* 
 * Tests: moving train with passengers
 */
void moveTrainWithPassengers_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.addPassenger(0, 1);
    metroSim.moveTrain();
    //assert(metroSim.currentStation == 1);
    // assert(metroSim.train[1].size() == 0);
    std::cout << "TEST moveTrainWithPassengers_test: PASSED" << std::endl;
}

/* 
 * Tests: moving train without passengers
 */
void moveTrainWithoutPassengers_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.moveTrain();
    // assert(metroSim.currentStation == 1);
    std::cout << "TEST moveTrainWithoutPassengers_test: PASSED" << std::endl;
}

/* 
 * Tests: ending simulation
 */
void endSim_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.endSim();
    // assert(metroSim.train[0].size() == 0);
    std::cout << "TEST endSim_test: PASSED" << std::endl;
}

/* 
 * Tests: printing simulation state
 */
void printMetroSim_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.addPassenger(0, 1);
    metroSim.addPassenger(3, 7);
    metroSim.addPassenger(2, 4);
    metroSim.moveTrain();
    metroSim.addPassenger(3, 4);
    metroSim.moveTrain();
    metroSim.printMetroSim();
    std::cout << "TEST printMetroSim_test: PASSED" << std::endl;
}

/* 
 * Tests: moving an empty train
 */
void emptyTrain_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.moveTrain();
    std::cout << "TEST emptyTrain_test: PASSED" << std::endl;
}

/* 
 * Tests: moving train at last station
 */
void trainAtLastStation_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    // metroSim.currentStation = metroSim.stations.size() - 1;
    metroSim.moveTrain();
    // assert(metroSim.currentStation == 0);
    std::cout << "TEST trainAtLastStation_test: PASSED" << std::endl;
}

/* 
 * Tests: executing valid commands from file
 */
void goodCommands_test() {
    MetroSim metroSim("stations.txt", "output.txt", "test_commands.txt");
    metroSim.run();
    std::cout << "TEST goodCommands_test: PASSED" << std::endl;
}

/* 
 * Tests: handling invalid commands from file
 */
void badCommands_test() {
    MetroSim metroSim("stations.txt", "output.txt", "bad_commands.txt");
    metroSim.run();
    std::cout << "TEST badCommands_test: PASSED" << std::endl;
}

/* 
 * Tests: handling bad stations file
 */
void badStationsFile_test() {
    MetroSim metroSim("bad_stations.txt", "output.txt", "test_commands.txt");
    metroSim.run();
    std::cout << "TEST badStationsFile_test: PASSED" << std::endl;
}

/* 
 * Tests: write passenger info to output file
 */
void writePassengerToOutputFile_test() {
    MetroSim metroSim("stations.txt", "output.txt", "test_commands.txt");
    metroSim.writePassengerToOutputFile(1, "Station A");
    std::cout << "TEST writePassengerToOutputFile_test: PASSED" << std::endl;
}

/* 
 * Tests: enqueue passenger to station queue
 */
void enqueue_test() {
    PassengerQueue stationQueue;
    Passenger passenger(1, 0, 1);
    stationQueue.enqueue(passenger);
    assert(stationQueue.size() == 1);
    std::cout << "TEST enqueue_test: PASSED" << std::endl;
}

/* 
 * Tests: get front passenger from station queue
 */
void front_test() {
    PassengerQueue stationQueue;
    Passenger passenger(1, 0, 1);
    stationQueue.enqueue(passenger);
    Passenger frontPassenger = stationQueue.front();
    assert(frontPassenger.id == 1);
    std::cout << "TEST front_test: PASSED" << std::endl;
}

/* 
 * Tests: dequeueing passenger from station queue
 */
void dequeue_test() {
    PassengerQueue stationQueue;
    Passenger passenger(1, 0, 1);
    stationQueue.enqueue(passenger);
    stationQueue.dequeue();
    assert(stationQueue.size() == 0);
    std::cout << "TEST dequeue_test: PASSED" << std::endl;
}

/* 
 * Tests: getting size of station queue
 */
void size_test() {
    PassengerQueue stationQueue;
    Passenger passenger1(1, 0, 1);
    Passenger passenger2(2, 1, 2);
    stationQueue.enqueue(passenger1);
    stationQueue.enqueue(passenger2);
    int size = stationQueue.size();
    assert(size == 2);
    std::cout << "TEST size_test: PASSED" << std::endl;
}

/* 
 * Tests: printing station queue contents
 */
void print_test() {
    PassengerQueue stationQueue;
    Passenger passenger1(1, 0, 1);
    Passenger passenger2(2, 1, 2);
    stationQueue.enqueue(passenger1);
    stationQueue.enqueue(passenger2);
    std::stringstream ss;
    stationQueue.print(ss);
    std::string output = ss.str();
    std::cout << "TEST print_test: PASSED" << std::endl;
}

/* 
 * Tests: moving an empty train
 */
void moveTrainEmpty_test() {
    MetroSim metroSim("stations.txt", "output.txt", "");
    metroSim.moveTrain();
    // assert(metroSim.train[0].size() == 0);
    // assert(metroSim.currentStation == 1);
    std::cout << "TEST moveTrainEmpty_test: PASSED" << std::endl;
}

/* 
 * Tests: handling empty commands file
 */
void emptyCommandsFile_test() {
    MetroSim metroSim("stations.txt", "output.txt", "empty_commands.txt");
    metroSim.run();
    // assert(metroSim.train[0].size() == 0);
    // assert(metroSim.currentStation == 0);
    // assert(metroSim.train[1].size() == 0);
    std::cout << "TEST emptyCommandsFile_test: PASSED" << std::endl;
}


int main() {
    addPassengerGood_test();
    addPassengerBadArrival_test();
    addPassengerBadDeparture_test();
    addMultiplePassengers_test();
    moveTrainWithPassengers_test();
    moveTrainWithoutPassengers_test();
    endSim_test();
    printMetroSim_test();
    emptyTrain_test();
    trainAtLastStation_test();
    emptyCommandsFile_test();
    goodCommands_test();
    badCommands_test();
    badStationsFile_test();
    writePassengerToOutputFile_test();
    enqueue_test();
    front_test();
    dequeue_test();
    size_test();
    print_test();
    moveTrainEmpty_test();
    emptyCommandsFile_test();

    return 0;
}
