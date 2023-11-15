#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 50000

void mergeSort(int array[], int l, int r, int* comparisonsCount, int* swapsCount);
void merge(int array[], int l, int m, int r, int* comparisonsCount, int* swapsCount);
void selectionSort(int arr[], int size);
void swap(int array[], int i, int j);
void initArray(int array[], int k);
double measureTime(void (*sortingFunction)(int[], int, int, int*, int*), int array[], int l, int r, int* comparisonsCount, int* swapsCount);