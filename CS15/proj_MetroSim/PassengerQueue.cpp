/*
 *      PassengerQueue.cpp
 *      MetroSim
 *      Comp 15 Proj 1
 *      Federico Sorcini
 */

#include "PassengerQueue.h"

/* front
 * Purpose: to return the first Passenger in the passengerQueue
 * Returns: the first Passenger in the passengerQueue
 */
Passenger PassengerQueue::front() {
    return passengerQueue.front();
}

/* dequeue
 * Purpose: to remove the first Passenger from the passengerQueue
 * Other information: reduces the size of the passengerQueue by 1
 */
void PassengerQueue::dequeue() {
    passengerQueue.pop_front();
}

/* enqueue
 * Purpose: to add a Passenger to the end of the passengerQueue
 * Parameters: the Passenger to be added to the end of the passengerQueue
 * Other information: increases the size of the passengerQueue by 1
 */
void PassengerQueue::enqueue(const Passenger &passenger) {
    passengerQueue.push_back(passenger);
}

/* size
 * Purpose: to return the number of Passengers in the passengerQueue
 * Returns: the number of Passengers in the passengerQueue
 */
int PassengerQueue::size() {
    return passengerQueue.size();
}

/* print
 * Purpose: to print the Passengers the passengerQueue in the appropriate 
        format
 * Parameters: the output stream to which the contents of the passengerQueue 
 *      will be printed
 */
void PassengerQueue::print(std::ostream &output) {
    for (auto p : passengerQueue) {
        p.print(output);
    }
}
