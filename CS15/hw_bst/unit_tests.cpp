/*
 * unit_tests.cpp
 * CS 15
 * Date: 10/31/23
 * Federico Sorcini
 *
 * Implementation of the unit tests used for testing the program.
 * 
 */

#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <cassert>

/********************************************************************\
*                       BST TESTS                        *
\********************************************************************/

using namespace std;

void print_tree_details(BinarySearchTree &bst) {
    
    bst.print_tree();
    cout << "\n";
    cout << "min: " << bst.find_min() << "\n";
    cout << "max: " << bst.find_max() << "\n";
    cout << "nodes: " << bst.node_count() << "\n";
    cout << "count total: " << bst.count_total() << "\n";
    cout << "tree height: " << bst.tree_height() << "\n";
    cout << "\n";
}


/*                      Condition: Base Cases                       *\
\********************************************************************/

void base_insert() {
    
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    assert(bst.node_count() == 2);
    assert(bst.find_min() == 1);
    assert(bst.find_max() == 2);
    assert(bst.count_total() == 3);
    assert(bst.tree_height() == 1);
}

void base_remove() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    assert(bst.node_count() == 2);
    assert(bst.find_min() == 1);
    assert(bst.find_max() == 2);
    assert(bst.count_total() == 3);
    assert(bst.tree_height() == 1);
    bst.remove(1);
    assert(bst.node_count() == 1);
    assert(bst.find_min() == 2);
    assert(bst.find_max() == 2);
    assert(bst.count_total() == 2);
    assert(bst.tree_height() == 0);
}

void base_contains() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    assert(bst.contains(1));
    assert(bst.contains(2));
    bst.remove(1);
    assert(!bst.contains(1));
    assert(bst.contains(2));
}

/*                      Condition: Repeated Inputs                  *\
\********************************************************************/

void repeated_insert() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(2);
    assert(bst.node_count() == 3);
    assert(bst.find_min() == 1);
    assert(bst.find_max() == 3);
    assert(bst.count_total() == 8);
    assert(bst.tree_height() == 2);

}

void repeated_remove() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(2);
    bst.remove(2);
    assert(bst.count_total() == 6);
}

void repeated_remove2() {
    BinarySearchTree bst;
    bst.insert(2);
    bst.insert(15);
    bst.insert(2);
    bst.insert(3);
    bst.insert(12);
    bst.insert(23);
    bst.insert(3964);
    bst.insert(15);
    bst.insert(15);
    bst.insert(15);
    bst.insert(15);
    bst.insert(15);
    bst.insert(15);
    bst.insert(15);
    bst.insert(15);
    assert(bst.count_total() == 4141);
    bst.remove(15);
    assert(bst.count_total() == 4126);
    assert(bst.node_count() == 6);
    bst.remove(2);
    bst.remove(2);
    assert(bst.node_count() == 5);
}

/*                      Condition: Nonexistant Value                *\
\********************************************************************/

void nonexistant_remove() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(2);
    bst.remove(4);
    assert(bst.count_total() == 8);
}

void nonexistant_contains() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(2);
    assert(!bst.contains(4));
}

/*                      Condition: Edge Cases                       *\
\********************************************************************/

// Tests remove node with zero children
void no_children_remove() {
    BinarySearchTree bst;
    bst.insert(1);
    bst.insert(2);
    assert(bst.contains(1));
    bst.remove(2);
    assert(!bst.contains(2));
}

// Tests remove node with one child
void one_child_remove() {
    BinarySearchTree bst;
    bst.insert(12);
    bst.insert(4);
    bst.insert(81);
    bst.insert(46);
    bst.insert(66);
    bst.insert(85);
    bst.remove(46);
    assert(not bst.contains(46));
}

// Tests remove node with two children
void two_children_remove() {
    BinarySearchTree bst;
    bst.insert(12);
    bst.insert(4);
    bst.insert(81);
    bst.insert(46);
    bst.insert(66);
    bst.insert(85);
    bst.remove(81);
    assert(not bst.contains(81));
}

