// Cropped homework code # 4.
#include <cstring>
#include <iostream>

#include "ArrFunc_TS7Template.hpp"
#include "SortingAlgorithmsTemplete.hpp"

enum SortType { ST_BOBLE_SORT, ST_SELECTION_SORT, ST_QUICK_SORT, COUNT_ST };

void (*Sort[COUNT_ST])(float *, float *, Comparison<float>) = {
    BubleSort, SelectSort, Quicksort};
const unsigned k_Name_Length{20};
const char k_MethodName[COUNT_ST][k_Name_Length]{"BOBLESORT", "SELECTION SORT",
                                                 "QUICK SORT"};

int main() {
  std::cout << R"(
    Cropped homework code # 4.
A program for demonstrating some sort algorithms.)"
            << std::endl;

  float SrcArray[k_int_array_size]{};

  std::cout << "Fill in an array of " << k_int_array_size
            << " elements with a random number generator\n"
            << std::endl;
  rundomInitArray(SrcArray, SrcArray + k_int_array_size);
  for (int Method = 0; Method != SortType::COUNT_ST; Method++) {
    const size_t memory_size = sizeof(SrcArray);
    float Victim[k_int_array_size]{};
    memcpy(Victim, SrcArray, memory_size);
    std::cout << "Restore the previous state of the array " << k_int_array_size
              << " elements." << std::endl;

    std::cout << "Launching ";

    const auto more = [](int a, int b) { return a > b; };

    std::cout << k_MethodName[Method] << std::endl;

    (*Sort[Method])(Victim, Victim + k_int_array_size, More<float>);

    ShowArray<float>(Victim, Victim + k_int_array_size);
  }
  return 0;
}