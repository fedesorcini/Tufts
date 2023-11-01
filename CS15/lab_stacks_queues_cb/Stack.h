/*
 *      Stack.h
 *      PartyPlaylist
 *      Comp 15 Lab 3
 *
 *      A class that represents a stack of elements.
 *      The type ElementType is presumed to be defined before this
 *      file is included.
 */
#ifndef STACK_H
#define STACK_H

#include "CircularBuffer.h"

template<typename ElementType>
class Stack {
public:
    Stack() {}
    Stack(int capacity) : stack(capacity) {}
    ~Stack() {}

    ElementType pop() {
        return stack.removeFromBack();
    }

    void push(ElementType element) {
        stack.addAtBack(element);
    }

private:
    CircularBuffer<ElementType> stack;
};

#endif
