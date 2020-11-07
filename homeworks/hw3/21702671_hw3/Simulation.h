/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : Simulation class, creates the two
*               queue's from the given text file
*               name. Calls the specific # of computers
*               given as a param to the correspinding
*               function.
*/

#include "Computer.h"
#include "Request.h"
#include "EventPriorityQueue.h"
#include "EventTimeQueue.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ROW = 101;
const int MAX_COMPUTERS = 101;

#ifndef _SIM
#define _SIM
class Simulation {

public:
    Simulation() {}
    Simulation (string filename, const int noOfComputers):
                filename(filename), noOfComputers(noOfComputers) {}

    void simulate();

protected:
    void readRequestsIntoArray(string filename);
    void createPriorityQueue();
    void createTimeQueue();
    void executeNextRequest();

private:
    int noOfComputers;
    string filename;
    EventPriorityQueue priorityQueue;
    EventTimeQueue timeQueue;
    Computer* computers[MAX_COMPUTERS];
    int noOfRequests;
    int log[MAX_ROW][4];

};
#endif