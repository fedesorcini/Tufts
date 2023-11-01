/*
 *  CharArrayList.h
 *  FEDERICO SORCINI
 *  21 September, 2023
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Header file for CharArrayList Class
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H

#include <string>

class CharArrayList {
    public:

    // Default constructor
    CharArrayList();

    // Single character constructor
    CharArrayList(char c);

    // Character array constructor
    CharArrayList(char arr[], int size);

    // Copy constructor
    CharArrayList(const CharArrayList &other);

    // Destructor
    ~CharArrayList();

    // Assignment operator
    CharArrayList &operator=(const CharArrayList &other);

    // isEmpty
    bool isEmpty() const;

    // clear
    void clear();

    // size
    int size() const;

    // first character
    char first() const;

    // last character
    char last() const;

    // elementAt
    char elementAt(int index) const;

    // toString
    std::string toString() const;

    // toReverseString
    std::string toReverseString() const;

    // pushAtBack
    void pushAtBack(char c);

    // pushAtFront
    void pushAtFront(char c);

    // insertAt
    void insertAt(char c, int index);

    // insertInOrder
    void insertInOrder(char c);

    // popFromFront
    void popFromFront();

    // popFromBack
    void popFromBack();

    // removeAt
    void removeAt(int index);

    // replaceAt
    void replaceAt(char c, int index);

    // concatenate
    void concatenate(CharArrayList *other);
    
    private:

    int numItems;

    int capacity;

    char *data;

    void expand();

};

#endif
