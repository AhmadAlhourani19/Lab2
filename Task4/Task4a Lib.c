#include "Task4a Lib.h"

// Function to measure the execution time of a sorting function
double measureTime(void (*sortingFunction)(int[], int, int, int*, int*), int array[], int l, int r, int* comparisonsCount, int* swapsCount) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    sortingFunction(array, l, r, comparisonsCount, swapsCount);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
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

    /* Copy the remaining elements of left side[], if there are any */
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

void mergeSort(int array[], int l, int r, int* comparisonsCount, int* swapsCount) {
    // End of recursion reached?
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(array, l, m, comparisonsCount, swapsCount);
    mergeSort(array, m + 1, r, comparisonsCount, swapsCount);
    merge(array, l, m, r, comparisonsCount, swapsCount);
}

// Sorting Algorithm 
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

// Function to swap two elements
void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function to initialize an array with a random permutation of k elements
void initArray(int array[], int k) {
    for (int i = 0; i < MAXSIZE; i++) {
        array[i] = i + 1;
    }

    if (k >= MAXSIZE) {
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < MAXSIZE - k; i++) {
        int randomIndex = i + rand() % (MAXSIZE - i);
        swap(array, i, randomIndex);
    }
}