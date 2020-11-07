/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : this is an events queue where
*               the request with the highest 
*               priority is at the top. Uses a 
*               maxHeap for implementation.
*/

#include "MaxHeap.h"
#include "Request.h"

#ifndef _EVENT_PRI
#define _EVENT_PRI
class EventPriorityQueue {

public:
    EventPriorityQueue() {}

    bool isEmpty() const;
    void insertEvent(Request*& newItem);
    void removeEvent(Request*& item);
    Request* peek();

private:
    MaxHeap h;

};
#endif

