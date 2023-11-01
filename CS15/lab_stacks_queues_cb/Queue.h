/*
 *      Queue.h
 *      PartyPlaylist
 *      Comp 15 Lab 3
 *
 *      A class that represents a queue of elements.
 *      The type ElementType is presumed to be defined before this
 *      file is included.
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "CircularBuffer.h"
#include <string>

template<typename ElementType>
class Queue {
public:
    Queue() {}
    Queue(int initialCapacity) : queue(initialCapacity) {}
    ~Queue() {}

    ElementType dequeue() {
        queue.removeFromFront();
    }

    void enqueue(ElementType element) {
        queue.addAtBack(element);
    }

private:
    CircularBuffer<ElementType> queue;
};

#endif
