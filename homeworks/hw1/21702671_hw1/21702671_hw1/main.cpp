/**
 * Title: Algorithm  Efficiency  and  Sorting
 * Author: Olcay Akman
 * ID: 21702671
 * Section: 1
 * Assignment: 1
 * Description: This file contains the main method to   
 *              use the sorting algorithms I created in
 *              the sorting files.
 */

#include "sorting.h"
#include <iostream>

using namespace std;

int main()
{

    const int ARR_SIZE = 20;

    //code begins here...
    int *arr1 = new int[ARR_SIZE];
    arr1[0] = 22;
    arr1[1] = 11;
    arr1[2] = 6;
    arr1[3] = 7;
    arr1[4] = 30;
    arr1[5] = 2;
    arr1[6] = 27;
    arr1[7] = 24;
    arr1[8] = 9;
    arr1[9] = 1;
    arr1[10] = 20;
    arr1[11] = 17;

    int *arr2 = new int[ARR_SIZE];
    for (int i = 0; i < 12; i++)
        arr2[i] = arr1[i];

    int *arr3 = new int[ARR_SIZE];
    for (int i = 0; i < 12; i++)
        arr3[i] = arr1[i];

    int compCount1 = 0, moveCount1 = 0;
    int compCount2 = 0, moveCount2 = 0;
    int compCount3 = 0, moveCount3 = 0;

    Sorting s;

    cout<<"Initial array:"<<endl;
    s.printArray(arr1, 12);
    cout<<"\n";


    //******************************************************
    cout<<"******************************************************"<<endl;

    s.quickSort(arr1, 0, 11, compCount1, moveCount1);

    cout<<"Initial array after quick sort:"<<endl;
    s.printArray(arr1, 12);
    cout<<"\n";
    cout<<"The comparison count is "<<compCount1;
    cout<<" and the move count is "<<moveCount1<<endl;


    //******************************************************

    cout<<"******************************************************"<<endl;
    s.insertionSort(arr2, 12, compCount2, moveCount2);

    cout<<"Initial array after insertion sort:"<<endl;
    s.printArray(arr2, 12);
    cout<<"\n";
    cout<<"The comparison count is "<<compCount2;
    cout<<" and the move count is "<<moveCount2<<endl;


    //******************************************************

    cout<<"******************************************************"<<endl;
    s.hybridSort(arr3, 12, compCount3, moveCount3);

    cout<<"Initial array after hybrid sort:"<<endl;
    s.printArray(arr3, 12);
    cout<<"\n";
    cout<<"The comparison count is "<<compCount3;
    cout<<" and the move count is "<<moveCount3<<endl;


    //delete the dynamically allocated array
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;

    cout<<"Now we do the performance analysis: "<<endl;
    cout<<"\n";

    s.performanceAnalysis();




    //end main function
    return 0;
}