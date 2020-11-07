/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : Simulation class implementation file.
*/

#include "Simulation.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Simulation::simulate() {
    //simulate
    readRequestsIntoArray(filename);
    //createPriorityQueue();
    createTimeQueue();
    //create computers
    for (int i = 0; i < noOfComputers; i++) {
        computers[i] = new Computer(i);
    }
    int t = 0; // t is for time
    int compIterator = 0;
    while ( !(timeQueue.isEmpty()) ) {
        while(timeQueue.peek()->getTime() == t) {
            Request* r;
            timeQueue.removeEvent(r);
            cout<<"Request id: "<<r->getId()<<endl;
            priorityQueue.insertEvent(r);
        }
        //bu while'a girmiyo cunku priQueue bos suan...
        while ( !(priorityQueue.isEmpty()) &&
                (t >= priorityQueue.peek()->getTime()) && 
                (computers[compIterator % noOfComputers]->isAvailable()) ) {
            cout<<"Computer "<<compIterator%noOfComputers;
            cout<<" takes request "<<priorityQueue.peek()->getId();
            cout<<" at ms: "<<t<<" (wait: ";
            cout<<t-priorityQueue.peek()->getTime()<<" ms)"<<endl;
            Request* processable;
            priorityQueue.removeEvent(processable);
            computers[(compIterator++) % noOfComputers]->processRequest(processable, t);
        }
        ++t;
    }
}

void Simulation::readRequestsIntoArray(string filename) {
    ifstream File;
    File.open(filename);
    File>>noOfRequests; //get first item.
    if (noOfRequests > MAX_ROW)
        return;
    for (int i = 0; i < noOfRequests; i++) {
        for (int j = 0; j < 4; j++) {
            File>>log[i][j];
        }
    }
    File.close();
}

void Simulation::createPriorityQueue() {
    for (int i = 0; i < noOfRequests; i++) {
        Request *nr = new Request(log[i][0], log[i][1], log[i][2], log[i][3]);
        priorityQueue.insertEvent(nr);
    }
}

void Simulation::createTimeQueue() {
    for (int i = 0; i < noOfRequests; i++) {
        Request *nr = new Request(log[i][0], log[i][1], log[i][2], log[i][3]);
        timeQueue.insertEvent(nr);
    }
}