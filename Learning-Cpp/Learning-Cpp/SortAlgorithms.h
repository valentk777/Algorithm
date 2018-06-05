#pragma once
extern void Replace (int& i, int& j);
extern void PrintAll (int *buff, int count);
extern void SelectionSort (int *buff, int count);
extern void InsertionSort (int *buff, int count);
extern void BoubleSort (int *buff, int count);
extern void BoubleSortOptimized (int *buff, int count);
extern void MergeSort (int *buff, int count);
extern void Merge (int* source, int* destination, int count, int currentCount);
extern int Partition (int* arr, int from, int to);
extern void QS (int* arr, int from, int to);
extern void QuickSort (int* arr, int count);
extern int* Partition_P (int* arr, int* from, int* to);
extern void QS_P (int* arr, int* from, int* to);
extern void QuickSort_P (int* arr, int count);