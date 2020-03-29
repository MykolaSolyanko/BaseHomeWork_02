// The code snippet is cut from homework #4
#pragma once
#include <fstream>
#include <iostream>
#include <random>
const size_t k_int_array_size{10'000};

static const int k_min_random_value{10};
static const int k_max_random_value{99};

// RANDOM INIT ARRAY
template <typename T>
void rundomInitArray(T *const array_begin, T const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin >= array_end) {
    return;  // error
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> GenRandVal(k_min_random_value,
                                                k_max_random_value);
  for (T *index = array_begin; index != array_end; index++) {
    *index = GenRandVal(mt);
  }
  // ok
}
