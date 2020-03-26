#pragma once
#include <functional>

enum SortType { ST_BOBLE_SORT, ST_SELECTION_SORT, ST_QUICK_SORT, COUNT_ST };

using Comparison = std::function<bool(int, int)>;

// bool More(int a, int b);
// bool Less(int a, int b);

// void BubleSort(int *const array_begin, int const *const array_end,
//                Comparison comp);
// void SelectSort(int *const array_begin, int const *const array_end,
//                 Comparison comp);
// void Quicksort(int *array_begin, int *array_end, Comparison comp);

//============================join===========================================
// #include "SortingAlgorithms.hpp"

template <typename T>
bool More(T a, T b) {
  return a > b;
}

template <typename T>
bool Less(T a, T b) {
  return a < b;
}

void SwapInt(int &first, int &second) {
  int tmp = first;
  first = second;
  second = tmp;
}

template <typename T>
void BubleSort(T *const array_begin, T const *const array_end,
               Comparison comp) {
  if (array_begin == nullptr || array_end == nullptr) {
    return;  // ERROR
  }
  for (int *pass_1 = array_begin; pass_1 != array_end; ++pass_1) {
    for (int *pass_2 = (array_begin); pass_2 != array_end; ++pass_2) {
      if (comp(*pass_1, *pass_2)) SwapInt(*pass_1, *pass_2);
    }
  }
  // OK
}

void SelectSort(int *const array_begin, int const *const array_end,
                Comparison comp) {
  if (array_begin == nullptr || array_end == nullptr) {
    return;  // ERROR
  }
  int *remember{nullptr};

  for (int *first_pass = array_begin; first_pass != array_end; first_pass++) {
    remember = first_pass;
    for (int *second_pass = first_pass + 1; second_pass != array_end;
         second_pass++)
      remember = (comp(*second_pass, *remember)) ? second_pass : remember;
    if (first_pass != remember) {
      SwapInt(*first_pass, *remember);
    }
  }
  // OK
}

//  Q U I C K   S O R T   F U N C T I O N S   B L O K   B E G I N

// function used in QuickSort
int *Separator(int *opening, int *closing, Comparison comp) {
  int pilot = *closing;
  int *section = opening;
  for (int *index = opening; index != closing; index++) {
    if (comp(*index, pilot) /* *index <= pilot */) {
      SwapInt(*index, *section);
      section++;
    }
  }
  SwapInt(*closing, *section);
  return section;
}
void Quicksort(int *array_begin, int *array_end, Comparison comp) {
  if (array_begin < array_end) {
    if (array_begin == nullptr || array_end == nullptr) {
      return;  // ERROR
    }
    int *index = Separator(array_begin, array_end, comp);
    Quicksort(array_begin, index - 1, comp);
    Quicksort(index + 1, array_end, comp);
  }
  // OK
}
//  Q U I C K   S O R T   F U N C T I O N S   B L O K   E N D