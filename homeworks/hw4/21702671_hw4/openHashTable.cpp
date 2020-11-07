/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 4
* Description : Hash table implementation using open
*               addressing with quadratic probing.
*/

#include "FoodItem.h"
#include "openHashTable.h"
#include <iostream>
#include <string>

using namespace std;

/* Hash the given food item to an index in which
*  the item is supposed to be placed in arr 
*/
int OpenHashTable::hashFunction(string &itemName) {
    int hashVal = 0;

    for (int i = 0; i < itemName.length(); i++)
        hashVal = 37 * hashVal + itemName[i];

    hashVal %= MAX_TABLE_SIZE;

    if (hashVal < 0)
        hashVal += MAX_TABLE_SIZE;
    
    return hashVal;
}

void OpenHashTable::addItem(string itemName, int amount) {
    if (size >= MAX_TABLE_SIZE) {
        cout<<"Table already full, cannot insert element."<<endl;
        return;
    }
    //find the index to insert item.
    int insertIndex = hashFunction(itemName);

    if (occupied[insertIndex] || deleted[insertIndex]) {
        if (arr[insertIndex].getName() == itemName) {
            cout<<"Item already on table."<<endl;
            return;
        }
        //do probing & set insertIndex to new insertIndex
        //insert in the proper place & return from function.
        int newIndex = (insertIndex + 1) % MAX_TABLE_SIZE;
        for (int i = 2; (newIndex != insertIndex) && (isOccupied(newIndex) || isDeleted(newIndex)); i++) {
            newIndex = (insertIndex + i * i) % MAX_TABLE_SIZE;
        }
        if (newIndex == insertIndex) {
            cout<<"Table is full, cannot insert element."<<endl;
            return;
        }
        //insert into newIndex
        occupied[newIndex] = true;
        deleted[newIndex] = false;
        arr[newIndex] = FoodItem(itemName, amount);
    } else {
        //if we come here then the index is freely available so we
        //put it in its corresponding place
        occupied[insertIndex] = true;
        deleted[insertIndex] = false;
        arr[insertIndex] = FoodItem(itemName, amount);
        size++;
    }
}

void OpenHashTable::deleteItem(string itemName) {
    //find index of item in table
    int index = hashFunction(itemName);
    if (occupied[index]) {
        deleted[index] = true;
        occupied[index] = false;
        size--;
    } else {
        cout<<"Item not on the list, cannot be deleted."<<endl;
    }
}

void OpenHashTable::findItem(string itemName) {
    //first find index of item
    int index = hashFunction(itemName);

    if (isOccupied(index)) {
        if (arr[index].getName() == itemName) {
            cout<<"Item found. Name: "<<arr[index].getName();
            cout<<" - Count: "<<arr[index].getAmount()<<endl;
        } else {
            //look for item via probing.
        }
    }
    
    //check if deleted
    if (isDeleted(index)) {
        //look for item via probing
    }
    //guess we're done?
}

void OpenHashTable::printTable() {
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        cout<<i<<": ";
        if (occupied[i]) {
            cout<<arr[i].getName()<<" = "<<arr[i].getAmount()<<endl;
        } else {
            cout<<"-"<<endl;
        }
    }
}