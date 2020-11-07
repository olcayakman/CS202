/**
* Title : Binary Search Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 2
* Description : main.cpp file to use the implemented methods
*               of the NgramTree class.
*/

#include "NgramTree.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc , char **argv) {
    NgramTree tree ;
    string fileName(argv[1]);
    int n = atoi(argv[2]);

    tree.generateTree ( fileName , n);
    cout<<"\n Total "<<n<<"-gram count : "
        <<tree.getTotalNgramCount()<<endl ;
    tree.printNgramFrequencies();
    cout<<n<<"-gram tree is complete : "
        <<( tree.isComplete() ? "Yes" : "No")<<endl;

    // Before insertion of new n- grams
    cout<<"\n Total "<<n<<"-gram count : "
        <<tree.getTotalNgramCount()<<endl;
    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    cout<<"\n Total " << n << "-gram count : "
        <<tree.getTotalNgramCount()<<endl ;
    tree.printNgramFrequencies();
    cout<<n<<"-gram tree is complete : "
        <<(tree.isComplete() ? "Yes" : "No")<<endl ;
    cout<<n<<"-gram tree is full : "
        <<(tree.isFull() ? "Yes " : "No")<<endl ;

    //end program...
    return 0;   
}