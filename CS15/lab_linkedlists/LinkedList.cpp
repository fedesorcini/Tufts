/*
 * LinkedList.cpp
 *
 * COMP 15 homework 1
 * by Tyler Calabrese, January 2020
 * Edited by Matt Russell, Juliana Vega, and Alexis Blair, Jan 2021
 *
 * An implementation of the LinkedList interface, the LinkedList can be used
 * to store Planets.
 *
 * NOTE: This is implemented using a singly-linked list with no back pointer.
 */
#include "LinkedList.h"
#include <sstream>
#include <string>

/* Purpose: Initializes an empty LinkedList */
LinkedList::LinkedList() {
    front = nullptr;
    size  = 0;
}

/* toString
 *    Purpose: Report the state of the list as a string
 * Parameters: None
 *    Returns: A string with the state of the list
 */
std::string LinkedList::toString() const {
    std::stringstream ss;
    ss << "LinkedList of size " << this->size << "\n";
    ss << "---------------------\n";

    Node *curr = this->front;
    while (curr != nullptr) {
        ss << curr->toString() << "\n";
        curr = curr->next;
    }

    return ss.str();
}


/* ****************************************
 * TODO: implement the LinkedList destructor
 * ****************************************
 * destructor
 *    Purpose: Free heap-allocated memory of 'this' 
 * Parameters: None
 *    Returns: None
 */
LinkedList::~LinkedList() {
    Node *curr = this->front;
    while (curr!= nullptr) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
}


/* ****************************************
 * TODO: implement the pushAtFront function
 * ****************************************
 * pushAtFront
 *    Purpose: Adds a Planet to the front of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtFront(Planet p) {
    Node *newNode = new Node();
    newNode->info = p;
    newNode->next = this->front;
    this->front = newNode;
    this->size++;
}

/*
 * ****************************************
 * TODO: implement the pushAtBack function
 * ****************************************
 * pushAtBack
 *    Purpose: Adds a Planet to the back of the list
 * Parameters: The Planet to be added to the list
 *    Returns: None
 */
void LinkedList::pushAtBack(Planet p) {
    Node* new_node = new Node();
    Node *back = front;
    new_node->info = p;
    new_node->next = nullptr;
    if (front == nullptr)
    {
        front = new_node;
        size++;
        return;
    }
    while (back->next != nullptr)
        back = back->next;
    back->next = new_node;
    size++;
    return;
}


/* ****************************************
 * TODO (Bonus JFFE): implement the reverse function
 * ****************************************
 * reverse
 *    Purpose: Reverses the list
 * Parameters: None
 *    Returns: None
 */

void LinkedList::reverse() {
    Node *curr = this->front;
    Node *prev = nullptr;
    while (curr!= nullptr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    this->front = prev;
}
    
