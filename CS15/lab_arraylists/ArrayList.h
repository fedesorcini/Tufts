/*
 * ArrayList.h
 * Matt Russell && Matt Champlin
 * COMP15 lab 1
 * 1/6/2021
 *
 * This is a class declaration for an ArrayList for lab0.
 *
 * 
 */
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <string>

class ArrayList {
public:

    ArrayList();
    ~ArrayList();

    void pushAtBack(int elem);

    bool        isEmpty() const;
    int         size() const;
    std::string toString() const;

    // JFFE! Write a find function that returns true if a given integer is
    // in the ArrayList, and false if not.
    bool find(int to_find) const;

    // JFFE! Write a popFromBack function that removes the last element of
    // the ArrayList.
    void popFromBack();

private:
    int numItems;
    int capacity;


    int *data;

    // helper function for changing the capacity of the ArrayList
    void expand();
};

#endif
