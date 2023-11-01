/*
 * CharLinkedList.h
 *  Federico Sorcini
 *  9/30/23
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  FILE PURPOSE HERE
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <string>
#include <iostream>

class CharLinkedList {
    
    public:

    // constructors
        CharLinkedList();
        // start with a single character
        CharLinkedList(char c); 
        // start with a list of characters
        CharLinkedList(char arr[], int size); 
        // start with another CharLinkedList
        CharLinkedList(const CharLinkedList &other); 
        // destructor
        ~CharLinkedList();
        // assignment operator overload
        CharLinkedList &operator=(const CharLinkedList &other);


        // CharLinkedList functions
        // get information about the list -- these won't modify the list
        bool isEmpty() const;
        int  size() const;
        char first() const;
        char last() const;
        char elementAt(int index) const;

        // insert into the list
        void pushAtBack(char c);
        void pushAtFront(char c);
        void insertAt(char c, int index);
        void insertInOrder(char c);

        // print the list
        std::string toString() const;
        std::string toReverseString() const;

        // remove from the list
        void clear();
        void popFromFront();
        void popFromBack();
        void removeAt(int index);

        // other ways to edit the list
        void replaceAt(char c, int index);
        void concatenate(const CharLinkedList *other);

    private:
    struct Node {
        char data;
        Node *next;
        Node *prev;
    };

    Node *front;
    Node *back;
    int numItems;
    
    void recycleList(Node *node) {
        if (node != nullptr) {
            recycleList(node->next);
            delete node;
        }
    }
    
    char elementAtHelper(Node *node, int index, int& i) const {
        if (i == index) {
            return node->data;
        } else {
            ++i;
            return elementAtHelper(node->next, index, i);
        }
    }
    
    void replaceAtHelper(Node *node, char c, int index, int& i) {
        if (i == index) {
            node->data = c;
        } else {
            i++;
            replaceAtHelper(node->next, c, index, i);
        }
    }
};

#endif
