/**
 * CS 202 - HW 1
 * A minimalistic main file
 * Please make sure that your code compiles and runs with this main file
 */

#include "sorting.h"

int main() {
	int arr[8] = {1, 5, 20, 10, 15, 123, 90, 66};
	int compCount = 0, moveCount = 0;
	sorting sorts;

	// call insertionSort
	sorts.insertionSort(arr, 8, compCount, moveCount);
	cout << compCount << "   " << moveCount<< "  ";
	// reset counters and call mergeSort
	compCount = 0, moveCount = 0;
	sorts.mergeSort(arr, 8, compCount, moveCount);
	cout << compCount << "   " << moveCount << "  ";
	// reset counters and call quickSort
	compCount = 0, moveCount = 0;
	sorts.quickSort(arr, 8, compCount, moveCount);
	cout << compCount << "   " << moveCount << "  ";
	// call performanceAnalysis
	sorts.performanceAnalysis();

	return 0;
}
