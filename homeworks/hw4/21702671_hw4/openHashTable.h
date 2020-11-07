/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 4
* Description : This is a hash table class using open
*               addressing with quadratic probing.
*/

//template<class T1, class T2> struct pair;

/*no more than 50 entries at the same time in the table*/
const int MAX_TABLE_SIZE = 53;

#include <string>
#include <array>
#include "FoodItem.h"

using namespace std;

#ifndef _OPEN_HASH
#define _OPEN_HASH
class OpenHashTable {

public:
    OpenHashTable() {
        arr = new FoodItem[MAX_TABLE_SIZE];
        deleted = new bool[MAX_TABLE_SIZE];
        occupied = new bool[MAX_TABLE_SIZE];
        for (int i = 0; i < MAX_TABLE_SIZE; i++) {
            deleted[i] = false;
            occupied[i] = false;
            //arr[i] = NULL;
        }
        size = 0;
    }
    /*The destructor to destory pointer stuff.*/
    ~OpenHashTable() {
        delete [] arr;
        delete [] deleted;

    } //should i implement the destructor myself?

    void addItem(string itemName, int amount);
    void deleteItem(string itemName);
    void findItem(string itemName); //adini ve countu print et
    void printTable();

    bool isDeleted(int index) {return deleted[index];}
    bool isOccupied(int index) {return occupied[index];}
    int getNumberOfItems() {return size;}

private:
    FoodItem* arr;
    bool* deleted;
    bool *occupied;
    int size; //current no of elements

    int hashFunction(string &itemName);


};
#endif