/*
 *  CharLinkedList.cpp
 *  Federico Sorcini
 *  9/30/23
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  
 *
 */

#include "CharLinkedList.h"

// for the print function
#include <iostream>

using namespace std;

/* Purpose: initializes an empty CharLinkedList */
CharLinkedList::CharLinkedList()
{
    front = nullptr;
    back = nullptr;
    numItems = 0;
}

/* Purpose: initializes a CharLinkedList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharLinkedList::CharLinkedList(char c)
{
    front = nullptr;
    back = nullptr;
    numItems = 0;
    Node *newNode = new Node();
    newNode->data = c;
    newNode->next = nullptr;
    this->front = newNode;
    this->back = newNode;
    this->numItems++;
}

/* Purpose: initializes a CharLinkedList containing all of the specified 
 *     characters, in the given order
 * Parameters: An array (in order) of characters to be stored in the list;
 *     the length of the given array (as an int)
 */
CharLinkedList::CharLinkedList(char arr[], int size)
{
    front = nullptr;
    back = nullptr;
    numItems = 0;
    for (int i = 0; i < size; i++) {
        pushAtBack(arr[i]);
    }
}

/* Purpose: copy constructor -- creates a list with the same information as
 *     the one passed in
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) 
{
    this->front = nullptr;
    this->back = nullptr;
    this->numItems = 0;
    Node *curr = other.front;
    while (curr != nullptr) {        
        pushAtBack(curr->data);
        curr = curr->next;
    }
}

/* Purpose: destructor -- frees all memory associated with the list */
CharLinkedList::~CharLinkedList()
{
    recycleList(this->front);
}

/* Purpose: assignment operator -- makes the current list contain the same
 *     information as the one on the right hand side
 */
CharLinkedList &CharLinkedList::operator =(const CharLinkedList &other) 
{
    if (this == &other) {
        return *this;
    }
    recycleList(front);
    this->front = nullptr;
    this->back = nullptr;
    this->numItems = 0;
    Node *curr = other.front;
    while (curr != nullptr) {        
        pushAtBack(curr->data);
        curr = curr->next;
    }
    return *this;
}

/* isEmpty
 * Purpose: Check if the list is empty
 * Returns: a boolean -- true if the list is empty, false if it isn't
 */
bool CharLinkedList::isEmpty() const 
{
    if (this->numItems == 0) {
        return true;
    } else {
        return false;
    }
}

/* size
 * Purpose: Get the number of characters being stored in the list
 * Returns: The number of characters currently stored in the list, as an
 *     int (will never be negative)
 */
int CharLinkedList::size() const 
{
    return numItems;
}

/* first
 * Purpose: Get the first element in the list.
 * Returns: The first element in the list, as a char.
 */
char CharLinkedList::first() const 
{
    if (numItems == 0) {
        throw std::runtime_error("cannot get first of empty LinkedList"); 
    } else {
        return this->front->data;
    }
}

/* last
 * Purpose: Get the last element in the list.
 * Returns: The last element in the list, as a char.
 */
char CharLinkedList::last() const 
{
    if (numItems == 0) {
        throw std::runtime_error("cannot get last of empty LinkedList"); 
    } else {
        return this->back->data;
    }
}

/* elementAt
 * Purpose: Get the character at a given position.
 * Parameters: The index to be accessed, as an int.
 * Returns: The element at the specified index, as a char
 */
char CharLinkedList::elementAt(int index) const
{
    if (index < 0 || index >= this->numItems) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")"); 
    } else {
        int i = 0;
        return elementAtHelper(this->front, index, i);
    }
}

/* pushAtBack
 * Purpose: Adds a character to the back of the list
 * Parameters: The character to be added to the list
 */
void CharLinkedList::pushAtBack(char c)
{
    Node *newNode = new Node();
    newNode->data = c;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (this->back != nullptr) {
        this->back->next = newNode;
        newNode->prev = this->back;
        this->back = newNode;
    } else {
        this->front = newNode;
        this->back = newNode;
    }
    numItems++;
}

/* pushAtFront
 * Purpose: Adds a character to the front of the list
 * Parameters: The character to be added to the list
 */
void CharLinkedList::pushAtFront(char c)
{
    Node *newNode = new Node();
    newNode->data = c;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    if (this->front != nullptr) {
        this->front->prev = newNode;
        newNode->next = this->front;
        this->front = newNode;
    } else {
        this->front = newNode;
        this->back = newNode;
    }
    numItems++;
}

/* insertAt
 * Purpose: Adds a character to the list at a given position
 * Parameters: The character to be added to the list and the position at which
 *     it should be added. 
 */
