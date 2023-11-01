/*
 * BinarySearchTree.cpp
 * CS 15
 * Date: 10/31/23
 * Federico Sorcini
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;


/* Default constructor
 * Purpose: initialize an empty BST
 */
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

/* Destructor
 * Purpose: to destroy the BST using post_order_delete
 */
BinarySearchTree::~BinarySearchTree() {
    // walk tree in post-order traversal and delete
    post_order_delete(root);
    root = nullptr; // not really necessary, since the tree is going
                    // away, but might want to guard against someone
                    // using a pointer after deleting
}

/* post_order_delete
 * Purpose: recursive post-order deletion of the tree
 * Parameters: a node to be recursively deleted
 */
void BinarySearchTree::post_order_delete(Node *node) {
    // cout << "HERE" << endl;
    if (node!= nullptr) {
        post_order_delete(node->left);
        post_order_delete(node->right);
        delete node;
    }
}

/* copy constructor
 * Purpose: to create a deep copy of the BST
 * Parameters: BST to be deep copied
 * Returns: a copy of the BST
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source) {
    // use pre-order traversal to copy the tree
    root = pre_order_copy(source.root);
}

/* assignment overload
 * Purpose: to deep copy a BST into another BST
 * Parameters: BST to be deep copied
 * Returns: a BST that is a deep copy of the source BST
 */
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source) {
    if (&source == this) {
        return *this;
    }
    if (this->root!= nullptr) {
        post_order_delete(this->root);
    }
    root = pre_order_copy(source.root);
    return *this;
}

/* pre_order_copy
 * Purpose: helper function to create a deep copy of the BST
 * Parameters: a node to be recursively copied
 * Returns: a copy of the node
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const {
    if (node == nullptr) {
        return nullptr;
    }
    BinarySearchTree::Node* newNode = new Node;
    newNode->data = node->data;
    newNode->count = node->count;
    newNode->left = pre_order_copy(node->left);
    newNode->right = pre_order_copy(node->right);
    return newNode;
}

/* find_min (public)
 * Purpose: public function to find the minimum value in the tree
 * Returns: the minimum value in the tree
 */
int BinarySearchTree::find_min() const {
    if (root == nullptr) return numeric_limits<int>::max(); // INT_MAX

    return find_min(root)->data;
}

/* find_min (private)
 * Purpose: private helper function to find the minimum value in the tree
 * Parameters: a node to be recursively searched for the minimum value
 * Returns: the node containing the minimum value
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const {
    if (node->left == nullptr) {
        return node;
    } else {
        return find_min(node->left);
    }
}

/* find_max (public)
 * Purpose: public function to find the maximum value in the tree
 * Returns: the maximum value in the tree
 */
int BinarySearchTree::find_max() const {
    if (root == nullptr) return numeric_limits<int>::min(); // INT_MIN

    return find_max(root)->data;
}

/* find_max (private)
 * Purpose: private helper function to find the maximum value in the tree
 * Parameters: a node to be recursively searched for the maximum value
 * Returns: the node containing the maximum value
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const {
    if (node->right == nullptr) {
        return node;
    } else {
        return find_max(node->right);
    }
}

/* contains (public)
 * Purpose: public function to evaluate if a given value is in the tree
 * Parameters: the value to be searched for
 * Returns: true if the value is in the tree, false otherwise
 */
bool BinarySearchTree::contains(int value) const {
    if (root == nullptr) return false;

    return contains(root, value);
}

/* contains (private)
 * Purpose: private helper function to evaluate if a given value is in the tree
 * Parameters: the node to be recursively searched for the value, and the value
 *      to be searched for
 * Returns: true if the value is in the tree, false otherwise
 */
bool BinarySearchTree::contains(Node *node, int value) const {
    if (node == nullptr) {
        return false;
    } else if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return contains(node->left, value);
    } else if (value > node->data) {
        return contains(node->right, value);
    } else {
        return false;
    }
}

/* insert (public)
 * Purpose: public function to insert a value into the tree
 * Parameters: the value to be inserted
 */
void BinarySearchTree::insert(int value) {
    insert(root, nullptr, value);
}

/* insert (private)
 * Purpose: private helper function to insert a value into the tree
 * Parameters: the node to be recursively searched for the insertion point,
 *      the node's parent, and the value to be inserted
 * Other information: if the value is already in the tree, the count for that 
 *      value is incremented by one
 */
void BinarySearchTree::insert(Node *node, Node *parent, int value) {
    if (node != nullptr) {
        if (value == node->data) {
            node->count++;
        } else if (value < node->data) {
            insert(node->left, node, value);
        } else if (value > node->data) {
            insert(node->right, node, value);
        } 
    } else {
        BinarySearchTree::Node* newNode = new Node;
        newNode->data = value;
        newNode->count = 1;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (parent == nullptr) {
            root = newNode;
        } else if (parent->data < value) {
            parent->right = newNode;
        } else if (parent->data > value) {
            parent->left = newNode;
        }
    }
}

/* remove (public)
 * Purpose: to remove a value from the tree
 * Parameters: the value to be removed
 * Returns: true if the value was removed, false otherwise
 */
bool BinarySearchTree::remove(int value) {
    return remove(root, nullptr, value);
}

