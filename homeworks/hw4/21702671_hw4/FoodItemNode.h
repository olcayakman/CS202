/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 4
* Description : FoodItemNode.
*/

#include <string>

using namespace std;

#ifndef _FOOD_NODE
#define _FOOD_NODE
class FoodItemNode {

public:
    //FoodItemNode():name(""), amount(0), next(NULL){}
    FoodItemNode(string name = "", int amount = 0, FoodItemNode* next = NULL);
    string getName() {return name;}
    int getAmount() {return amount;}
    FoodItemNode* getNextPtr() {return next;}

private:
    string name;
    int amount;
    FoodItemNode* next;

};
#endif