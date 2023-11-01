/*
 *      PassengerQueue.h
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#ifndef _PASSENGER_QUEUE_H
#define _PASSENGER_QUEUE_H

#include "Passenger.h"
#include <list>

class PassengerQueue {
public:
    
    // returns the first Passengerin the passengerQueue
    Passenger front();
    
    // removes the first Passenger from the passengerQueue
    void dequeue();
    
    // adds a Passenger to the back of the passengerQueue
    void enqueue(const Passenger &passenger);
    
    // returns the number of Passengers in the passengerQueue
    int size();
    
    // prints the Passengers the passengerQueue in the appropriate format
    void print(std::ostream &output);

    // the name of the passengerQueue, meant to represent the name of the 
    //      station, or the name of the station that a train car will be 
    //      enqueued with Passengers whose departure station 
    std::string name;

private:

    // a list of Passenger objects
    std::list<Passenger> passengerQueue;

};

#endif
