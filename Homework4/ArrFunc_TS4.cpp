#include "ArrFunc_TS4.hpp"

#include <fstream>
#include <iostream>
#include <random>

static const int k_min_random_value{10};
static const int k_max_random_value{99};

// RANDOM INIT ARRAY
void rundomInitArray(int *const array_begin, int const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin >= array_end) {
    return;  // error
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> GenInt(k_min_random_value,
                                            k_max_random_value);
  for (int *index = array_begin; index != array_end; index++) {
    *index = GenInt(mt);
  }
  // ok
}

void fileInitArray(int *const array_begin, int const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin >= array_end) {
    return;  // error
  }
  std::ifstream InitFile{k_file_name};
  if (InitFile.is_open()) {
    int *read = array_begin;
    while (!InitFile.eof() && !(read == array_end)) {
      InitFile >> *read++;
    }
    return;
  }
  std::cout << "File not found" << std::endl;
}

// USER INIT ARRAY
void userInitArray(int *const array_begin, int const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin >= array_end) {
    return;  // error
  }
  std::cout << "Start initiating an array" << std::endl;
  for (int *index = array_begin; index != array_end; index++) {
    std::cout << "Enter int value=";
    std::cin >> *index;
  }
  std::cout << "Array initiation complete" << std::endl;
  // ok
}

// SHOW ARRAY
void ShowArray(int *const array_begin, int const *const array_end) {
  if (array_begin == nullptr || array_end == nullptr ||
      array_begin > array_end) {
    return;  // error
  }
  for (int *index = array_begin; index != array_end; index++) {
    std::cout << '{' << *index << '}';
  }
  std::cout << std::endl;
  // ok
}