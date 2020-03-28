#pragma once
#include <functional>
using IntCompare = std::function<bool(int, int)>;
void BubbleSortArray(int* array, int size, IntCompare compare);
void BubbleSortTime(int* array, int size, IntCompare compare);
void swap(int& a, int& b);
void QuickSortArray(int* array, int low, int high, IntCompare compare);
void QuickSortTime(int* array, int low, int high, IntCompare compare);
void CreateRandomIntArray(int* array, const int size);
void CreateManualIntArray(int* array, const int size);
void PrintArray(int* array, const int size);
void CreateIntArray(int* array, int size);
bool to_bigger(int a, int b);
bool to_smaller(int a, int b);
void SortArray(int* array, int size);