void CharLinkedList::insertAt(char c, int index)
{
    if (index < 0 || index > this->numItems) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + "]"); 
    } else {
        if (index == 0) {
        pushAtFront(c);
        } else if (index == numItems) {
            pushAtBack(c);

        } else {
            Node *newNode = new Node();
            newNode->data = c;
            newNode->next = this->front;
            for (int i = 0; i <= index; i++) {
                if (i == index) {
                    newNode->prev = newNode->next->prev;
                    newNode->next->prev->next = newNode;
                    newNode->next->prev = newNode;
                    numItems++;
                } else {
                    newNode->next = newNode->next->next;
                }
            }
        }
    }
}

/* insertInOrder
 * Purpose: Adds a character to the list in ASCII order
 * Parameters: The character to be added to the list 
 */
void CharLinkedList::insertInOrder(char c)
{
    Node *curr = new Node();
    curr = this->front;
    for (int i = 0; i <= numItems; i++) {
        if (i == numItems) {
            pushAtBack(c);
            break;
        } else if (c <= curr->data) {
            insertAt(c, i);
            break;
        } else {
            curr = curr->next;
        }
    }
}

/* toString
 * Purpose: Converts the list of chars into a string along with the 
 *      size of the list.
 * Returns: The formatted string of chars along with the size of the 
 *      list.
 */
std::string CharLinkedList::toString() const {
    string s = "";
    s.append("[CharLinkedList of size ");
    s.append(to_string(numItems));
    s.append(" <<");
    Node *curr = this->front;
    while (curr != nullptr) {
        s.append(1, curr->data);
        curr = curr->next;
    }
    s.append(">>]");
    return s;
}

/* toReverseString
 * Purpose: Converts the list of chars into a string, but in reverse order, 
 *      along with the size of the list.
 * Returns: The formatted and reversed string of chars along with the size of the 
 *      list.
 */
std::string CharLinkedList::toReverseString() const {
    string s = "";
    s.append("[CharLinkedList of size ");
    s.append(to_string(numItems));
    s.append(" <<");
    Node *curr = this->back;
    while (curr != nullptr) {
        s.append(1, curr->data);
        curr = curr->prev;;
    }
    s.append(">>]");
    return s;
}

/* clear
 * Purpose: Makes the list empty
 */
void CharLinkedList::clear() 
{
    while (numItems > 0) {
        popFromFront();
    }
}

/* popFromFront
 * Purpose: Removes the first element from the list
 */
void CharLinkedList::popFromFront()
{
    if (numItems == 0) {
        throw std::runtime_error("cannot pop from empty LinkedList"); 
    } else if (numItems == 1) {
        delete front;
        numItems--;
    } else {
        Node *node = front->next;
        delete front;
        front = node;
        front->prev = nullptr;
        numItems--;
    }
}

/* popFromBack
 * Purpose: Removes the last element from the list
 */
void CharLinkedList::popFromBack()
{
    if (numItems == 0) {
        throw std::runtime_error("cannot pop from empty LinkedList"); 
    } else if (numItems == 1) {
        delete back;
        numItems--;
    } else {
        Node *node = back->prev;
        delete back;
        back = node;
        back->next = nullptr;
        numItems--;
    }
}

/* removeAt
 * Purpose: Removes the element at a given index
 * Parameters: The position at which to remove an element.
 */
void CharLinkedList::removeAt(int index)
{
    if (index < 0 || index >= this->numItems) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")"); 
    } else {
        Node *curr = this->front;
        for (int i = 0; i < numItems; i++) {
            if (i == index) {
                if (curr == this->front) {
                    popFromFront();
                } else if (curr == this->back) {
                    popFromBack();
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    numItems--;
                }
            } else {
                curr = curr->next;
            }
        }
    }
}

/* replaceAt
 * Purpose: Replaces the element at the given index with the given value
 * Parameters: A character to put in the list and the index of the
 *     element to replace.
 */
void CharLinkedList::replaceAt(char c, int index)
{
    if (index < 0 || index >= this->numItems) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")"); 
    } else {
        int i = 0;
        replaceAtHelper(this->front, c, index, i);
    }
}

/* concatenate
 * Purpose: Adds the contents of a CharLinkedList to the back of the current 
 *     one.
 * Parameters: A CharLinkedList whose contents should be pushed to the back of 
 *     the current list. Will not be altered
 */
void CharLinkedList::concatenate(const CharLinkedList *other)
{
    CharLinkedList otherCopy(*other);
    while (otherCopy.front != nullptr) {
        this->pushAtBack(otherCopy.front->data);
        otherCopy.popFromFront();
    }  
}