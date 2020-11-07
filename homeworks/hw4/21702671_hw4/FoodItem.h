/**
* Title : Balanced Search Trees , Hash Tables & Graphs
* Author : Olcay Akman
* ID: 21702671
* Section : 1
* Assignment : 4
* Description : FoodItem.
*/

#include <string>

using namespace std;

#ifndef _FOOD_ITEM
#define _FOOD_ITEM
class FoodItem {

public:
    //FoodItem():name(""), amount(0){}
    FoodItem(string name = "", int amout = 0);
    string getName() {return name;}
    int getAmount() {return amount;}

private:
    string name;
    int amount;

};
#endif