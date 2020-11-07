/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : Computer class impelentation file.
*/

#include "Computer.h"

#include <iostream>

using namespace std;

bool Computer::isAvailable() const {
    return available;
}

void Computer::processRequest(Request*& r, int& t) {
    while (r->getDuration() > t) {
        available = false;
        t++;
    }
    available = true;
}