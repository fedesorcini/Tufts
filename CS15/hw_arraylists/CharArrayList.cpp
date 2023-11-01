/*
 *  CharArrayList.cpp
 *  FEDERICO SORCINI
 *  21 September, 2023
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Definitions of CharArrayList Class objects and methods
 *
 */

#include "CharArrayList.h"
#include <iostream>

using namespace std;

/* Constructor 1
 * Purpose: initializes an empty CharArrayList */
CharArrayList::CharArrayList() {
    numItems = 0;
    capacity = 0;
    data = nullptr;
}

/* Constructor 2
 * Purpose: initializes a CharArrayList containing one character
 * Parameters: the character that should be stored in the new list
 */
CharArrayList::CharArrayList(char c) {
    numItems = 1;
    capacity = 1;
    data = new char[capacity];
    data[0] = c;
}

/* Constructor 3
 * Purpose: initializes a CharArrayList containing all of the specified 
 *      characters
 * Parameters: An array of characters to be stored in the list;
 *    the length of the given array (as an int)
 */
CharArrayList::CharArrayList(char arr[], int size) {
    numItems = size;
    capacity = size;
    data = new char[capacity];
    for (int i = 0; i < numItems; i++)
    {
        data[i] = arr[i];
    }
    
}

/* Copy Constructor
 * Purpose: Creates an arraylist with the same information as
 *          the one passed in
 * Parameters: An array of characters to be copied from
 */
CharArrayList::CharArrayList(const CharArrayList &other) {
    numItems = other.numItems;
    capacity = other.numItems;
    data = new char[capacity];
    for (int i = 0; i < numItems; i++) {
        data[i] = other.data[i];
    }
}

/* Purpose: frees memory allocated for the list */
CharArrayList::~CharArrayList() {
    delete [] data;
}

/* Assignment operator
 * Purpose: sets the current list contain the same
 *          information as the other
 * Parameters: the current list as well as the one to be copied from
 */
CharArrayList &CharArrayList::operator =(const CharArrayList &other) {
    if (this == &other) {
        return *this;
    }
    delete [] data;
    numItems = other.numItems;
    capacity = other.numItems;
    data = new char[capacity];
    for (int i = 0; i < numItems; i++) {
        *(data + i) = *(other.data + i);
    }
    return *this;
}

/* isEmpty
 * Purpose: Check if the list is empty
 * Returns: a boolean: true if the list is empty, false if it isn't
 */
bool CharArrayList::isEmpty() const {
    return numItems == 0;
}

/* clear
 * Purpose: Makes the list empty, but does not free any memory
 */
void CharArrayList::clear() {
    for (int i = 0; i < numItems; i++) {
        data[i] = 0;
    }
    numItems = 0;
}

/* size
 * Purpose: Gets the current number of characters in the list
 * Returns: The number of characters currently stored in the list, as an
 *      int
 */
int CharArrayList::size() const {
    return numItems;
}

/* first
 * Purpose: Gets the first item in the list.
 * Returns: The first char in the list.
 */
char CharArrayList::first() const {
    if (numItems == 0) {
        throw std::runtime_error("cannot get first of empty ArrayList");
        return 0;
    } else {
        return data[0];
    }
}

/* last
 * Purpose: Gets the last item in the list.
 * Returns: The last char in the list.
 */
char CharArrayList::last() const {
    if (numItems == 0) {
        throw std::runtime_error("cannot get last of empty ArrayList");
        return 0;
    } else {
        return data[numItems - 1];
    }
}

/* elementAt
 * Purpose: Gets the character at a given index.
 * Parameters: The index of the char to be gotten.
 * Returns: The char at the given index.
 */
char CharArrayList::elementAt(int index) const {
    if (index >= numItems || index < 0) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")");
    } else {
        return data[index];
    }
}

/* toString
 * Purpose: Converts the arraylist of chars into a string along with the 
 *      size of the arraylist.
 * Returns: The formatted string of chars along with the size of the 
 *      arraylist.
 */
std::string CharArrayList::toString() const {
    std::string s;
    s.append("[CharArrayList of size ");
    s.append(to_string(numItems));
    s.append(" <<");
    for (int i = 0; i < numItems; i++) {
        s.append(1, data[i]);
    }
    s.append(">>]");
    return s;
}

/* toReverseString
 * Purpose: Converts the arraylist of chars into a string, but in reverse order, 
 *      along with the size of the arraylist.
 * Returns: The formatted and reversed string of chars along with the size of the 
 *      arraylist.
 */
std::string CharArrayList::toReverseString() const {
    std::string s;
    s.append("[CharArrayList of size ");
    s.append(to_string(numItems));
    s.append(" <<");
    for (int i = numItems - 1; i > -1; i--) {
        s.append(1, data[i]);
    }
    s.append(">>]");
    return s;
}

