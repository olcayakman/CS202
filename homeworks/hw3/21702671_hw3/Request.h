/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : Requests (Nodes) class. Has four int properties.
*/

#ifndef _REQUEST
#define _REQUEST
class Request {

public:
    Request() {}
    Request(int& id, int& priority, int& time, int& duration):
            id(id), priority(priority), time(time), duration(duration) {}

    int getId();
    int getPriority();
    int getTime();
    int getDuration();

private:
    int id;
    int priority;
    int time;
    int duration;

};
#endif