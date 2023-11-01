/*
 * unit_tests.h
 * Matt Russell && Matt Champlin
 * 1/6/2021
 * This file demonstrates unit tests for an ArrayList class
 *
 * Background info for tests:
 *     For our purposes, if a test finishes execution, it is considered 
 *     successful.
 *     Use assert(boolean_expression) to test for known conditions.
 *     If the expression evaluates to false, then the assertion fails.
 *
 *
 * Workflow encouragements:
 *     You are encouraged to write MANY, MANY tests!!!
 *     Furthermore, you are encouraged to write and run tests as you work.
 *     So, the workflow should be something along the lines of:
 *            1) Write a function (or part of a function)
 *            2) Write at least 1 test for the code you just wrote
 *            3) Run the tests, and fix all errors (including memory issues)
 *            4) Rinse and Repeat!
 *    *** It is wise to debug BEFORE moving on to writing the next function. ***
 *
 * NB: The ArrayList code provided has bugs, so (some) tests will fail 
 * first on purpose!
 * Be sure to ask questions!!
 */

#include "ArrayList.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

/*
 * constructor test 0
 * Make sure no fatal errors/memory leaks in the default constructor
 */
void constructor_test_0() {
    ArrayList list;
}

/*
 * constructor test 1
 * Make sure no items exist in the list upon construction
 * Note: given the provided code, this test should fail. Fix it!
 */
void constructor_test_1() {
    ArrayList list; // One way to invoke the default constructor.
    cout << list.toString() << endl;
    // assert(list.size() == 0);
}


/*
 * 
 *
 * isEmpty test
 * Make sure we report an empty list correctly.
 */
void isEmpty_test() {
     ArrayList list;
     assert(list.isEmpty());
     if (list.isEmpty()) {
        cout << "isEmpty_test result: Passed!" << endl;
     } else {
        cout << "isEmpty_test result: Failed :(" << endl;
     }
}


/*
 * toString_test_0
 * Checks that the given list is as we expect it to be
 * Note: You might want to create a simpler test which doesn't push any
 *       elements back before asserting the result of list.toString().
 *       In some sense, this test will inevitably have to work in tandem
 *       with the pushAtBack test below.
 */

void toString_test_0() {
    ArrayList list;
    list.pushAtBack(1);
    list.pushAtBack(2);
    list.pushAtBack(3);
    assert(list.toString() == "[1,2,3]");
    if (list.toString() == "[1,2,3]") {
        cout << "toString_test_0 result: Passed!" << endl;
    } else {
        cout << "toString_test_0 result: Failed :(" << endl;
    }
}

/*
 * 
 * Print the list to cout and make sure num_items is correctly updated.
 * Note: Uncomment the function header below when you are ready.
 */
void pushAtBack_test() {
    ArrayList list;
    list.pushAtBack(1);
    assert(list.size() == 1);
    cout << "pushAtBack_test result: " << list.toString() << endl;
}

/*
 * Make sure num_items is correctly updated and print the inserted numbers to
 * cout.
 * Note: Uncomment the function header below when you are ready.
 */
void expand_test() {
    ArrayList list;
    list.pushAtBack(1);
    list.pushAtBack(2);
    list.pushAtBack(3);
    list.pushAtBack(4);
    list.pushAtBack(5);
    list.pushAtBack(6);
    assert(list.size() == 6);
    cout << "expand_test result: " << list.toString() << endl;   
}


/********************** JFFE (Just For Fun) Excersises ***********************/

/*
 * integer is in the ArrayList.
 * Note: you must create the function declaration yourself!
 *
 * find_returns_true test
 * Make sure find returns true when an integer is present in the ArrayList
 */
void find_returns_true_test() {
    ArrayList list;
    list.pushAtBack(1);
    list.pushAtBack(2);
    list.pushAtBack(3);
    list.pushAtBack(4);
    list.pushAtBack(5);
    list.pushAtBack(6);
    assert(list.find(3));
    if (list.find(3)) {
        cout << "find_returns_true_test result: Found!" << endl;
    } else {
        cout << "find_returns_true_test result: Didn't find :(" << endl;
    }
}

/*
 * integer is NOT in the ArrayList.
 * Note: you must create the function declaration yourself!
 *
 * find_returns_false test
 * Make sure find returns false when an integer is NOT present in the ArrayList
 */
void find_returns_false_test() {
    ArrayList list;
    list.pushAtBack(1);
    list.pushAtBack(2);
    list.pushAtBack(3);
    list.pushAtBack(4);
    list.pushAtBack(5);
    list.pushAtBack(6);
    assert(not list.find(12));
    if (not list.find(12)) {
        cout << "find_returns_false_test result: Didn't find!" << endl;
    } else {
        cout << "find_returns_false_test result: Found :(" << endl;
    }
}

/*
 * removes it. Print the empty list to verify it has in fact been removed.
 * Make sure num_items is correctly updated.
 * Note: Uncomment the function header below when you are ready.
 */
void popFromBack_test() {
    ArrayList list;
    list.pushAtBack(1);
    list.pushAtBack(2);
    list.pushAtBack(3);
    list.pushAtBack(4);
    list.pushAtBack(5);
    list.pushAtBack(6);
    list.pushAtBack(7);
    list.pushAtBack(8);
    list.popFromBack();
    assert(list.toString() == "[1,2,3,4,5,6,7]");
}


/* Write any other tests you can think of below! */


int main() {
    
        constructor_test_0();
        constructor_test_1();
        isEmpty_test();
        toString_test_0();
        pushAtBack_test();
        expand_test();
        popFromBack_test();
        find_returns_true_test();
        find_returns_false_test();
   
    return 0;
}