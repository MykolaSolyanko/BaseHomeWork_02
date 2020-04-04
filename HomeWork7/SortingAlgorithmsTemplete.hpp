#pragma once
#include <functional>

// / Sorting function template
template <typename T>
using Comparison = std::function<bool(T, T)>;

template <typename T>
bool More(T a, T b) {
  return a > b;
}

template <typename T>
bool Less(T a, T b) {
  return a < b;
}

template <typename T>
void SwapInt(T &first, T &second) {
  int tmp = first;
  first = second;
  second = tmp;
}

template <typename T>
void BubleSort(T *array_begin, T *const array_end, Comparison<T> comp) {
  if (array_begin == nullptr || array_end == nullptr) {
    return;  // ERROR
  }
  for (T *pass_1 = array_begin; pass_1 != array_end; ++pass_1) {
    for (T *pass_2 = pass_1 + 1; pass_2 != array_end; ++pass_2) {
      if (comp(*pass_1, *pass_2)) SwapInt(*pass_1, *pass_2);
    }
  }
  // OK
}

template <typename T>
void SelectSort(T *array_begin, T *array_end, Comparison<T> comp) {
  if (array_begin == nullptr || array_end == nullptr) {
    return;  // ERROR
  }
  T *remember{nullptr};

  for (T *first_pass = array_begin; first_pass != array_end; first_pass++) {
    remember = first_pass;
    for (T *second_pass = first_pass + 1; second_pass != array_end;
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
template <typename T>
T *Separator(T *opening, T *closing, Comparison<T> comp) {
  T pilot = *closing;
  T *section = opening;
  for (T *index = opening; index != closing; index++) {
    if (comp(*index, pilot) /* *index <= pilot */) {
      SwapInt(*index, *section);
      section++;
    }
  }
  SwapInt(*closing, *section);
  return section;
}
template <typename T>
void Quicksort(T *array_begin, T *array_end, Comparison<T> comp) {
  if (array_begin < array_end) {
    if (array_begin == nullptr || array_end == nullptr) {
      return;  // ERROR
    }
    T *index = Separator(array_begin, array_end, comp);
    Quicksort(array_begin, index - 1, comp);
    Quicksort(index + 1, array_end, comp);
  }
  // OK
}
//  Q U I C K   S O R T   F U N C T I O N S   B L O K   E N D