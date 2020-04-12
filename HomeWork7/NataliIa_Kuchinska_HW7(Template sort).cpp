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
      RandArrSort<int>();
      break;
    }
    case ARRAY_TYPE::DOUBLE: {
      RandArrSort<double>();
      break;
    }
    case ARRAY_TYPE::CHAR: {
      RandArrSort<char>();
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
