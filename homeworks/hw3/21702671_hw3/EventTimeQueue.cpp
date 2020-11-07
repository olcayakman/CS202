/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : EventTimeQueue implementation
*               file.
*/

#include "EventTimeQueue.h"

#include <iostream>

using namespace std;

bool EventTimeQueue::isEmpty() const{
    return h.heapIsEmpty();
}

void EventTimeQueue::insertEvent(Request*& newItem) {
    h.heapInsert(newItem);
}

void EventTimeQueue::removeEvent(Request*& item) {
    h.heapDelete(item);
}

Request* EventTimeQueue::peek() {
    return h.peek();
}

