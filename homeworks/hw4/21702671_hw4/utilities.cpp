/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 4
* Description : utilities
*/

#include "utilities.h"
#include <iostream>
#include <cmath>

using namespace std;

int Utilities::binaryToDecimal(string s) {
    int accumulator = 0;
    int strSize = s.length();
    for (int i = strSize-1; i >= 0; i++) {
        int n = s[i] - 48;
        int x = pow(2, i);
        accumulator += x*n;
    }
    cout << s << " in decimal is " << accumulator<<endl;
}