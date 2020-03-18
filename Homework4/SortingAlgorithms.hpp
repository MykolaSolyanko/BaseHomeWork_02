#pragma once
#include <functional>

enum SortType { ST_BOBLE_SORT, ST_SELECTION_SORT, ST_QUICK_SORT, COUNT_ST };
using Comparison = std::function<bool(int, int)>;
void BubleSort(int *const array_begin, int const *const array_end,
               Comparison comp);
void SelectSort(int *const array_begin, int const *const array_end,
                Comparison comp);
void Quicksort(int *array_begin, int *array_end, Comparison comp)