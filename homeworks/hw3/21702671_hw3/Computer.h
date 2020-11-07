/**
* Title : Heaps & AVL Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 3
* Description : Computer objects process requests,
*               one request at a time.
*/

#include "Request.h"

#ifndef _COMPUTER
#define _COMPUTER
class Computer {

public:
    Computer() {}
    Computer(int id): available(true) {}
    
    bool isAvailable() const;
    void processRequest(Request*& r, int& time);

private:
    int id;
    bool available;

};
#endif