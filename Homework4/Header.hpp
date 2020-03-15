#pragma once
char *AllocCharArray(size_t kSize);
size_t LengthCharArray(char *array);
void CreateRandArray(char *array, const int size);
void CreateRandArray(int *array, const int size);
void CreateRandArray(double *array, const int size);
void CreateCustomArray(int *array, const int size);
void CreateCustomArray(double *array, const int size);
void PrintArray(int *array, const int size);
void PrintArray(double *array, const int size);
void PrintArray(char *array, const int size);
void swap(int *a, int *b);
void swap(double *a, double *b);
void swap(char *a, char *b);
// std::function<bool(int, int)>  more(int a, int b);
// std::function<bool(double, double)> more(double a, double b);
// std::function<bool(char, char)> more(char a, char b);
// std::function<bool(int, int)> less(int a, int b);
// std::function<bool(double, double)> less(double a, double b);
// std::function<bool(char, char)>  less(char a, char b);
void BubbleSort(int *array, int size, std::function<bool(int, int)> compare);
void BubbleSort(double *array, int size,
                std::function<bool(double, double)> compare);
void BubbleSort(char *array, int size, std::function<bool(char, char)> compare);
void QuickSort(int *array, int low, int high,
               std::function<bool(int, int)> compare);
void QuickSort(double *array, int low, int high,
               std::function<bool(double, double)> compare);
void QuickSort(char *array, int low, int high,
               std::function<bool(char, char)> compare);
void QuickSortTime(int *array, int low, int high,
                   std::function<bool(int, int)> compare);
void QuickSortTime(double *array, int low, int high,
                   std::function<bool(double, double)> compare);
