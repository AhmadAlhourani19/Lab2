#include "Task2 Lib.h"

// Function to merge two subarrays during Merge Sort
void merge(int array[], int l, int m, int r, int* comparisonsCount, int* swapsCount) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;
	int comparisons = 0;
	int swaps = 0;

	/* create temp arrays */
	int leftArray[MAXSIZE], rightArray[MAXSIZE];

	/* Copy data to temp arrays leftArray[] and rightArray[] */
	for (i = 0; i < leftSize; i++)
		leftArray[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightArray[j] = array[m + 1 + j];

	/* Merge the temp arrays back into array[l..r]*/
	// Initial index of first subarray
	i = 0;
	// Initial index of second subarray
	j = 0;
	// Initial index of merged subarray
	k = l;

	while ((i < leftSize) && (j < rightSize)) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
		comparisons++;  // Incrementing comparisons here
		swaps++;        // Incrementing swaps here
	}

	/* Copy the remaining elements of left side[], if there	are any */
	while (i < leftSize) {
		array[k] = leftArray[i];
		i++;
		k++;
		swaps++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < rightSize) {
		array[k] = rightArray[j];
		j++;
		k++;
		swaps++;
	}
	*comparisonsCount += comparisons;
	*swapsCount += swaps;

}

// Mergesort algorithm
void mergesort(int array[], int l, int r, int* comparisonsCount, int* swapsCount) {
	// End of recursion reached?
	if (l >= r)
		return;

	// Calculate the middle index
	int m = l + (r - l) / 2;

	// Recursively apply Merge Sort to the left and right subarrays
	mergesort(array, l, m, comparisonsCount, swapsCount);
	mergesort(array, m + 1, r, comparisonsCount, swapsCount);

	// Merge the two sorted subarrays
	merge(array, l, m, r, comparisonsCount, swapsCount);
}

