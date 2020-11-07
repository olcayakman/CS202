/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : MaxHeap data structure class.
*/

#include "Request.h"

#include <iostream>

using namespace std;

const int MAX_HEAP = 405;

#ifndef _MAX_HEAP
#define _MAX_HEAP
class MaxHeap {

public:
    MaxHeap();

    bool heapIsEmpty() const;
    void heapInsert(Request*& newItem);
    void heapDelete(Request*& rootItem);
    Request* peek();

protected:
    void heapRebuild(int root);

private:    
    Request* items[MAX_HEAP];
    int size;

};
#endif