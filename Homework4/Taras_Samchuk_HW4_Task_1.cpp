#include <chrono>
#include <cstring>
#include <iostream>

#include "ArrFunc_TS6.hpp"
#include "SortingAlgorithms.hpp"

using SysTimePoint = std::chrono::time_point<std::chrono::system_clock>;
using SysTimeDuration = std::chrono::duration<double>;

enum TypeInit { TI_RAND = 1, TI_USER };

int main() {
  std::cout << R"(
A program for demonstrating the speed of some algorithms.
Choose the method of initiation
  1 Automatic (random number generator)
  2 The numbers are downloaded from the file 
)" << k_file_name
            << R"(

Enter a method)"
            << std::endl;

  short choise;
  std::cin >> choise;

  int SrcArray[k_int_array_size]{};
  switch (choise) {
    case TI_RAND:
      std::cout << "Fill in an array of " << k_int_array_size
                << " elements with a random number generator\n"
                << std::endl;
      rInitArray(SrcArray, SrcArray + k_int_array_size);
      break;
    case TI_USER:
      std::cout << R"(
  Filling an array from a file. In the absence of data
in the file, the data array is filled with empty values.
When filling the array, the remaining data from the file
is ignored.)" << std::endl;
      fInitArray(SrcArray, SrcArray + k_int_array_size);
      break;
    default:
      std::cout << "Unknown choice.The program cannot be executed" << std::endl;
      return 0;
  }
  // todo
  for (int Method = 0; Method < COUNT_ST; Method++) {
    const size_t memory_size = sizeof(SrcArray);
    int Victim[k_int_array_size]{};
    memcpy(Victim, SrcArray, memory_size);
    std::cout << "Restore the previous state of the array " << k_int_array_size
              << " elements." << std::endl;

    std::cout << "Launching ";

    auto more = [](int a, int b) { return a > b; };
    SysTimePoint BeginAt{};
    SysTimePoint FinishAt{};
    SysTimeDuration TimeІpent{};
    switch (Method) {
      //
      case SortType::ST_BOBLE_SORT:
        std::cout << "BOBLESORT" << std::endl;
        BeginAt = std::chrono::system_clock::now();
        BubleSort(Victim, Victim + k_int_array_size, more);
        FinishAt = std::chrono::system_clock::now();
        break;
        //
      case SortType::ST_SELECTION_SORT:
        std::cout << "SELECTION SORT" << std::endl;
        BeginAt = std::chrono::system_clock::now();
        SelectSort(Victim, Victim + k_int_array_size, more);
        FinishAt = std::chrono::system_clock::now();
        break;
        //
      case SortType::ST_QUICK_SORT:
        std::cout << "QUICK SORT" << std::endl;
        BeginAt = std::chrono::system_clock::now();
        Quicksort(Victim, Victim + k_int_array_size, more);
        FinishAt = std::chrono::system_clock::now();
        break;
        //
      default:
        break;
    }
    TimeІpent = FinishAt - BeginAt;
    std::cout << "Elapsed time: " << TimeІpent.count() << "s" << std::endl;
  }
  return 0;
}