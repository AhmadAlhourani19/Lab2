#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Task2 Lib.h"

int main() {
    int arr[MAXSIZE] = { 64, 25, 12, 22, 11 };  // You can initialize your array here
    int size = sizeof(arr) / sizeof(arr[0]);
    int comparisonsCount = 0;
    int swapsCount = 0;

    int choice;
    printf("Choose a sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Shell Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Bottom-up Merge Sort\n");
    printf("6. Quick Sort\n");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
        insertionSort(arr);
        break;
    case 2:
        selectionSort(arr, size);
        break;
    case 3:
        shellSort(arr, size);
        break;
    case 4:
        mergesort(arr, 0, size - 1, &comparisonsCount, &swapsCount);	
        printf("Number of comparisons: %d\n", comparisonsCount);
        printf("Number of swaps: %d\n", swapsCount);
        break;
    case 5:
        mergesortBU(arr, size, &comparisonsCount, &swapsCount);
        printf("Number of comparisons: %d\n", comparisonsCount);
        printf("Number of swaps: %d\n", swapsCount);
        break;
    case 6:
        quicksort(arr, 0, size - 1, &comparisonsCount, &swapsCount);
        printf("Number of comparisons: %d\n", comparisonsCount);
        printf("Number of swaps: %d\n", swapsCount);
        break;
    default:
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Sorted array: \n");
    printArray(arr);

    return 0;
}