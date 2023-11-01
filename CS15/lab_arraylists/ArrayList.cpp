/*
 *
 * ArrayList.cpp
 * Matt Russell && Matt Champlin
 * COMP15 lab 1
 * 1/6/2021
 * 9/12/2021 - updated for cs15 by mrussell
 *
 * Function definitions for the ArrayList class
 *
 * 
 *
 */

#include "ArrayList.h"
#include <sstream>

using namespace std;

/*
 * name:      ArrayList default constructor
 * purpose:   initialize an empty ArrayList
 * arguments: none
 * returns:   none
 * effects:   numItems to 0 (also updates capacity and data array)
 */
ArrayList::ArrayList() {
    numItems = 0;
    capacity = 0;
    data = nullptr;
}

/*
 * name:      ArrayList destructor
 * purpose:   free memory associated with the ArrayList
 * arguments: none
 * returns:   none
 * effects:   frees memory allocated by Arraylist instances
 */
ArrayList::~ArrayList() {
    delete [] data;
}

/*
 * name:      size
 * purpose:   determine the number of items in the ArrayList
 * arguments: none
 * returns:   number of elements currently stored in the ArrayList
 * effects:   none
 */
int ArrayList::size() const {
    return numItems; // Placeholder (remove when you implement this!)
}

/*
 * name:      isEmpty
 * purpose:   determines if the ArrayList is empty or not
 * arguments: none
 * returns:   true if ArrayList contains no elements, false otherwise
 * effects:   none
 */
bool ArrayList::isEmpty() const {
    return numItems == 0; // Placeholder (remove when you implement this!)
}

/*
 * name:      toString
 * purpose:   turns the array into a string, and returns it
 * arguments: none
 * returns:   a string representation of the array
 * effects:   none
 */
std::string ArrayList::toString() const {
    std::stringstream ss;
    ss << "[";
    for (int i = 0; i < size(); i++)
    {
        ss << data[i];
        if (i == size() - 1)
        {
            ;
        } else {
            ss << ",";
        }
    }
    ss << "]";
    return ss.str();
}

/*
 * name:      pushAtBack
 * purpose:   push the provided integer into the back of the ArrayList
 * arguments: an integer to add to the back of the list
 * returns:   none
 * effects:   increases num elements of ArrayList by 1,
 *            adds element to list
 */
void ArrayList::pushAtBack(int elem) {
    if (numItems == capacity)
    {
        expand();
        data[numItems] = elem;
        numItems++;
    } else {
        data[numItems] = elem;
        numItems++;
    }
    
}

/*
 * name:      expand
 * purpose:   increase the capacity of the ArrayList
 * arguments: none
 * returns:   none
 * effects:   creates new, larger array on heap, copies over elements,
 *            and recycles the old array
 */
void ArrayList::expand() {
    capacity = capacity * 2 + 2;
    int *newArray = new int[capacity];
    for (int i = 0; i < numItems; i++)
    {
        newArray[i] = data[i];
    }
    delete [] data;
    data = newArray;
}

/*
 * name:      find - JFFE
 * purpose:   determine if the provided integer is within the ArrayList
 * arguments: an integer to find
 * returns:   returns true if x is in the ArrayList, false otherwise
 * effects:   none
 */
bool ArrayList::find(int to_find) const {
    for (int i = 0; i < numItems; i++)
    {
        if (data[i] == to_find)
        {
            return true;
        }
    }
    return false;
}


/*
 * name:      popFromBack - JFFE

 * purpose:   remove the last item from the ArrayList
 * arguments: none
 * returns:   none
 * effects:   decreases num items of ArrayList by 1
 *            removes the last item from the list
 */
void ArrayList::popFromBack() {
    numItems--;
    data[numItems] = 0;
}
