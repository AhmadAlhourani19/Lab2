#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Task4a Lib.h"

int main() {
    srand(time(NULL));

    int array[MAXSIZE];
    double startTime, endTime;
    int comparisonsCount, swapsCount;

    printf("Array Size\tSelection Sort Time\tMerge Sort Time\tSelection Sort Comparisons\tMerge Sort Comparisons\n");

    for (int k = 1; k < MAXSIZE; k *= 2) {
        initArray(array, k);

        // Selection Sort
        comparisonsCount = 0;
        swapsCount = 0;
        startTime = measureTime(selectionSort, array, 0, MAXSIZE - 1, &comparisonsCount, &swapsCount);
        endTime = measureTime(selectionSort, array, 0, MAXSIZE - 1, &comparisonsCount, &swapsCount);
        printf("%d\t%.6f\t", k, endTime - startTime);

        // Merge Sort
        comparisonsCount = 0;
        swapsCount = 0;
        startTime = measureTime(mergeSort, array, 0, MAXSIZE - 1, &comparisonsCount, &swapsCount);
        endTime = measureTime(mergeSort, array, 0, MAXSIZE - 1, &comparisonsCount, &swapsCount);
        printf("%.6f\t%d\t%d\n", endTime - startTime, comparisonsCount, swapsCount);
    }

    return 0;
}