#include "Header.hpp"
#include <functional>
#include <iostream>
#include <random>

const int kSize = 10000;
enum ARRAY_TYPE { INT = 1, DOUBLE, CHAR, EXIT };
int main() {
  int choise;
  do {
    std::cout << "Please, choose the type of elements of array to demonstrate "
                 "template functions:"
              << std::endl;
    std::cout << "1 integer;" << std::endl;
    std::cout << "2 double;" << std::endl;
    std::cout << "3 char." << std::endl;
    std::cout << "4 EXIT." << std::endl;
    std::cin >> choise;
    switch (choise) {
    case ARRAY_TYPE::INT: {
      std::cout << "Please, choose the size of array (from 1 to 10 000)"
                << std::endl;
      int int_arr_size{};
      std::cin >> int_arr_size;
      int *int_arr = new int[int_arr_size]{};
      if (int_arr_size <= kSize && int_arr_size > 0) {
        CreateIntRandArray(int_arr, int_arr_size);
        PrintArray(int_arr, int_arr_size);
        BubbleSort(int_arr, int_arr_size, [](int a, int b) { return (a < b); });
        PrintArray(int_arr, int_arr_size);
      }
      delete[] int_arr;
      break;
    }
    case ARRAY_TYPE::DOUBLE: {
      std::cout << "Please, choose the size of array (from 1 to 10 000)"
                << std::endl;
      int double_arr_size{};
      std::cin >> double_arr_size;
      double *d_arr = new double[double_arr_size]{};
      if (double_arr_size <= kSize && double_arr_size > 0) {
        CreateDoubleRandArray(d_arr, double_arr_size);
        PrintArray(d_arr, double_arr_size);
        BubbleSort(d_arr, double_arr_size,
                   [](int a, int b) { return (a < b); });
        PrintArray(d_arr, double_arr_size);
      }
      delete[] d_arr;
      break;
    }
    case ARRAY_TYPE::CHAR: {
      std::cout << "Please, choose the size of array (from 1 to 10 000)"
                << std::endl;
      int c_arr_size{};
      std::cin >> c_arr_size;
      char *c_arr = new char[c_arr_size]{};
      if (c_arr_size <= kSize && c_arr_size > 0) {
        CreateCharRandArray(c_arr, c_arr_size);
        PrintArray(c_arr, c_arr_size);
        BubbleSort(c_arr, c_arr_size, [](int a, int b) { return (a < b); });
        PrintArray(c_arr, c_arr_size);
      }

      delete[] c_arr;
      break;
    }
    case ARRAY_TYPE::EXIT: {
      return 0;
    }
    default:
      break;
    }
  } while (true);

  return 0;
}
