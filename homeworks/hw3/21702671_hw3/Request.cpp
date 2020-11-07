/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : Requests (Nodes) class implementation.
*/


#include "Request.h"
#include <iostream>

using namespace std;

int Request::getId() {
    return id;
}

int Request::getPriority() {
    return priority;
}

int Request::getTime() {
    return time;
}

int Request::getDuration() {
    return duration;
}

