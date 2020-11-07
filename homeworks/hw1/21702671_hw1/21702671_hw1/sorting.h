/**
 * Title: Algorithm  Efficiency  and  Sorting
 * Author: Olcay Akman
 * ID: 21702671
 * Section: 1
 * Assignment: 1
 * Description: In this header file I define a Sorting class
 *              and in it are the three required sorting
 *              algotirhms' declarations.
 */

#ifndef _SORTING
#define _SORTING

class Sorting {

public:

    void quickSort(int *arr, int f ,int l, int &compCount, int &moveCount);
    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void hybridSort(int *arr, int size, int &compCount, int &moveCount);

    void partition(int *arr, int f, int l, int &pivotIndex, int &compCount, int &moveCount);
    void printArray(int *arr, int size);

    void performanceAnalysis();

private:
    void performanceAnalysis(int arrSize,
                             float &elapsedTimeQS,
                             float &elapsedTimeIS,
                             float &elapsedTimeHS,
                             int &compCountQS,
                             int &compCountIS,
                             int &compCountHS,
                             int &moveCountQS,
                             int &moveCountIS,
                             int &moveCountHS);
    int* createArray(int arrSize);
};

#endif