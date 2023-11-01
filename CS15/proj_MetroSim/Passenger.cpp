/*
 *      Passenger.cpp
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/* print
 * Purpose: Prints the passenger information in the appropriate format
 * Parameters: the output stream to print to
 */
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
