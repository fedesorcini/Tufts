/*
 * FunkeyTable.cpp --- compare two different methods of handling hash
 * table collisions and two different hash functions.
 *
 * your job:  code the insert functions and expand function
 *  our job:  run the insert functions and report results
 *
 * Based on a previous lab by Ben Hescott, I think.
 *
 * Mark A. Sheldon, Tufts University, Spring 2017
 */

#include <iostream>
#include <stdio.h>
#include <functional>

#include "FunkeyTable.h"

using namespace std;

/*
 * Constructor allocates and initializes two empty tables
 * of the INITIAL_TABLE_SIZE
 */
FunkeyTable::FunkeyTable()
{
        currentTableSize = INITIAL_TABLE_SIZE;
        numItemsInTable = 0;
        chainedTable = new ChainNode *[currentTableSize];
        linearTable = new TableEntry[currentTableSize];
        for (int i = 0; i < currentTableSize; i++)
        {
                chainedTable[i] = nullptr;
                linearTable[i].isEmpty = true;
        }
}

/*
 * Delete all nodes in list starting with given node
 */
void FunkeyTable::deleteList(ChainNode *node)
{
        while (node!= nullptr)
        {
                ChainNode *next = node->next;
                delete node;
                node = next;
        }
}

/*
 * destructor
 */
FunkeyTable::~FunkeyTable()
{
        for (int i = 0; i < currentTableSize; i++) {
                deleteList(chainedTable[i]);
        }
        delete[] chainedTable;
        delete[] linearTable;
}

static size_t good_hash_function(KeyType key)
{
        return std::hash<KeyType>{}(key);
}

static size_t bad_hash_function(KeyType key)
{
        return key.length();
}

static size_t hashValue(KeyType key, FunkeyTable::HashFunction hashFunction)
{
        if (hashFunction == FunkeyTable::BAD_HASH_FUNCTION)
                return bad_hash_function(key);
        else
                return good_hash_function(key);
}

/*
 * Linear Probing
 *
 * Return number of collisions before finding a spot
 *
 */
int FunkeyTable::insertProbing(KeyType key, ValueType value,
                               HashFunction hashFunction)
{
        int attempt = 0;
        bool found = false;
        size_t index = hashValue(key, hashFunction) % currentTableSize;
        while (not found)
        {
                if (linearTable[index].isEmpty) {
                linearTable[index].key = key;
                linearTable[index].value = value;
                linearTable[index].isEmpty = false;
                found = true;
                } else {
                        index = (index + 1) % currentTableSize;
                }
                ++attempt;
        }
        return attempt;
}

/*
 * Return length of list starting at given node
 */
int FunkeyTable::listLength(ChainNode *nodep)
{
        int length = 0;
        while (nodep != nullptr) {
                ++length;
                nodep = nodep->next;
        }
        return length;
}

/*
 * Chained hashing --- each spot in table is a linked list
 *
 * Return number of items in that spot before insertion
 */
int FunkeyTable::insertChaining(KeyType key, ValueType value,
                                HashFunction hashFunction)
{
        size_t index = hashValue(key, hashFunction) % currentTableSize;
        ChainNode *newNode = new ChainNode;
        newNode->key = key;
        newNode->value = value;
        newNode->next = chainedTable[index];
        chainedTable[index] = newNode;
        return listLength(chainedTable[index]);
}

/*
 * Expand both of the hash tables
 */
void FunkeyTable::expand(HashFunction hashFunction)
{
        int newTableSize = currentTableSize * 2;
        ChainNode **newChainedTable = new ChainNode *[newTableSize];
        TableEntry *newLinearTable = new TableEntry[newTableSize];
        for (int i = 0; i < newTableSize; i++)
        {
                newChainedTable[i] = nullptr;
                newLinearTable[i].isEmpty = true;
        }
        for (int i = 0; i < currentTableSize; i++)
        {
                ChainNode *curr = chainedTable[i];
                while (curr != nullptr)
                {
                size_t index = hashValue(curr->key, hashFunction) % newTableSize;
                ChainNode *temp = curr->next;
                curr->next = newChainedTable[index];
                newChainedTable[index] = curr;
                curr = temp;
                }

                if (!linearTable[i].isEmpty)
                {
                size_t index = hashValue(linearTable[i].key, hashFunction) % newTableSize;
                newLinearTable[index] = linearTable[i];
                }
        }
        delete[] chainedTable;
        delete[] linearTable;
        currentTableSize = newTableSize;
        chainedTable = newChainedTable;
        linearTable = newLinearTable;
}

void FunkeyTable::printTableEntry(TableEntry entry)
{
        if (entry.isEmpty)
                cout << "empty";
        else
                cout << "key:  "
                     << entry.key
                     << "; value:  {"
                     << entry.value.chartPosition
                     << ", "
                     << entry.value.bpm
                     << "}";
}

void FunkeyTable::printChainNode(ChainNode *nodep)
{
        cout << "key:  " << nodep->key
             << "; value:  {" << nodep->value.chartPosition
             << ", " << nodep->value.bpm << "}";
}

/*
 * Print both hash tables
 * Could break this up into two print functions
 */
void FunkeyTable::print()
{
        cout << "Linear table" << endl;
        for (int i = 0; i < currentTableSize; ++i)
        {
                cout << i << ":  ";
                printTableEntry(linearTable[i]);
                cout << endl;
        }
        cout << endl
             << "Chained table" << endl;

        for (int i = 0; i < currentTableSize; ++i)
        {
                ChainNode *curr = chainedTable[i];
                cout << i << ":  [ ";
                while (curr != NULL)
                {
                        printChainNode(curr);
                        curr = curr->next;
                        if (curr != NULL)
                                cout << ", ";
                }
                cout << "]" << endl;
        }
        cout << endl;
}
