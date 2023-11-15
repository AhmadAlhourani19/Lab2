#include "Task1 Lib.h"

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
    for (int i = MAXSIZE - k; i < MAXSIZE; i++) {
        int randomIndex = i + rand() % (MAXSIZE - i);
        swap(array, i, randomIndex);
    }
}
