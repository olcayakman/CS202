/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : MinHeap data structure implementation file.
*/

#include "MinHeap.h"

#include <iostream>

using namespace std;

bool MinHeap::heapIsEmpty() const {
    return (size == 0);
}

void MinHeap::heapInsert(Request*& newItem) {
    if (size >= MAX_HEAP_SIZE)
        return;
    //place new item at end of the heap
    items[size] = newItem;

    //Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1) / 2;
    while ( (place > 0 && items[place]->getTime() < items[parent]->getTime()) /*|| 
            (place > 0 && items[place]->getTime() == items[parent]->getTime() &&
             items[place]->getPriority() > items[parent]->getPriority())*/ ) {
        Request* tmp = items[parent];
        items[parent] = items[place];
        items[place] = tmp;
        place = parent;
        parent = (place - 1) / 2;
    }
    ++size;
}

void MinHeap::heapDelete(Request*& rootItem) {
    if (heapIsEmpty())
        return;
    else {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void MinHeap::heapRebuild(int root) {
    int child = 2 * root + 1; // index of root's left chile, if any
    if (child < size) {
        //root is not a leaf so that it has a left child
        int rightChild = child + 1;
        if ( (rightChild < size && items[rightChild]->getPriority() < items[child]->getPriority()) )
            child = rightChild;
        //if root's item is bigger than larger child, swpa values
        if ( (items[root]->getTime() > items[child]->getTime()) /*||
             (items[root]->getTime() == items[child]->getTime() &&
              items[root]->getPriority() < items[child]->getPriority()) */) {
            Request* tmp = items[child];
            items[child] = items[root];
            items[root] = tmp;
            //transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

Request* MinHeap::peek() {
    return items[0];
}