/* pushAtBack
 * Purpose: Adds a char to the back of the arraylist
 * Parameters: The char to be added to the arraylist
 */
void CharArrayList::pushAtBack(char c) {
    if (numItems == capacity)
    {
        expand();
        data[numItems] = c;
        numItems++;
    } else {
        data[numItems] = c;
        numItems++;
    }
}

/* pushAtFront
 * Purpose: Adds a char to the front of the arraylist.
 * Parameters: The char to be added to the arraylist
 */
void CharArrayList::pushAtFront(char c) {
    if (numItems == capacity)
    {
        expand();
        for (int i = numItems - 1; i > - 1; i--) {
            data[i + 1] = data[i];
        }
        data[0] = c;
        numItems++;
    } else {
        for (int i = numItems - 1; i > - 1; i--) {
            data[i + 1] = data[i];
        }
        data[0] = c;
        numItems++;
    }
}

/* insertAt
 * Purpose: Adds a char to the arraylist at a given index.
 * Parameters: The char to be added to the arraylist and the index at which
 *      it should be added.
 */
void CharArrayList::insertAt(char c, int index) {
    if (index > numItems || index < 0) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + "]");
    } else {
        if (numItems == capacity) {
            expand();
            for (int i = numItems - 1; i > index - 1; i--) {
                data[i + 1] = data[i];
            }
            data[index] = c;
            numItems++;
        } else {
            for (int i = numItems - 1; i > index - 1; i--) {
                data[i + 1] = data[i];
            }
            data[index] = c;
            numItems++;
        }
    }
}

/* insertInOrder
 * Purpose: Adds a char to the arraylist in its correct position in ASCII order.
 * Parameters: The char to be added to the arraylist.
 */
void CharArrayList::insertInOrder(char c) {
    if (numItems == capacity) {
        expand();
        for (int i = 0; i <= numItems; i++) {
            if (i == numItems) {
                insertAt(c, i);
                break;
            } else if (data[i] >= c) {
                insertAt(c, i);
                break;
            }
        }
    } else {
        for (int i = 0; i <= numItems; i++) {
            if (i == numItems) {
                insertAt(c, i);
                break;
            } else if (data[i] >= c) {
                insertAt(c, i);
                break;
            }
        }
    }
}

/* popFromFront
 * Purpose: Removes the first char from the arraylist
 */
void CharArrayList::popFromFront() {
    if (numItems == 0) {
        throw std::runtime_error("cannot pop from empty ArrayList");
    } else {
        for (int i = 1; i < numItems; i++) {
            data[i - 1] = data[i];
        }
        data[numItems - 1] = 0;
        numItems--;
    }
}

/* popFromBack
 * Purpose: Removes the last char from the arraylist
 */
void CharArrayList::popFromBack() {
    if (numItems == 0) {
        throw std::runtime_error("cannot pop from empty ArrayList");
    } else {
        data[numItems - 1] = 0;
        numItems--;
    }
}

/* removeAt
 * Purpose: Removes the char at a given index.
 * Parameters: The index at which to remove a char.
 */
void CharArrayList::removeAt(int index) {
    if (index >= numItems || index < 0) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")");
    } else {
        for (int i = index + 1; i < numItems; i++) {
            data[i - 1] = data[i];
        }
        data[numItems - 1] = 0;
        numItems--;
    }
}

/* replaceAt
 * Purpose: Replaces the char at the given index with the given char
 * Parameters: A char to put in the arraylist and the index of the
 *      char to replace.
 */
void CharArrayList::replaceAt(char c, int index) {
    if (index >= numItems || index < 0) {
        throw std::range_error("index (" + to_string(index) + ") not in range [0.." + to_string(numItems) + ")");
    } else {
        data[index] = c;
    }
}

/* concatenate
 * Purpose: Adds the contents of a second arraylist to the back of the current 
 *             one.
 * Parameters: An arraylist whose contents should be pushed to the back of
 *             the current arraylist.
 */
void CharArrayList::concatenate(CharArrayList *other) {
    CharArrayList otherCopy(*other);
    if (numItems + otherCopy.numItems > capacity) {
        capacity = capacity + otherCopy.size();
        char *newArray = new char[capacity];
        for (int i = 0; i < numItems; i++) {
            newArray[i] = data[i];
        }
        delete [] data;
        data = newArray;
    }
    for (int i = 0; i < otherCopy.size(); i++) {
        pushAtBack(otherCopy.data[i]);
    }
}

/* expand
 * Purpose: If needed, expands the capacity of the arraylist to meet the needs of whicher function is called.
 */
void CharArrayList::expand() {
    capacity = capacity * 2 + 2;
    char *newArray = new char[capacity];
    for (int i = 0; i < numItems; i++)
    {
        newArray[i] = data[i];
    }
    delete [] data;
    data = newArray;
}
