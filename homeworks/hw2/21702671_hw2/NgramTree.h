/**
* Title : Binary Search Trees
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 2
* Description : NgramTree class header file. Includes 
*               the TreeNode class.
*/

#include <string>

using namespace std;



#ifndef _TREE_NODE
#define _TREE_NODE

class TreeNode {
public: //------------------private yapilcak!
    TreeNode() {}
    TreeNode(const string& ngram, 
             const int& count, 
             TreeNode* left = NULL, 
             TreeNode* right = NULL)
             :ngram(ngram), count(count), leftChildPtr(left), rightChildPtr(right) {}

    string ngram;
    int count;
    TreeNode* leftChildPtr;
    TreeNode* rightChildPtr;
    friend class NgramTree;
};
#endif

#ifndef _NGRAM_TREE
#define _NGRAM_TREE

class NgramTree {

public:
    NgramTree();
    ~NgramTree();
    void addNgram(string ngram);
    int getTotalNgramCount();
    void printNgramFrequencies();
    bool isComplete();
    bool isFull();
    void generateTree(string fileName, int n);
    //... more to come

public: //-----------------------to private yap sonra!!!!
    //... more to come
    TreeNode* root; //pointer to the root of the tree

    //private methods...
    void destroyTree(TreeNode*& treePtr); //called by the destructor
    void insertItem(TreeNode*& treePtr, const string ngram); //called by addNgram
    int getTotalNgramCount(TreeNode* treePtr); //called by getTotalNgramCount
    void printNgramFrequencies(TreeNode* treePtr); //called by printNgramFrequencies
    bool isCompleteHelper(TreeNode* treePtr, int index, int nodeCount); //called by isComplete
    bool isFull(TreeNode* treePtr); //called by isFull
};
#endif

