/*
 * unit_tests.cpp
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 *
 * edited by: Milod Kazerounian, January 2022
 *
 * Example unit tests framework to test the CharArrayList class.
 *
 */

#include "CharArrayList.h"
#include <string>
#include <iostream>
#include <cassert>

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */


// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() {
    
        CharArrayList test_list;
        test_list.insertAt('a', 0);
        assert(test_list.size() == 1);
        assert(test_list.elementAt(0) == 'a');
   
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
    // insertAt for out-of-range index
    test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
    // if insertAt is correctly implemented, a range_error will be thrown,
    // and we will end up here
    range_error_thrown = true;
    error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
   
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
   
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
   
}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
   
}

// Tests insertion into front of a larger list
void insertAt_front_large_list() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('y', 0);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<yabcdefgh>>]");
   
}

// Tests insertion into the back of a larger list
void insertAt_back_large_list() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('x', 8);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(8) == 'x');
        assert(test_list.toString() == "[CharArrayList of size 9 <<abcdefghx>>]");
   
}

// Tests insertion into the middle of a larger list
void insertAt_middle_large_list() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<abczdefgh>>]");
   
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
   
}

// Tests basic constructor.
void constructor_test_0() {
    CharArrayList chars;
}

// Tests constructor that takes a single character.
void constructor_test_1() {
    CharArrayList chars('A');
    assert(chars.size() == 1);
    std::cout << "TESTING CONSTRUCTOR 2: " << chars.toString() << std::endl;
}


// Tests constructor that takes a character array and the size of the array.
void constructor_test_2() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    assert(chars.size() == 8);
    std::cout << "TESTING CONSTRUCTOR 3: " << chars.toString() << std::endl;
}

// Tests the pushAtBack function with multiple characters, then prints it to cout using the implemented toString function.
void pushAtBack_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    chars.pushAtBack(' ');
    chars.pushAtBack('S');
    chars.pushAtBack('o');
    chars.pushAtBack('r');
    chars.pushAtBack('c');
    chars.pushAtBack('i');
    chars.pushAtBack('n');
    chars.pushAtBack('i');
    std::cout << "TESTING PUSH AT BACK: " << chars.toString() << std::endl;
}

// Tests the pushAtFront function with multiple characters, then prints it to cout using the implemented toString function.
void pushAtFront_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    chars.pushAtFront(' ');
    chars.pushAtFront(',');
    chars.pushAtFront('i');
    chars.pushAtFront('n');
    chars.pushAtFront('i');
    chars.pushAtFront('c');
    chars.pushAtFront('r');
    chars.pushAtFront('o');
    chars.pushAtFront('S');
    std::cout << "TESTING PUSH AT FRONT: " << chars.toString() << std::endl;
}

// Tests the first function by printing the first character of the arraylist to cout.
void first_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    std::cout << "TESTING FIRST: " << chars.first() << std::endl;
}

// Tests the first function by seeing how it responds to asking for the first character of an empty arralist.
void emptyfirst_test() {
    CharArrayList chars;
    std::cout << "TESTING EMPTY FIRST: " << chars.first() << std::endl;
}

// Tests the last function by printing the first character of the arraylist to cout.
void last_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    std::cout << "TESTING LAST: " << chars.last() << std::endl;
}

// Tests the last function by seeing how it responds to asking for the last character of an empty arralist.
void emptylast_test() {
    CharArrayList chars;
    std::cout << "TESTING EMPTY LAST: " << chars.last() << std::endl;
}

// Tests the elementAt function by printing the indexth character of the arraylist to cout.
void elementAt_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    std::cout << "TESTING ELEMENTAT: " << chars.elementAt(3) << std::endl;
}

// Tests the elementAt function by inputting an index that is out of range.
void OORelementAt_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    std::cout << "TESTING ELEMENTAT OUT OF RANGE: " << chars.elementAt(12) << std::endl;
}

