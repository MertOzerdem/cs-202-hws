#include "sorting.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

void sorting::insertionSort(int *theArray, int size, int &compCount, int &moveCount) {

  for (int unsorted = 1; unsorted < size; ++unsorted) {

    int nextItem = theArray[unsorted];
    int loc = unsorted;

    for (  ;(loc > 0) && (theArray[loc-1] > nextItem); --loc){
        compCount++;
        moveCount++;
        theArray[loc] = theArray[loc-1];
    }

    theArray[loc] = nextItem;
  }
}

const int MAX_SIZE = 20000;

void merge( int *theArray, int first, int mid, int last, int &compCount, int &moveCount) {

	int *tempArray = new int[MAX_SIZE]; 	// temporary array

	int first1 = first; 	// beginning of first subarray
   int last1 = mid; 		// end of first subarray
   int first2 = mid + 1;	// beginning of second subarray
   int last2 = last;		// end of second subarray
   int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      if (theArray[first1] < theArray[first2]) {
         compCount++;
         moveCount++;
         tempArray[index] = theArray[first1];
         ++first1;
      }
      else {
          compCount++;
          moveCount++;
          tempArray[index] = theArray[first2];
          ++first2;
      }
   }
	// finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index){
      tempArray[index] = theArray[first1];
      moveCount++;
   }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index){
      tempArray[index] = theArray[first2];
      moveCount++;
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index){
      theArray[index] = tempArray[index];
      moveCount++;
   }

}  // end merge

void mergesort( int *theArray, int first, int last, int &compCount, int &moveCount) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergesort(theArray, first, mid, compCount, moveCount);

      mergesort(theArray, mid+1, last, compCount, moveCount);

      // merge the two halves
      merge(theArray, first, mid, last, compCount, moveCount);
   }
}  // end mergesort

void sorting::mergeSort(int *theArray, int size, int &compCount, int &moveCount){
    mergesort(theArray, 0, size-1, compCount, moveCount);
}

void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
   // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

   int pivot = theArray[last]; // copy pivot
       // initially, everything but pivot is in unknown
   int lastS1 = first;          // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  compCount++;
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
          moveCount = moveCount + 3;
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   moveCount = moveCount + 3;
   pivotIndex = lastS1;
}

void quicksort(int *theArray, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

	int pivotIndex = last;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quicksort(theArray, first, pivotIndex-1, compCount, moveCount);
      quicksort(theArray, pivotIndex+1, last, compCount, moveCount);
   }
}

void sorting::quickSort(int *theArray, int size, int &compCount, int &moveCount){
    quicksort(theArray, 0, size-1, compCount, moveCount);
}

void sorting::performanceAnalysis(){

    int comp1 = 0, move1 = 0;
    double runtime;
    // time template
    clock_t beginning = clock();
    //runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;

    int *arr1 = new int[5000];
    int *arr2 = new int[10000];
    int *arr3 = new int[15000];
    int *arr4 = new int[20000];

    // insertion sort random
    for(int i = 0; i < 5000; i++)
        arr1[i] = rand() % 20000 + 1;

    for(int i = 0; i < 10000; i++)
        arr2[i] = rand() % 20000 + 1;

    for(int i = 0; i < 15000; i++)
        arr3[i] = rand() % 20000 + 1;

    for(int i = 0; i < 20000; i++)
        arr4[i] = rand() % 20000 + 1;

    beginning = clock();
    insertionSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    insertionSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    // insertion sort descending

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = 5000-i;

    for(int i = 0; i < 10000; i++)
        arr2[i] = 10000-i;
    for(int i = 0; i < 15000; i++)
        arr3[i] = 15000-i;

    for(int i = 0; i < 20000; i++)
        arr4[i] = 20000-i;

        comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    insertionSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    // insertion sort ascending

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = i;

    for(int i = 0; i < 10000; i++)
        arr2[i] = i;
    for(int i = 0; i < 15000; i++)
        arr3[i] = i;

    for(int i = 0; i < 20000; i++)
        arr4[i] = i;

    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    insertionSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    insertionSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    // quick sort random

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = rand() % 20000 + 1;

    for(int i = 0; i < 10000; i++)
        arr2[i] = rand() % 20000 + 1;

    for(int i = 0; i < 15000; i++)
        arr3[i] = rand() % 20000 + 1;

    for(int i = 0; i < 20000; i++)
        arr4[i] = rand() % 20000 + 1;

    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort random\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    quickSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort random\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort random\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort random\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";




    //////// quick sort descending


    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = 5000-i;

    for(int i = 0; i < 10000; i++)
        arr2[i] = 10000-i;
    for(int i = 0; i < 15000; i++)
        arr3[i] = 15000-i;

    for(int i = 0; i < 20000; i++)
        arr4[i] = 20000-i;

    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort descending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    quickSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort descending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort descending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort descending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    ///// quickSort ascending

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = i;

    for(int i = 0; i < 10000; i++)
        arr2[i] = i;
    for(int i = 0; i < 15000; i++)
        arr3[i] = i;

    for(int i = 0; i < 20000; i++)
        arr4[i] = i;

    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    quickSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    quickSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << "Quick Sort ascending\t comparisons\tTime elapsed\tDatamoves";
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    // merge sort random

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = rand() % 20000 + 1;

    for(int i = 0; i < 10000; i++)
        arr2[i] = rand() % 20000 + 1;

    for(int i = 0; i < 15000; i++)
        arr3[i] = rand() % 20000 + 1;

    for(int i = 0; i < 20000; i++)
        arr4[i] = rand() % 20000 + 1;

    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    mergeSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    // merge sort ascending

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = i;

    for(int i = 0; i < 10000; i++)
        arr2[i] = i;
    for(int i = 0; i < 15000; i++)
        arr3[i] = i;

    for(int i = 0; i < 20000; i++)
        arr4[i] = i;

    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    mergeSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    //// mergesort desecnding

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    arr1 = new int[5000];
    arr2 = new int[10000];
    arr3 = new int[15000];
    arr4 = new int[20000];

    for(int i = 0; i < 5000; i++)
        arr1[i] = 5000-i;

    for(int i = 0; i < 10000; i++)
        arr2[i] = 10000-i;
    for(int i = 0; i < 15000; i++)
        arr3[i] = 15000-i;

    for(int i = 0; i < 20000; i++)
        arr4[i] = 20000-i;

    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr1, 5000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    beginning = clock();
    comp1 = 0, move1 = 0;
    mergeSort(arr2, 10000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr3, 15000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";

    comp1 = 0, move1 = 0;
    beginning = clock();
    mergeSort(arr4, 20000, comp1, move1);
    runtime = 1000 * double(clock() - beginning ) / CLOCKS_PER_SEC;
    cout << comp1 << "\t"<< runtime << "\t" << move1 << "\n";


}