/* remove (private)
 * Purpose: private helper function to remove a value from the tree
 * Parameters: the node to be recursively searched for the value to be removed,
 *      the node's parent, and the value to be removed
 * Returns: true if the value was removed, false otherwise
 * Other information: if the value is in the tree and its node has a count 
 *      greater than one, the count for that value is reduced by one, otherwise
 *      that node is deleted
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
    if (node == nullptr) {
        return false;
    } else if (value == node->data) {
        if (node->count > 1) {
            node->count--;
            return true;
        } else {
            // Removing node with no children
            if (node->left == nullptr && node->right == nullptr) {
                passChildToParent(node, parent, node->right);
                delete node;
                return true;
            // Removing node with right child
            } else if (node->left == nullptr) {
                passChildToParent(node, parent, node->right);
                delete node;
                return true;
            // Removing node with left child
            } else if (node->right == nullptr) {
                passChildToParent(node, parent, node->left);
                delete node;
                return true;
            } else {
                // Removing node with two children
                Node *replacementNode = find_min(node->right);
                passChildToParent(replacementNode,find_parent(node, replacementNode),replacementNode->right);
                replacementNode->right = node->right;
                replacementNode->left = node->left;
                passChildToParent(node, parent, replacementNode);
                delete node;
                return true;
            }
        }
        return true;
        } else if (value < node->data) {
            return remove(node->left, node, value);
        } else if (value > node->data) {
            return remove(node->right, node, value);
        } else {
            return false;
        }
}

/* pass_child_to_parent
 * Purpose: helper function to pass a node's child to that node's parent
 * Parameters: the node that is leaving, the node's parent, the node's child
 */
void BinarySearchTree::passChildToParent(Node *node, Node *parent, 
    Node *child) {
    if (node == nullptr or parent == nullptr) {
        root = child;
    } else if (parent->left == node) {
        parent->left = child;
    } else if (parent->right == node) {
        parent->right = child;
    }
}

/* tree_height (public)
 * Purpose: returns the height of the tree
 * Returns: the height of the tree
 */
int BinarySearchTree::tree_height() const {
    return tree_height(root);
}

/* tree_height (private)
 * Purpose: private helper function to return the height of the tree
 * Parameters: the node to be recursively searched for the height of the tree
 * Returns: the height of the tree
 */
int BinarySearchTree::tree_height(Node *node) const {
    if (node == nullptr) {
        return -1;
    } else {
        return 1 + max(tree_height(node->left), tree_height(node->right));
    }
}

/* node_count (public)
 * Purpose: returns the total number of nodes in the tree
 * Returns: the total number of nodes in the tree
 */
int BinarySearchTree::node_count() const {
    return node_count(root);
}

/* node_count (private)
 * Purpose: private helper function to return the total number of nodes in 
 *      the tree
 * Parameters: the node to be recursively searched for the total number of 
 *      nodes in the tree
 * Returns: the total number of nodes in the tree
 */
int BinarySearchTree::node_count(Node *node) const {
    if (node == nullptr) {
        return 0;
    } else {
        return 1 + node_count(node->left) + node_count(node->right);
    }
}

/* count_total (public)
 * Purpose: returns the sum of all the node values (including duplicates) 
 * Returns: the sum of all the node values (including duplicates) 
 */
int BinarySearchTree::count_total() const {
    return count_total(root);
}

/* count_total (private)
 * Purpose: private helper function to return the sum of all the node values 
 *      (including duplicates)
 * Parameters: the node to be recursively searched for the sum of all the 
 *      nodes in the tree
 * Returns: the sum of all the node values (including duplicates)
 */
int BinarySearchTree::count_total(Node *node) const {
    if (node == nullptr) {
        return 0;
    } else {
        return (node->data * node->count) + count_total(node->left) + count_total(node->right);
    }
}

/* find_parent
 * Purpose: to find the parent node of a given node
 * Parameters: the node to be searched for the given node, and the given node
 * Returns: the parent node of the given node
 */
BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const {
    if (node == nullptr) return nullptr;

    // if either the left or right is equal to the child,
    // we have found the parent
    if (node->left == child or node->right == child) { return node; }

    // Use the binary search tree invariant to walk the tree
    if (child->data > node->data) {
        return find_parent(node->right, child);
    } else {
        return find_parent(node->left, child);
    }
}

/* print_tree (public)
 * Purpose: prints the tree in a pretty way
 */
void BinarySearchTree::print_tree() const {
    size_t      numLayers  = tree_height() + 1;
    size_t      levelWidth = 4;
    const char *rootPrefix = "-> ";

    // Need numLayers * levelWidth characters for each layer of tree.
    // Add an extra levelWidth characters at front to avoid if statement
    // 1 extra char for nul character at end
    char *start = new char[(numLayers + 1) * levelWidth + 1];

    print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
    delete[] start;
}

/* 
 * Purpose: print_tree (private)
 * Parameters: multiple values that help print the tree
 */
// Logic and Output Reference:
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const {
    if (node == nullptr) return;

    // 4 characters + 1 for nul terminator
    using TreeLevel                    = char[5];
    static const int       levelLength = sizeof(TreeLevel) - 1;
    static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                           CONNECT = "   |";
    // Copies prev into dest and advances dest by strlen(prev)
    auto set = [](char *dest, const char *prev) {
        size_t p = strlen(prev);
        return (char *)memcpy(dest, prev, p) + p;
    };

    print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

    // Clear any characters that would immediate precede the "branch"
    // Don't need to check for root (i.e start of array),fullLine is padded
    set(currPos - levelLength, EMPTY);

    // Terminate fullLine at current level
    *currPos = '\0';

    std::cerr << fullLine << branch << node->data
              << (node->count > 1 ? "*" : "") << endl;

    // Connect upper branch to parent
    if (branch == UP) set(currPos - levelLength, CONNECT);

    // Connect lower branch to parent
    print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}




