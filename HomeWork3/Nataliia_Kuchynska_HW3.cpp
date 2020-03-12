#include "Header.hpp"
#include <iostream>
#include <random>

const int ksize = 100;
enum ARR_TYPE { CHAR_ARR = 1, INT_ARR };
enum CHAR_ARR_OPTIONS {
  CHAR_ARR_REVERSE = 1,
  CHAR_ARR_UPC,
  CHAR_ARR_LWC,
  CHAR_ARR_IS_DIGIT
};
enum INT_ARR_OPTIONS { INT_ARR_ADD = 1, INT_ARR_DELETE };

int main() {
  do {
    std::cout << "Please, choose type of array:\n 1 char array;\n 2 int array"
              << std::endl;
    std::cout << " Press any other key to exit from this program." << std::endl;
    int choise;
    std::cin >> choise;
    switch (choise) {
    case ARR_TYPE::CHAR_ARR: {
      char *array = cin_char_array(ksize);
      int asize = sizeof_char_array(array);
      do {
        std::cout << "Please, choose function to work with char array:"
                  << std::endl;
        std::cout << "1 print REVERSE char array;" << std::endl;
        std::cout << "2 print UPPERCASE char array;" << std::endl;
        std::cout << "3 print LOWERCASE char array;" << std::endl;
        std::cout << "4 print Try IS_DIGIT in char array;" << std::endl;
        std::cout << " Press any other key to exit from this program."
                  << std::endl;
        int choise1;
        std::cin >> choise1;
        switch (choise1) {
        case CHAR_ARR_OPTIONS::CHAR_ARR_REVERSE:
          PrintCharArrayReverse(array, asize);
          break;
        case CHAR_ARR_OPTIONS::CHAR_ARR_UPC:
          PrintUpperCaseCharArray(array, asize);
          break;
        case CHAR_ARR_OPTIONS::CHAR_ARR_LWC:
          PrintLowerCaseCharArray(array, asize);
          break;
        case CHAR_ARR_OPTIONS::CHAR_ARR_IS_DIGIT:
          is_digit(array, asize);
          break;
        default:
          std::cout << " End of work with array" << std::endl;
          return false;
        }
      } while (true);
      delete[] array;
      break;
    }
    case ARR_TYPE::INT_ARR: {
      do {
        std::cout << "Please, choose function to work with int array:"
                  << std::endl;
        std::cout << "1 create and add elements to sorted int array;"
                  << std::endl;
        std::cout << "2 delete elements from int array;" << std::endl;
        std::cout << " Press any other key to exit from this program."
                  << std::endl;
        int choise2;
        std::cin >> choise2;
        int *int_arr = new int[ksize]{};
        switch (choise2) {
        case INT_ARR_OPTIONS::INT_ARR_ADD: {
          std::cout << "Enter the size of array with max " << ksize
                    << " elements." << std::endl;
          int user_arr_size;
          std::cin >> user_arr_size;
          int i{};
          char answer;
          while (i < user_arr_size) {
            std::cout
                << "Enter the " << i + 1
                << " th element of array of numbers integer (from 0 to 1024 ) "
                << std::endl;
            std::cin >> int_arr[i];
            ++i;
            PartialSortElemArray(int_arr, i);
            PrintIntArray(int_arr, user_arr_size);
            std::cout << "To continue press 1 otherwise press any key to break."
                      << std::endl;
            std::cin >> answer;
            if (answer != '1') {
              break;
            }
          };
          break;
        }
        case INT_ARR_OPTIONS::INT_ARR_DELETE: {

          std::cout << "To create integer array, choose one of the function:"
                    << std::endl;
          std::cout << "1 use template array (integer numbers from 1 to 100);"
                    << std::endl;
          std::cout << "2 create random array;" << std::endl;
          std::cout << "3 create user array;" << std::endl;
          int answer;
          std::cin >> answer;
          std::cout << "Enter the size of array with max " << ksize
                    << " elements." << std::endl;
          int user_arr_size;
          std::cin >> user_arr_size;

          switch (answer) {
          case 1: {
            for (int i{0}; i < 100; ++i) {
              int_arr[i] = {i + 1};
            }
            break;
          }
          case 2: {
            std::uniform_int_distribution<> d(1, 1024);
            std::mt19937 gen;
            for (int i{1}; i < 101; ++i) {
              int_arr[i] = {d(gen)};
            }
            break;
          }
          case 3: {
            int i{};
            while (i < user_arr_size) {
              std::cout << "Enter the " << i + 1
                        << " th element of array of numbers integer (from 0 to "
                           "1024 ) "
                        << std::endl;
              std::cin >> int_arr[i];
              ++i;
              break;
            }
            break;
          }
          default:
            std::cout << "Incorrect choise. Exit" << std::endl;
            break;
          }
          PrintIntArray(int_arr, user_arr_size);
          std::cout
              << "Enter the integer number to delete in array (from 0 to 1024)"
              << std::endl;
          int delete_num, count{};
          std::cin >> delete_num;
          for (int i{1}; i < user_arr_size; ++i) {
            if (int_arr[i] == delete_num) {
              int_arr[i] = int_arr[user_arr_size - 1];
              --user_arr_size;
              std::cout << " Number " << delete_num << " is deleted. "
                        << std::endl;
            } else {
              ++count;
            };
            if (--user_arr_size == count) {
              std::cout << " No number " << delete_num << " in the array. "
                        << std::endl;
            }
          }
        }
        default:
          std::cout << " End of work with int array" << std::endl;
          return 0;
        }

      } while (true);

      break;
    }
    default:
      std::cout << " End of Program " << std::endl;
      return 0;
    }

  } while (true);
  return 0;
}