// Function to merge two subarrays during bottom-up Merge Sort
void mergeBU(int array[], int l, int m, int r, int* comparisonsCount, int* swapsCount) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;
	int comparisons = 0;
	int swaps = 0;

	int leftPart[MAXSIZE], rightPart[MAXSIZE];

	// Copy data to temporary arrays
	for (i = 0; i < leftSize; i++)
		leftPart[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightPart[j] = array[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	// Merge the temporary arrays back into the original array
	while (i < leftSize && j < rightSize) {
		if (leftPart[i] <= rightPart[j]) {
			array[k] = leftPart[i];
			i++;
		}
		else {
			array[k] = rightPart[j];
			j++;
		}
		k++;
		comparisons++;
		swaps++;
	}

	// Copy the remaining elements of the left subarray
	while (i < leftSize) {
		array[k] = leftPart[i];
		i++;
		k++;
		swaps++;
	}

	// Copy the remaining elements of the left subarray
	while (j < rightSize) {
		array[k] = rightPart[j];
		j++;
		k++;
		swaps++;
	}

	// Update counters
	*comparisonsCount += comparisons;
	*swapsCount += swaps;
}

// Function to perform bottom-up Merge Sort on an array
void mergesortBU(int array[], int arraySize, int* comparisonsCount, int* swapsCount) {
	int currSize;
	int leftStart;

	// Iterate over different subarray sizes
	for (currSize = 1; currSize <= arraySize - 1; currSize = 2 * currSize) {
		// Iterate over subarrays with the current size
		for (leftStart = 0; leftStart < arraySize - 1; leftStart += 2 * currSize) {
			// Calculate mid and right_end for merging
			int mid = minimum(leftStart + currSize - 1, arraySize - 1);

			int right_end = minimum(leftStart + 2 * currSize - 1, arraySize - 1);

			// Merge the subarrays
			mergeBU(array, leftStart, mid, right_end, comparisonsCount, swapsCount);
		}
	}
}

// Function to find the minimum of two integers
int minimum(int x, int y) {
	return (x < y) ? x : y;
}

// Function to partition an array
int partition(int array[], int l, int r, int* comparisonsCount, int* swapsCount) {
	int i = l - 1;
	int j = r;
	int comparisons = 0;
	int swaps = 0;
	while (1) {
		// find item on left
		while (less(array[++i], array[r]))
			comparisons++;
			if (i == r)
				// to swap
				break;
		// find item on right
		while (less(array[r], array[--j]))
			comparisons++;
			// to swap
			if (j == l)
				break;
		// do pointers cross ?
		if (i >= j)
			break;
		// otherwise do swap
		swap(array, i, j);
		swaps++;
	}
	// final swap
	swap(array, i, r);
	swaps++;
	*comparisonsCount += comparisons;
	*swapsCount += swaps;
	// return index of cross point
	return i;
}

// quicksort Algorithm
void quicksort(int array[], int l, int r, int* comparisonsCount, int* swapsCount) {
	// Base case: if the subarray has one or zero elements, it is already sorted
	if (r - l <= 0)
		return;

	// Partition the array
	int m = partition(array, l, r, comparisonsCount, swapsCount);

	// Recursively apply Quicksort to the left and right subarrays
	quicksort(array, l, m - 1, comparisonsCount, swapsCount);
	quicksort(array, m + 1, r, comparisonsCount, swapsCount);
}

// InsertionSort Algorithm
void insertionSort(int array[]) {
	int i = 1;
	int j = 0;
	int comparisonsCount = 0;
	int exchangesCount = 0;

	// Iterate through the array starting from the second element
	while (i < MAXSIZE) {
		j = i;

		// Move elements to the correct position in the sorted part of the array
		while ((j > 0) && (array[j - 1] > array[j])) {
			// Swap elements
			swap(array, j, j - 1);
			j = j - 1;
			comparisonsCount++;
			exchangesCount++;
		}
		i = i + 1;
	}

	// Print the number of comparisons and exchanges
	printf("Insertion Sort:\n");
	printf("Comparisons: %d\n", comparisonsCount);
	printf("Exchanges: %d\n\n", exchangesCount);
}

// selectionSort algothm
void selectionSort(int arr[], int size) {
	int i, j, minIndex;
	int swapCount = 0;
	int comparisonsCount = 0;

	// Goes through array
	for (i = 0; i < size - 1; i++) {
		minIndex = i;

		// Find the minimum element in the unsorted part of the array
		for (j = i + 1; j < size; j++) {
			comparisonsCount++;
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		// Swap elements if the minimum is not at the current index
		if (minIndex != i) {
			swap(arr, arr[i], arr[minIndex]);
			swapCount++;
		}
	}
	printf("Selection Sort:\n");
	printf("Swaps: %d\n", swapCount);
	printf("Comparisons: %d\n\n", comparisonsCount);
}

void shellSort(int arr[], int size) {
	int gaps[] = { 6, 3, 1 };  // Specify the gap intervals here
	int numGaps = sizeof(gaps) / sizeof(gaps[0]);

	int swapCount = 0;
	int comparisonsCount = 0;

	// Iterate through the gap 
	for (int g = 0; g < numGaps; g++) {
		int gap = gaps[g];

		// Perform insertion sort for each gap
		for (int i = gap; i < size; i++) {
			int temp = arr[i];
			int j;

			// Insertion sort within the current gap
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
				swapCount++;  // Zähler für Vertauschungen erhöhen
				comparisonsCount++;  // Zähler für Vergleiche erhöhen
			}

			arr[j] = temp;
		}
	}

	// Print the number of swaps and comparisons
	printf("Shell Sort:\n");
	printf("Swaps: %d\n", swapCount);
	printf("Comparisons: %d\n\n", comparisonsCount);
}

// Function that compares two Elements
// Returns 1 if i is less than j, 0 otherwise
int less(int i, int j) {
	if (i < j)
		return 1;
	else
		return 0;
}

//Function to print array
void printArray(int array[]) {
	for (int i = 0; i < MAXSIZE; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}

// Function that performs a swap of two elements
void swap(int array[], int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}