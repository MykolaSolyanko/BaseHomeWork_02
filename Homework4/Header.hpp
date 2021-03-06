
#pragma once
using IntCompare = std::function<bool(int, int)>;
using DoubleCompare = std::function<bool(double, double)>;
using CharCompare = std::function<bool(char, char)>;
char *AllocCharArray(size_t kSize);
void DeleteAllocCharArray(char *array);
size_t LengthCharArray(char *array);
void CreateRandArray(char *array, const int size);
void CreateRandArray(int *array, const int size);
void CreateRandArray(double *array, const int size);
void CreateCustomArray(int *array, const int size);
void CreateCustomArray(double *array, const int size);
void PrintArray(int *array, const int size);
void PrintArray(double *array, const int size);
void PrintArray(char *array, const int size);
void swap(int &a, int &b);
void swap(double &a, double &b);
void swap(char &a, char &b);
bool more(int a, int b);
bool more(double a, double b);
bool more(char a, char b);
bool less(int a, int b);
bool less(double a, double b);
bool less(char a, char b);
void BubbleSort(int *array, int size, IntCompare compare);
void BubbleSort(double *array, int size, DoubleCompare compare);
void BubbleSort(char *array, int size, CharCompare compare);
void BubbleSortTime(int *array, int size, IntCompare compare);
void BubbleSortTime(double *array, int size, DoubleCompare compare);
void BubbleSortTime(char *array, int size, CharCompare compare);
void QuickSort(int *array, int low, int high, IntCompare compare);
void QuickSort(double *array, int low, int high, DoubleCompare compare);
void QuickSort(char *array, int low, int high, CharCompare compare);
void QuickSortTime(int *array, int low, int high, IntCompare compare);
void QuickSortTime(double *array, int low, int high, DoubleCompare compare);
void CreateIntArray(int *array, int size);
void SortArray(int *array, int size);
void CreateDoubleArray(double *array, int size);
void SortDoubleArray(double *array, int size);
std::pair<char *, int> CreateCharArray();
void SortCharArray(char *array, int size);
