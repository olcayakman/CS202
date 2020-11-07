/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : main.cpp file for execution.
*/

#include "Simulation.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main( int arc, char **argv) {
    string fileName(argv[1]);
    double n = atoi(argv[2]); //n for avgwaitingtime

    Simulation s1(fileName, 5);
    //Simulation s2(fileName, 2);
    //Simulation s3(fileName, 3);
    //Simulation s4(fileName, 4);

    s1.simulate();
 

    //initialize event list
    //....

    /*event loop
        pull event w/ lowes-time off event priority queue
        process event
            decode what type of event
            run appropriate code
            compile statistics
            insert any nw events onto queue
    repeat*/
    //...
    
    //end program
    return 0;
}