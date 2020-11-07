/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : this is an events queue where
*               the request with the smallest time
*               is at the top. Uses a minheap for
*               implementation.
*/

#include "Request.h"
#include "MinHeap.h"

#ifndef _EVENT_TIME
#define _EVENT_TIME
class EventTimeQueue {

public:
    EventTimeQueue() {}

    bool isEmpty() const;
    void insertEvent(Request*& newItem);
    void removeEvent(Request*& item);
    Request* peek();

private:
    MinHeap h;

};
#endif