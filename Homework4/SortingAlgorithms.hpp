#pragma once
#include <functional>

using Comparison = std::function<bool(int, int)>;

bool More(int a, int b);
bool Less(int a, int b);

void BubleSort(int *array_begin, int *array_end, Comparison comp);
void SelectSort(int *array_begin, int *array_end, Comparison comp);
void Quicksort(int *array_begin, int *array_end, Comparison comp);