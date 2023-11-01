/*
 *      Passenger.h
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
#include <fstream>
#include <string>

struct Passenger
{

        int id, from, to;
        
        // Constructor for an empty Passenger
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        // Constructor for a Passenger with a given ID, from, and to
        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        // Prints the passenger information in the appropriate format
        void print(std::ostream &output);

};

#endif
