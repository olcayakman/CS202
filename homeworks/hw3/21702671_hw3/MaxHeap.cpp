/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : MaxHeap data structure implementation file.
*/

#include "MaxHeap.h"

MaxHeap::MaxHeap() : size(0) {}

bool MaxHeap::heapIsEmpty() const {
    return (size == 0);
}

void MaxHeap::heapInsert(Request*& newItem) {
    if (size >= MAX_HEAP) 
        return;
    items[size] = newItem;

    int place = size;
    int parent = (place - 1) / 2;
    while ( (place > 0 && items[place]->getPriority() > items[parent]->getPriority()) /*|| 
            (place > 0 && items[place]->getPriority() == items[parent]->getPriority() &&
             items[place]->getTime() < items[parent]->getTime()) */) {
        Request* tmp = items[parent];
        items[parent] = items[place];
        items[place] = tmp;

        place = parent;
        parent = (place - 1) / 2;
    }
    ++size;
}

void MaxHeap::heapDelete(Request*& rootItem) {
    if (heapIsEmpty())
        return;
    rootItem = items[0];
    items[0] = items[--size];
    heapRebuild(0);
}

void MaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if (child < size) {
        int rightChild = child + 1;
        if ( (rightChild < size && items[rightChild]->getPriority() < items[child]->getPriority()) ||
             (rightChild < size && items[rightChild]->getPriority() == items[child]->getPriority() &&
              items[rightChild]->getTime() < items[child]->getTime()) )
            child = rightChild;
        if ( (items[root]->getPriority() < items[child]->getPriority()) ||
             (items[root]->getPriority() == items[child]->getPriority() &&
              items[child]->getTime() < items[root]->getTime()) ) {
            Request* tmp = items[root];
            items[root] = items[child];
            items[child] = tmp;

            heapRebuild(child);
        }
    }
}

Request* MaxHeap::peek() {
    return items[0];
}