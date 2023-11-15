#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Task1 Lib.h"

int main() {
    int array[MAXSIZE];
    int k = 5; // You can change k to any value

    initArray(array, k);

    // Print the initialized array
    for (int i = 0; i < MAXSIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}