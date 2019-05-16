   /**
 * Header file for CS 202 - HW 1
 * DO NOT MODIFY THIS FILE
 */

#include <iostream>
using namespace std;
#ifndef SORTING_H
#define SORTING_H

class sorting
{
// Question 2 - part (a): function prototypes
public:
void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);

// Question 2 - part (b): function prototype
void performanceAnalysis();

};

#endif // SORTING_H
