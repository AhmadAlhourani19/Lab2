#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 20


void mergesort(int array[], int l, int r, int* comparisonsCount, int* swapsCount);
void merge(int array[], int l, int m, int r, int* comparisonsCount, int* swapsCount);
void mergesortBU(int array[], int arraySize, int* comparisonsCount, int* swapsCount);
void mergeBU(int array[], int l, int m, int r, int* comparisonsCount, int* swapsCount);
void quicksort(int array[], int l, int r, int* comparisonsCount, int* swapsCount);
int partition(int array[], int l, int r, int* comparisonsCount, int* swapsCount);
int less(int i, int j);
void printArray(int array[]);
void swap(int array[], int i, int j);
void insertionSort(int array[]);
void selectionSort(int arr[], int size);
void shellSort(int arr[], int size);
int minimum(int x, int y);
