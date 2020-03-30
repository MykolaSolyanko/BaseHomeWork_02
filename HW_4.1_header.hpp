#pragma once
#include <functional>

using Comparison = std::function<bool(int, int)>;

enum INPUT {
    MANUAL_INPUT = 1,
    RANDOM_INPUT
};

enum SORT {
    BUBBLE_SORT = 1,
    QUICKSORT
};

void Manual_array(int* begin, int* end);
void Random_array(int* begin, int* end);
void Array_result(int* begin, int* end, const size_t kSize);
void Bubble_sort(int* begin, int* end, Comparison comp);
void Quick_sort(int* begin, int* end, Comparison comp);
