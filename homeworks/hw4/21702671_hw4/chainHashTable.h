/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 4
* Description : This is a hash table class using seperate
*               chaining.
*/

/*no more than 50 entries at the same time in the table*/
const int MAX_TABLE_SIZE = 53;

#include <string>
#include <array>
#include "FoodItemNode.h"

using namespace std;

#ifndef _CHAIN_HASH
#define _CHAIN_HASH
class ChainHashTable {

public:
    ChainHashTable() {
        arr = new FoodItemNode*[MAX_TABLE_SIZE];
        size = 0;
    }
    ~ChainHashTable() {
        for (int i = 0; i < size; i++) delete arr[i];
        delete [] arr;
    }

    int hashFunction(string &itemName);
    void addItem(string itemName, int amount);
    void deleteItem(string itemName);
    void printTable();

private:
    FoodItemNode** arr; //table that keeps the foods
    int size; //current size

};
#endif