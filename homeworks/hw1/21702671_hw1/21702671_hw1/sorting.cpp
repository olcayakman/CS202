/**
 * Title: Algorithm  Efficiency  and  Sorting
 * Author: Olcay Akman
 * ID: 21702671
 * Section: 1
 * Assignment: 1
 * Description: In this implementation file, I implement the
 *              three following sorting algortihms.
 *              Quick Sort
 *              Insertion Sort
 *              Hybrid Sort
 */

#include "sorting.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <iomanip>

using namespace std;

const int MIN_SIZE = 10;


void Sorting::quickSort(int *arr, int f, int l, int &compCount, int &moveCount) {
    int pivotIndex = f;
    if (f < l) {
        partition(arr, f, l, pivotIndex, compCount, moveCount);

        quickSort(arr, f, pivotIndex-1, compCount, moveCount);
        quickSort(arr,pivotIndex+1, l, compCount, moveCount);
    }
}

void Sorting::insertionSort(int *arr, int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;

        for ( ; (loc > 0) && (arr[loc-1] > nextItem); --loc)
        {
            compCount++;
            arr[loc] = arr[loc-1];
            moveCount++;
        }

        arr[loc] = nextItem;
        moveCount++;
    }
}

void Sorting::hybridSort(int *arr, int size, int &compCount, int &moveCount) {
    if (size < MIN_SIZE) {
        insertionSort(arr, size, compCount, moveCount);
        return;
    } else {
        quickSort(arr, 0, size - 1, compCount, moveCount);
        return;
    }
}




//here are the utilities...

//for quickSort algorithm
void Sorting::partition(int *arr, int f, int l, int &pivotIndex, int &compCount, int &moveCount) {
    //choosePivot(arr, f, l);

    moveCount++;
    int pivot = arr[f]; //copy pivot

    //initially everything but pivot is in unknown
    int lastS1 = f; //index of last item in S1
    int firstUnknown = f + 1; //index of first item in unknown

    //move one item at a time until unknown region is empty
    for ( ; firstUnknown <= l; ++firstUnknown ) {
        //move item from unknown to proper region
        compCount++;
        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            moveCount = moveCount + 3;
            swap(arr[firstUnknown], arr[lastS1]);
        } //else belongs to S2
    }
    //place pivot in proper position and mark its location
    moveCount = moveCount + 3;
    swap(arr[f], arr[lastS1]);
    pivotIndex = lastS1;
}

void Sorting::printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

//******************************************************
//the privates

void Sorting::performanceAnalysis(int arrSize,
                                  float &elapsedTimeQS,
                                  float &elapsedTimeIS,
                                  float &elapsedTimeHS,
                                  int &compCountQS,
                                  int &compCountIS,
                                  int &compCountHS,
                                  int &moveCountQS,
                                  int &moveCountIS,
                                  int &moveCountHS) {
    //necessary declarations
    compCountQS = 0, moveCountQS = 0;
    compCountIS = 0, moveCountIS = 0;
    compCountHS = 0, moveCountHS = 0;
    clock_t startTime;

    //create three identical arrays of arrSize random integers
    int *array1 = createArray(arrSize);
    int *array2 = new int[arrSize]; 
    int *array3 = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        array2[i] = array1[i];
        array3[i] = array1[i];
    }

    //use the 1st array for quickSort -- calculate elapsed time
    startTime = clock();
    quickSort(array1, 0, arrSize - 1, compCountQS, moveCountQS);
    startTime = clock() - startTime;
    elapsedTimeQS = ((float)startTime) / CLOCKS_PER_SEC;
    elapsedTimeQS = elapsedTimeQS * 1000;

    //use the second array for insertionSort -- calculate elapsed time
    startTime = clock();
    insertionSort(array2, arrSize, compCountIS, moveCountIS);
    startTime = clock() - startTime;
    elapsedTimeIS = ((float)startTime) / CLOCKS_PER_SEC;
    elapsedTimeIS = elapsedTimeIS * 1000;

    //use the 3rd array for hybridSort -- calculate elapsed time
    startTime = clock();
    hybridSort(array3, arrSize, compCountHS, moveCountHS);
    startTime = clock() - startTime;
    elapsedTimeHS = ((float)startTime) / CLOCKS_PER_SEC;
    elapsedTimeHS = elapsedTimeHS * 1000;

    //delete the arrays created once we're done
    delete [] array1;
    delete [] array2;
    delete [] array3;
}

