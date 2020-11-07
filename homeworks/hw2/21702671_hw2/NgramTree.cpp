/**
* Title : Binary Search Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 2
* Description : NgramTree class implementation file.
*/

#include "NgramTree.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * The constructor of the NgramTree. 
 */
NgramTree::NgramTree() {
    root = NULL; //sets root to NULL
}

/**
 * The destructor of the NgramTree.
 */
NgramTree::~NgramTree() {
    destroyTree(root); //destroys the tree
}

/**
 * Given the value of an ngram string, adds a new node to
 * the tree with the given ngram as its ngram. If such
 * a node already exists, the method increments the
 * count of that node with the given ngram value.
 */
void NgramTree::addNgram(string ngram) {
    insertItem(root, ngram);
}

/**
 * Recursively computes and returns the total number of 
 * ngrams currently stored in the tree.
 */
int NgramTree::getTotalNgramCount() {
    return getTotalNgramCount(root);
}

/**
 * Recursively prints each ngram in the tree in alphabetical
 * order along with their frequencies.
 */
void NgramTree::printNgramFrequencies() {
    printNgramFrequencies(root);
}

/**
 * Computes and returns whether or not the current
 * tree is a complete tree.
 */
bool  NgramTree::isComplete() {
    int nodeCount = getTotalNgramCount();
    bool complete = isCompleteHelper(root, 0, nodeCount);
    return complete;
}

/**
 * Computes and returns whether or not the current
 * tree is a full tree.
 */
bool NgramTree::isFull() {
    return isFull(root);
}

/**
 * Reads the input text and generates a BST of ngrams. This
 * function detects all of the ngrams in the input text and adds 
 * them to the tree by using addNgram function. Function also
 * requires the parameter n.
 */
void NgramTree::generateTree(string fileName, int n) {
    ifstream inFile;
    string input;
    inFile.open(fileName);
    if (!inFile) {
        cerr<<"Unable to open file"<<endl;
        exit(1); //call system to stop
    }
    while(inFile>>input) {
        //addNgram(input);
        if (input.length() >= n) {
            for (int i = 0; i < (input.length() - n + 1); i++) {
                addNgram(input.substr(i, 4));
            }
        }
    }
    inFile.close();
}





//****************************************************************//
//****************************************************************//
//****************************************************************//
//****************************************************************//





//additional & helpful functions of my choice

/**
 * uses postorder traversal for the destroy operation --
 * visits first the left and right children and then 
 * the node.
 */
void NgramTree::destroyTree(TreeNode*& treePtr) {
    if (treePtr == NULL)
        return;
    destroyTree(treePtr->leftChildPtr);
    destroyTree(treePtr->rightChildPtr);
    delete treePtr;
    treePtr = NULL;
}

/**
 * Inserts into the tree a new node with the given ngram value.
 * If such a node already exists, it increments the count value of
 * that node.
 */
void NgramTree::insertItem(TreeNode*& treePtr, const string ngram) {
    //if treePtr is null, we create new node here.
    if (treePtr == NULL) {
        treePtr = new TreeNode(ngram, 1, NULL, NULL);
    }
    //if root already has the node with the specified ngram 
    //value, we increment the count of it.
    else if (ngram.compare(treePtr->ngram) == 0) {
        treePtr->count = treePtr->count + 1;
    } else if (ngram.compare(treePtr->ngram) < 0) { //can string comparison be done
        insertItem(treePtr->leftChildPtr, ngram); //like so?
    } else {
        insertItem(treePtr->rightChildPtr, ngram);
    }
}

/**
 * Returns the number of nodes in a tree given the TreeNode
 * pointer to its root.
 */
int NgramTree::getTotalNgramCount(TreeNode* treePtr) {
    if (treePtr == NULL)
        return 0;
    int left = getTotalNgramCount(treePtr->leftChildPtr);
    int right = getTotalNgramCount(treePtr->rightChildPtr);
    return left + right + 1;
}

/**
 * Recursively prints each ngram in the tree in alphabetical
 * order along with their frequencies. -- uses inorder traversal
 */
void NgramTree::printNgramFrequencies(TreeNode* treePtr) {
    if (treePtr == NULL)
        return;

    printNgramFrequencies(treePtr->leftChildPtr);
    
    cout<<"ngram: "<<treePtr->ngram<<" -- ";
    cout<<"frequency: "<<treePtr->count<<endl;

    printNgramFrequencies(treePtr->rightChildPtr);
}

/**
 * Computes and returns whether the tree with given
 * root is complete or not.
 */
bool NgramTree::isCompleteHelper(TreeNode* treePtr, int index, int nodeCount) {
    if (treePtr != NULL) {
        if (index >= nodeCount)
            return false;
        else {
            bool left = isCompleteHelper(treePtr->leftChildPtr, 2*index+1, nodeCount);
            bool right = isCompleteHelper(treePtr->rightChildPtr, 2*index+1, nodeCount);
            return left && right;
        }
    } else 
        return true;
}

/**
 * Computes and returns whether the tree with the 
 * given root is full or not.
 */
bool NgramTree::isFull(TreeNode* treePtr) {
    if (treePtr == NULL) {
        return true;
    }
    if ( (treePtr->leftChildPtr == NULL) && (treePtr->rightChildPtr == NULL) )
        return true;
    else if ( (treePtr->leftChildPtr != NULL) && (treePtr->rightChildPtr != NULL) ) {
        bool left = isFull(treePtr->leftChildPtr);
        bool right = isFull(treePtr->rightChildPtr);
        return left && right;
    } else {
        return false;
    }
}