// Tests remove node with two children, replace with node that has zero children
void two_children_leaf_replacement() {
    BinarySearchTree bst;
    bst.insert(12);
    bst.insert(4);
    bst.insert(46);
    bst.insert(34);
    bst.insert(66);
    bst.insert(51);
    bst.insert(85);
    print_tree_details(bst);
    cout << "Removing 46 from original tree:\n";
    bst.remove(46);
    assert(not bst.contains(46));
    // Visual check
    print_tree_details(bst);
}

// Tests remove node with two children, replace with node that has one child
void two_children_replacement_with_child() {
    BinarySearchTree bst;
    bst.insert(12);
    bst.insert(4);
    bst.insert(46);
    bst.insert(34);
    bst.insert(66);
    bst.insert(51);
    bst.insert(85);
    bst.insert(54);
    print_tree_details(bst);
    cout << "Removing 46 from original tree:\n";
    bst.remove(46);
    assert(not bst.contains(46));
    // Visual check
    print_tree_details(bst);
}


/*                      Condition: Empty Tree                       *\
\********************************************************************/

// Tests insert
void emptyTree_insert() {
    BinarySearchTree bst;
    bst.insert(10);
    assert(bst.find_min() == 10);
    assert(bst.find_max() == 10);
    assert(bst.node_count() == 1);
    assert(bst.count_total() == 10);
    assert(bst.tree_height() == 0);
}

// Tests contains
void emptyTree_contains() {
    BinarySearchTree bst;
    assert(bst.contains(10) == false);
}

// Tests remove 
void emptyTree_remove() {
    BinarySearchTree bst;
    bst.remove(10);
    assert(bst.node_count() == 0);
    assert(bst.count_total() == 0);
    assert(bst.tree_height() == -1);
}

// Tests copy constructor
void emptyTree_copyConstructor() {
    BinarySearchTree bst;
    BinarySearchTree bst2(bst);
    assert(bst2.node_count() == 0);
    assert(bst2.count_total() == 0);
    assert(bst2.tree_height() == -1);
}

// Tests assignment operator
void emptyTree_assignmentOperator() {
    BinarySearchTree bst;
    BinarySearchTree bst2;
    bst2 = bst;
    assert(bst2.node_count() == 0);
    assert(bst2.count_total() == 0);
    assert(bst2.tree_height() == -1);
}

int main() {
    cout << "Testing base_insert... " << endl;
    base_insert();
    cout << "Testing base_remove... " << endl;
    base_remove();
    cout << "Testing base_contains... " << endl;
    base_contains();
    cout << "Testing repeated_insert... " << endl;
    repeated_insert();
    cout << "Testing repeated_remove... " << endl;
    repeated_remove();
    cout << "Testing repeated_remove2... " << endl;
    repeated_remove2();
    cout << "Testing nonexistant_remove... " << endl;
    nonexistant_remove();
    cout << "Testing nonexistant_contains... " << endl;
    nonexistant_contains();
    cout << "Testing no_children_remove... " << endl;
    no_children_remove();
    cout << "Testing one_child_remove... " << endl;
    one_child_remove();
    cout << "Testing two_children_remove... " << endl;
    two_children_remove();
    cout << "Testing two_children_leaf_replacement... " << endl;
    two_children_leaf_replacement();
    cout << "Testing two_children_replacement_with_child... " << endl;
    two_children_replacement_with_child();
    cout << "Testing emptyTree_insert... " << endl;
    emptyTree_insert();
    cout << "Testing emptyTree_contains... " << endl;
    emptyTree_contains();
    cout << "Testing emptyTree_remove... " << endl;
    emptyTree_remove();
    cout << "Testing emptyTree_copyConstructor... " << endl;
    emptyTree_copyConstructor();
    cout << "Testing emptyTree_assignmentOperator... " << endl;
    emptyTree_assignmentOperator();
    
    return 0;
}