int* Sorting::createArray(int arrSize) {
    srand((int)time(0));
    int *arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
        arr[i] = (rand() % 1000) + 1;
    //system("pause");
    return arr;
}



//zikkim
void Sorting::performanceAnalysis() {
    //performance analysis for array sized 1500
    float elapsedTimeQS1500, elapsedTimeIS1500, elapsedTimeHS1500;
    int compCountQS1500 = 0, compCountIS1500 = 0, compCountHS1500 = 0;
    int moveCountQS1500 = 0, moveCountIS1500 = 0, moveCountHS1500 = 0;
    performanceAnalysis(1500, elapsedTimeQS1500, elapsedTimeIS1500, elapsedTimeHS1500, compCountQS1500, compCountIS1500, compCountHS1500, moveCountQS1500, moveCountIS1500, moveCountHS1500);

    //performance analysis for array sized 3000
    float elapsedTimeQS3000;
    float elapsedTimeIS3000;
    float elapsedTimeHS3000;
    int compCountQS3000 = 0;
    int compCountIS3000 = 0;
    int compCountHS3000 = 0;
    int moveCountQS3000 = 0;
    int moveCountIS3000 = 0;
    int moveCountHS3000 = 0;
    performanceAnalysis(3000,
                        elapsedTimeQS3000,
                        elapsedTimeIS3000,
                        elapsedTimeHS3000,
                        compCountQS3000,
                        compCountIS3000,
                        compCountHS3000,
                        moveCountQS3000,
                        moveCountIS3000,
                        moveCountHS3000);  

    //performance analysis for array sized 4500
    float elapsedTimeQS4500;
    float elapsedTimeIS4500;
    float elapsedTimeHS4500;
    int compCountQS4500 = 0;
    int compCountIS4500 = 0;
    int compCountHS4500 = 0;
    int moveCountQS4500 = 0;
    int moveCountIS4500 = 0;
    int moveCountHS4500 = 0;
    performanceAnalysis(4500,
                        elapsedTimeQS4500,
                        elapsedTimeIS4500,
                        elapsedTimeHS4500,
                        compCountQS4500,
                        compCountIS4500,
                        compCountHS4500,
                        moveCountQS4500,
                        moveCountIS4500,
                        moveCountHS4500);

    //performance analysis for array sized 6000
    float elapsedTimeQS6000;
    float elapsedTimeIS6000;
    float elapsedTimeHS6000;
    int compCountQS6000 = 0;
    int compCountIS6000 = 0;
    int compCountHS6000 = 0;
    int moveCountQS6000 = 0;
    int moveCountIS6000 = 0;
    int moveCountHS6000 = 0;
    performanceAnalysis(6000,
                        elapsedTimeQS6000,
                        elapsedTimeIS6000,
                        elapsedTimeHS6000,
                        compCountQS6000,
                        compCountIS6000,
                        compCountHS6000,
                        moveCountQS6000,
                        moveCountIS6000,
                        moveCountHS6000);

    //performance analysis for array sized 7500
    float elapsedTimeQS7500;
    float elapsedTimeIS7500;
    float elapsedTimeHS7500;
    int compCountQS7500 = 0;
    int compCountIS7500 = 0;
    int compCountHS7500 = 0;
    int moveCountQS7500 = 0;
    int moveCountIS7500 = 0;
    int moveCountHS7500 = 0;
    performanceAnalysis(7500,
                        elapsedTimeQS7500,
                        elapsedTimeIS7500,
                        elapsedTimeHS7500,
                        compCountQS7500,
                        compCountIS7500,
                        compCountHS7500,
                        moveCountQS7500,
                        moveCountIS7500,
                        moveCountHS7500);

    //performance analysis for array sized 9000
    float elapsedTimeQS9000;
    float elapsedTimeIS9000;
    float elapsedTimeHS9000;
    int compCountQS9000 = 0;
    int compCountIS9000 = 0;
    int compCountHS9000 = 0;
    int moveCountQS9000 = 0;
    int moveCountIS9000 = 0;
    int moveCountHS9000 = 0;
    performanceAnalysis(9000,
                        elapsedTimeQS9000,
                        elapsedTimeIS9000,
                        elapsedTimeHS9000,
                        compCountQS9000,
                        compCountIS9000,
                        compCountHS9000,
                        moveCountQS9000,
                        moveCountIS9000,
                        moveCountHS9000);

    //performance analysis for array sized 10500
    float elapsedTimeQS10500;
    float elapsedTimeIS10500;
    float elapsedTimeHS10500;
    int compCountQS10500 = 0;
    int compCountIS10500 = 0;
    int compCountHS10500 = 0;
    int moveCountQS10500 = 0;
    int moveCountIS10500 = 0;
    int moveCountHS10500 = 0;
    performanceAnalysis(10500,
                        elapsedTimeQS10500,
                        elapsedTimeIS10500,
                        elapsedTimeHS10500,
                        compCountQS10500,
                        compCountIS10500,
                        compCountHS10500,
                        moveCountQS10500,
                        moveCountIS10500,
                        moveCountHS10500);

    //performance analysis for array sized 12000
    float elapsedTimeQS12000;
    float elapsedTimeIS12000;
    float elapsedTimeHS12000;
    int compCountQS12000 = 0;
    int compCountIS12000 = 0;
    int compCountHS12000 = 0;
    int moveCountQS12000 = 0;
    int moveCountIS12000 = 0;
    int moveCountHS12000 = 0;
    performanceAnalysis(12000,
                        elapsedTimeQS12000,
                        elapsedTimeIS12000,
                        elapsedTimeHS12000,
                        compCountQS12000,
                        compCountIS12000,
                        compCountHS12000,
                        moveCountQS12000,
                        moveCountIS12000,
                        moveCountHS12000);      

    //performance analysis for array sized 13500
    float elapsedTimeQS13500;
    float elapsedTimeIS13500;
    float elapsedTimeHS13500;
    int compCountQS13500 = 0;
    int compCountIS13500 = 0;
    int compCountHS13500 = 0;
    int moveCountQS13500 = 0;
    int moveCountIS13500 = 0;
    int moveCountHS13500 = 0;
    performanceAnalysis(13500,
                        elapsedTimeQS13500,
                        elapsedTimeIS13500,
                        elapsedTimeHS13500,
                        compCountQS13500,
                        compCountIS13500,
                        compCountHS13500,
                        moveCountQS13500,
                        moveCountIS13500,
                        moveCountHS13500);

    //performance analysis for array sized 15000
    float elapsedTimeQS15000;
    float elapsedTimeIS15000;
    float elapsedTimeHS15000;
    int compCountQS15000 = 0;
    int compCountIS15000 = 0;
    int compCountHS15000 = 0;
    int moveCountQS15000 = 0;
    int moveCountIS15000 = 0;
    int moveCountHS15000 = 0;
    performanceAnalysis(15000,
                        elapsedTimeQS15000,
                        elapsedTimeIS15000,
                        elapsedTimeHS15000,
                        compCountQS15000,
                        compCountIS15000,
                        compCountHS15000,
                        moveCountQS15000,
                        moveCountIS15000,
                        moveCountHS15000);

    //time to print the holy table... 

    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Part a - Time analysis of Quick Sort"<<endl;

    cout<<setw(10)<<"Array Size";
    cout<<setw(29)<<"Time Elapsed";
    cout<<setw(45)<<"compCount";
    cout<<setw(61)<<"moveCount"<<endl;

    cout<<setw(10)<<"1500";
    cout<<setw(26)<<elapsedTimeQS1500<<" ms";
    cout<<setw(45)<<compCountQS1500;
    cout<<setw(61)<<moveCountQS1500<<endl;

    cout<<setw(10)<<"3000";
    cout<<setw(26)<<elapsedTimeQS3000<<" ms";
    cout<<setw(45)<<compCountQS3000;
    cout<<setw(61)<<moveCountQS3000<<endl;

    cout<<setw(10)<<"4500";
    cout<<setw(26)<<elapsedTimeQS4500<<" ms";
    cout<<setw(45)<<compCountQS4500;
    cout<<setw(61)<<moveCountQS4500<<endl;

    cout<<setw(10)<<"6000";
    cout<<setw(26)<<elapsedTimeQS6000<<" ms";
    cout<<setw(45)<<compCountQS6000;
    cout<<setw(61)<<moveCountQS6000<<endl;

    cout<<setw(10)<<"7500";
    cout<<setw(26)<<elapsedTimeQS7500<<" ms";
    cout<<setw(45)<<compCountQS7500;
    cout<<setw(61)<<moveCountQS7500<<endl;

    cout<<setw(10)<<"9000";
    cout<<setw(26)<<elapsedTimeQS9000<<" ms";
    cout<<setw(45)<<compCountQS9000;
    cout<<setw(61)<<moveCountQS9000<<endl;

    cout<<setw(10)<<"10500";
    cout<<setw(26)<<elapsedTimeQS10500<<" ms";
    cout<<setw(45)<<compCountQS10500;
    cout<<setw(61)<<moveCountQS10500<<endl;

    cout<<setw(10)<<"12000";
    cout<<setw(26)<<elapsedTimeQS12000<<" ms";
    cout<<setw(45)<<compCountQS12000;
    cout<<setw(61)<<moveCountQS12000<<endl;

    cout<<setw(10)<<"13500";
    cout<<setw(26)<<elapsedTimeQS13500<<" ms";
    cout<<setw(45)<<compCountQS13500;
    cout<<setw(61)<<moveCountQS13500<<endl;

    cout<<setw(10)<<"15000";
    cout<<setw(26)<<elapsedTimeQS15000<<" ms";
    cout<<setw(45)<<compCountQS15000;
    cout<<setw(61)<<moveCountQS15000<<endl;

    //.............................................

    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Part b - Time analysis of Insertion Sort"<<endl;

    cout<<setw(10)<<"Array Size";
    cout<<setw(29)<<"Time Elapsed";
    cout<<setw(45)<<"compCount";
    cout<<setw(61)<<"moveCount"<<endl;

    cout<<setw(10)<<"1500";
    cout<<setw(26)<<elapsedTimeIS1500<<" ms";
    cout<<setw(45)<<compCountIS1500;
    cout<<setw(61)<<moveCountIS1500<<endl;

    cout<<setw(10)<<"3000";
    cout<<setw(26)<<elapsedTimeIS3000<<" ms";
    cout<<setw(45)<<compCountIS3000;
    cout<<setw(61)<<moveCountIS3000<<endl;

    cout<<setw(10)<<"4500";
    cout<<setw(26)<<elapsedTimeIS4500<<" ms";
    cout<<setw(45)<<compCountIS4500;
    cout<<setw(61)<<moveCountIS4500<<endl;

    cout<<setw(10)<<"6000";
    cout<<setw(26)<<elapsedTimeIS6000<<" ms";
    cout<<setw(45)<<compCountIS6000;
    cout<<setw(61)<<moveCountIS6000<<endl;    

    cout<<setw(10)<<"7500";
    cout<<setw(26)<<elapsedTimeIS7500<<" ms";
    cout<<setw(45)<<compCountIS7500;
    cout<<setw(61)<<moveCountIS7500<<endl;

    cout<<setw(10)<<"9000";
    cout<<setw(26)<<elapsedTimeIS9000<<" ms";
    cout<<setw(45)<<compCountIS9000;
    cout<<setw(61)<<moveCountIS9000<<endl;

    cout<<setw(10)<<"10500";
    cout<<setw(26)<<elapsedTimeIS10500<<" ms";
    cout<<setw(45)<<compCountIS10500;
    cout<<setw(61)<<moveCountIS10500<<endl;

    cout<<setw(10)<<"12000";
    cout<<setw(26)<<elapsedTimeIS12000<<" ms";
    cout<<setw(45)<<compCountIS12000;
    cout<<setw(61)<<moveCountIS12000<<endl;

    cout<<setw(10)<<"13500";
    cout<<setw(26)<<elapsedTimeIS13500<<" ms";
    cout<<setw(45)<<compCountIS13500;
    cout<<setw(61)<<moveCountIS13500<<endl;

    cout<<setw(10)<<"15000";
    cout<<setw(26)<<elapsedTimeIS15000<<" ms";
    cout<<setw(45)<<compCountIS15000;
    cout<<setw(61)<<moveCountIS15000<<endl;

    //.............................................

    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Part c - Time analysis of Hybrid Sort"<<endl;

    cout<<setw(10)<<"Array Size";
    cout<<setw(29)<<"Time Elapsed";
    cout<<setw(45)<<"compCount";
    cout<<setw(61)<<"moveCount"<<endl;

    cout<<setw(10)<<"1500";
    cout<<setw(26)<<elapsedTimeHS1500<<" ms";
    cout<<setw(45)<<compCountHS1500;
    cout<<setw(61)<<moveCountHS1500<<endl;

    cout<<setw(10)<<"3000";
    cout<<setw(26)<<elapsedTimeHS3000<<" ms";
    cout<<setw(45)<<compCountHS3000;
    cout<<setw(61)<<moveCountHS3000<<endl;

    cout<<setw(10)<<"4500";
    cout<<setw(26)<<elapsedTimeHS4500<<" ms";
    cout<<setw(45)<<compCountHS4500;
    cout<<setw(61)<<moveCountHS4500<<endl;

    cout<<setw(10)<<"6000";
    cout<<setw(26)<<elapsedTimeHS6000<<" ms";
    cout<<setw(45)<<compCountHS6000;
    cout<<setw(61)<<moveCountHS6000<<endl;

    cout<<setw(10)<<"7500";
    cout<<setw(26)<<elapsedTimeHS7500<<" ms";
    cout<<setw(45)<<compCountHS7500;
    cout<<setw(61)<<moveCountHS7500<<endl;

    cout<<setw(10)<<"9000";
    cout<<setw(26)<<elapsedTimeHS9000<<" ms";
    cout<<setw(45)<<compCountHS9000;
    cout<<setw(61)<<moveCountHS9000<<endl;

    cout<<setw(10)<<"10500";
    cout<<setw(26)<<elapsedTimeHS10500<<" ms";
    cout<<setw(45)<<compCountHS10500;
    cout<<setw(61)<<moveCountHS10500<<endl;

    cout<<setw(10)<<"12000";
    cout<<setw(26)<<elapsedTimeHS12000<<" ms";
    cout<<setw(45)<<compCountHS12000;
    cout<<setw(61)<<moveCountHS12000<<endl;

    cout<<setw(10)<<"13500";
    cout<<setw(26)<<elapsedTimeHS13500<<" ms";
    cout<<setw(45)<<compCountHS13500;
    cout<<setw(61)<<moveCountHS13500<<endl;

    cout<<setw(10)<<"15000";
    cout<<setw(26)<<elapsedTimeHS15000<<" ms";
    cout<<setw(45)<<compCountHS15000;
    cout<<setw(61)<<moveCountHS15000<<endl;

    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

}