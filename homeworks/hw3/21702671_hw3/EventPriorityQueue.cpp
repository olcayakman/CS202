/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : EventPriorityQueue implementation
*               file.
*/

#include "EventPriorityQueue.h"

#include <iostream>

using namespace std;

bool EventPriorityQueue::isEmpty() const {
    return h.heapIsEmpty();
}

void EventPriorityQueue::insertEvent(Request*& newItem) {
    h.heapInsert(newItem);
}

void EventPriorityQueue::removeEvent(Request*& item) {
    h.heapDelete(item);
}

Request* EventPriorityQueue::peek() {
    return h.peek();
}

