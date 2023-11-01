/*
 *  unit_tests.cpp
 *  Federico Sorcini
 *  9/30/23
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  FILE PURPOSE HERE
 *
 */

#include "CharLinkedList.h"
#include <string>
#include <iostream>
#include <cassert>


/* 
 * Tests: 
 * Conditions: 
 */


/* 
 * Tests: Basic constructor
 */
void constructor_1_test() {
    CharLinkedList chars;
    std::cout << "TESTING CONSTRUCTOR 1: " << chars.toString() << std::endl;

}

/* 
 * Tests: constructor with a character
 */
void constructor_2_test() {
    CharLinkedList chars('a');
    std::cout << "TESTING CONSTRUCTOR 2: " << chars.toString() << std::endl;
}

/* 
 * Tests: constructor with an array of characters and number of characters
 */
void constructor_3_and_pushAtBack_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "TESTING CONSTRUCTOR 3: " << chars.toString() << std::endl;
}

/* 
 * Tests: the copy constroctor
 */
void copy_constructor_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "TO COPY: " << chars.toString() << std::endl;
    CharLinkedList chars2(chars);
    std::cout << "COPY: " << chars2.toString() << std::endl;
}

/* 
 * Tests: the assignment operator
 */
void assignmemt_operator_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "CHARS 1: " << chars.toString() << std::endl;
    char charArr2 [9] = {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'};
    CharLinkedList chars2(charArr2, 9);
    std::cout << "CHARS 2 before assignment: " << chars2.toString() << std::endl;
    chars2 = chars;
    std::cout << "CHARS 2 after assignment: " << chars2.toString() << std::endl;
}

/* 
 * Tests: whether an empty list is actually empty
 */
void isEmpty_test_TRUE() {
    CharLinkedList chars;
    std::cout << "EXPECT TRUE: " << chars.isEmpty() << std::endl;   
}

/* 
 * Tests: whether a non-empty list is empty
 */
void isEmpty_test_FALSE() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "EXPECT FALSE: " << chars.isEmpty() << std::endl;
}

/* 
 * Tests: the first function, and whether it returns 'a'
 */
void first_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "FIRST: " << chars.first() << std::endl;
}

/* 
 * Tests: the last function, and whether it returns 'i'
 */
void last_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "LAST: " << chars.last() << std::endl;
}

/* 
 * Tests: the elementAt function, and whether it returns e'
 */
void elementAt_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "EXPECT 'e': " << chars.elementAt(4) << std::endl;
}

/* 
 * Tests: the elementAt function using an index that is outside (higher) 
 *     of the range of the list, and whether sends an error message
 */
void elementAtOutOfRangeAbove_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    try {
        chars.elementAt(13);
    }
    catch (const std::range_error &e) {
        std::cout << "EXPECT Range error 13: " << e.what() << std::endl;
    }
}

/* 
 * Tests: the elementAt function using an index that is outside (lower) 
 *     of the range of the list, and whether sends an error message
 */
void elementAtOutOfRangeBelow_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    try {
        chars.elementAt(-5);
    }
    catch (const std::range_error &e) {
        std::cout << "EXPECT Range error -5: " << e.what() << std::endl;
    }
}

/* 
 * Tests: the elementAt function using an index in the middle of the list
 */
void elementAtMiddle_test() {
    char charArr [8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    CharLinkedList chars(charArr, 8);
    std::cout << "EXPECT 'e': " << chars.elementAt((chars.size())/2) << std::endl;
}

/* 
 * Tests: the reverseString function
 */
void toReverseString_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "TESTING REVERSE STRING: " << chars.toReverseString() << std::endl;
}

/* 
 * Tests: the clear function and whether it returns an empty list
 */
void clear_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "BEFORE CLEAR: " << chars.toString() << std::endl;
    chars.clear();
    std::cout << "AFTER CLEAR: " << chars.toString() << std::endl;
}

/* 
 * Tests: the popFromFront function and whether it returns a list without
 *    the first element
 */
void popFromFront_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "BEFORE POP FROM FRONT: " << chars.toString() << std::endl;
    chars.popFromFront();
    std::cout << "AFTER POP FROM FRONT: " << chars.toString() << std::endl;
}

/* 
 * Tests: the popFromBack function and whether it returns a list without
 *    the last element
 */
void popFromBack_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "BEFORE POP FROM BACK: " << chars.toString() << std::endl;
    chars.popFromBack();
    std::cout << "AFTER POP FROM BACK: " << chars.toString() << std::endl;
}

/* 
 * Tests: the removeAt function and whether it returns a list without
 *    the element at the given index
 */
void removeAt_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "BEFORE REMOVE AT 4: " << chars.toString() << std::endl;
    chars.removeAt(4);
    std::cout << "AFTER REMOVE AT 4: " << chars.toString() << std::endl;
}

/* 
 * Tests: the removeAt function using an index that is out of range 
 *     of the list
 */
void removeAtOOR_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    try {
        chars.removeAt(14);
    }
    catch (const std::range_error &e) {
        std::cout << "EXPECT Range error 14: " << e.what() << std::endl;
    }
}

/* 
 * Tests: the replaceAt function and whether it returns a list with the 
 *     replacement char at the given index
 */
void replaceAt_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "BEFORE REPLACE e AT 4 with E at 4: " << chars.toString() << std::endl;
    chars.replaceAt('E', 4);
    std::cout << "AFTER REPLACE e AT 4 with E at 4: " << chars.toString() << std::endl;
}

/* 
 * Tests: the concatenate function and whether it returns a list with the 
 *     added copy of another list to the back
 */
void concatenate_test() {
    char charArr [9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 9);
    std::cout << "CHARS 1: " << chars.toString() << std::endl;
    char charArr2 [8] = {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'};
    CharLinkedList chars2(charArr2, 8);
    std::cout << "CHARS 2: " << chars2.toString() << std::endl;
    chars.concatenate(&chars2);
    std::cout << "CHARS 1 AND 2 COMBINED: " << chars.toString() << std::endl;
}

/* 
 * Tests: the insertAt function and whether it returns a list with the 
 *     given char at the given index
 */
void insertAt_test() {
    char charArr [8] = {'a', 'b', 'c', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 8);
    std::cout << "BEFORE INSERT 'd' AT 8: " << chars.toString() << std::endl;
    chars.insertAt('d', 8);
    std::cout << "AFTER INSERT 'd' AT 8: " << chars.toString() << std::endl;
}

/* 
 * Tests: the insertInOrder function and whether it returns a list with the 
 *     given char in ASCII order
 */
void insertInOrder_test() {
    char charArr [8] = {'a', 'b', 'c', 'e', 'f', 'g', 'h', 'i'};
    CharLinkedList chars(charArr, 8);
    std::cout << "BEFORE INSERT 'd': " << chars.toString() << std::endl;
    chars.insertInOrder('z');
    std::cout << "AFTER INSERT 'd': " << chars.toString() << std::endl;
}


int main() {
    constructor_1_test();
    constructor_2_test();
    constructor_3_and_pushAtBack_test();
    copy_constructor_test();
    assignmemt_operator_test();
    isEmpty_test_TRUE();
    isEmpty_test_FALSE();
    first_test();
    last_test();
    elementAt_test();
    elementAtOutOfRangeAbove_test();
    elementAtOutOfRangeBelow_test();
    elementAtMiddle_test();
    toReverseString_test();
    clear_test();
    popFromFront_test();
    popFromBack_test();
    removeAt_test();
    removeAtOOR_test();
    replaceAt_test();
    concatenate_test();
    insertAt_test();
    insertInOrder_test();

    return 0;
}
