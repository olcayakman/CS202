/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : MinHeap data structure class.
*/

#include "Request.h"

#include <iostream>

using namespace std;

const int MAX_HEAP_SIZE = 405;

#ifndef _MIN_HEAP
#define _MIN_HEAP
class MinHeap {

public:
    MinHeap(): size(0) {}

    bool heapIsEmpty() const;
    void heapInsert(Request*& newItem);
    void heapDelete(Request*& rootItem);
    Request* peek();

protected:
    void heapRebuild(int root);

private:
    Request* items[MAX_HEAP_SIZE];
    int size;

};
#endif