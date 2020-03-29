// Cropped homework code # 4.
#include <cstring>
#include <iostream>

#include "ArrFunc_TS7Template.hpp"
#include "SortingAlgorithmsTemplete.hpp"

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

    switch (Method) {
      //
      case SortType::ST_BOBLE_SORT:
        std::cout << "BOBLESORT" << std::endl;
        BubleSort<float>(Victim, Victim + k_int_array_size, More<float>);
        break;
        //
      case SortType::ST_SELECTION_SORT:
        std::cout << "SELECTION SORT" << std::endl;
        SelectSort<float>(Victim, Victim + k_int_array_size, More<float>);
        break;
        //
      case SortType::ST_QUICK_SORT:
        std::cout << "QUICK SORT" << std::endl;
        Quicksort<float>(Victim, Victim + k_int_array_size, More<float>);
        break;
        //
      default:
        break;
    }
  }
  return 0;
}