// Tests the isEmpty function by checking whether the empty arraylist is empty and printed the result to cout.
void isEmpty_test() {
    CharArrayList chars;
    assert(chars.isEmpty());
    if (chars.isEmpty()) {
        std::cout << "TESTTING ISEMPTY: EMPTY!" << std::endl;
    } else {
        std::cout << "TESTTING ISEMPTY: NOT EMPTY :(" << std::endl;
    }
}

// Tests the isEmpty function by checking whether the empty arraylist is empty and printed the result to cout.
void fullIsEmpty_test() {
    char charArr [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    CharArrayList chars(charArr, 8);
    if (chars.isEmpty()) {
        std::cout << "TESTTING ISEMPTY: EMPTY!" << std::endl;
    } else {
        std::cout << "TESTTING ISEMPTY: NOT EMPTY :(" << std::endl;
    }
}

// Tests the concatenate function by concatenating one arrayList to another arrayList and printing the original (combined) arrayList to cout.
void concatenate_test() {
    char charArr1 [8] = {'F', 'e', 'd', 'e', 'r', 'i', 'c', 'o'};
    char charArr2 [8] = {' ', 'S', 'o', 'r', 'c', 'i', 'n', 'i'};
    CharArrayList chars1(charArr1, 8);
    CharArrayList chars2(charArr2, 8);
    chars1.concatenate(&chars2);
    std::cout << "TESTING CONCATENATE: " << chars1.toString() << std::endl;
}

void insertInOrder_test() {
    char charArr [8] = {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharArrayList chars(charArr, 8);
    chars.insertInOrder('c');
    std::cout << "TESTING INSERTINORDER: " << chars.toString() << std::endl;
}

void insertInOrderEmpty_test() {
    CharArrayList chars;
    chars.insertInOrder('c');
    std::cout << "TESTING INSERTINORDER EMPTY: " << chars.toString() << std::endl;
}

// Tests assignment operator.
void assignmentOperator_test() {
    char charArr [8] = {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharArrayList chars(charArr, 8);
    CharArrayList chars2 = chars;
    std::cout << "TESTING ASSIGNMENTOPERATOR: " << chars2.toString() << std::endl;
}

// Tests same assignment operator.
void assignmentOperatorSame_test() {
    char charArr [8] = {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i'};
    CharArrayList chars(charArr, 8);
    chars = chars;
    std::cout << "TESTING ASSIGNMENTOPERATOR SAME: " << chars.toString() << std::endl;
}

// Tests empty assignment operator.
void assignmentOperatorEmpty_test() {
    char charArr [8] = {'a', 'b', 'd', 'e', 'f', 'g', 'h', 'i'};
    //char charArr2 [4] = {'S', 'o', 'r', 'c'};
    CharArrayList chars(charArr, 8);
    //CharArrayList chars2(charArr2, 4);
    CharArrayList chars2;
    chars = chars2;
    std::cout << "TESTING ASSIGNMENTOPERATOR EMPTY: " << chars2.toString() << std::endl;
}

int main() {
/*  insertAt_empty_correct();
    insertAt_empty_incorrect();
    insertAt_front_singleton_list();
    insertAt_back_singleton_list();
    insertAt_many_elements();
    insertAt_front_large_list();
    insertAt_back_large_list();
    insertAt_middle_large_list();
    insertAt_nonempty_incorrect();
    constructor_test_0();
    constructor_test_1();
    constructor_test_2();
    pushAtBack_test();
    pushAtFront_test();
    concatenate_test();
    isEmpty_test();
    first_test();
    emptyfirst_test();
    last_test();
    emptylast_test();
    elementAt_test();
    OORelementAt_test();
    fullIsEmpty_test();
    insertInOrder_test();
    insertInOrderEmpty_test(); */
    assignmentOperator_test();
    assignmentOperatorSame_test();
    assignmentOperatorEmpty_test();
    return 0;
}

