#include "Header.hpp"
#include <iostream>

const size_t ksize = 100;
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
      char *array = alloc_char_array(ksize);
      fill_char_array(array, ksize);
      size_t asize = length_char_array(array);
      bool eow{true};
      do {
        std::cout << "Please, choose function to work with char array:"
                  << std::endl;
        std::cout << "1 print REVERSE char array;" << std::endl;
        std::cout << "2 print UPPERCASE char array;" << std::endl;
        std::cout << "3 print LOWERCASE char array;" << std::endl;
        std::cout << "4 print Try IS_DIGIT in char array;" << std::endl;
        std::cout << "0 press to finish work with char array." << std::endl;
        int choise1;
        std::cin >> choise1;

        switch (choise1) {
        case CHAR_ARR_OPTIONS::CHAR_ARR_REVERSE:
          CharArrayReverse(array, asize);
          PrintCharArray(array, asize);
          break;
        case CHAR_ARR_OPTIONS::CHAR_ARR_UPC:
          PrintUpperCaseCharArray(array, asize);
          break;
        case CHAR_ARR_OPTIONS::CHAR_ARR_LWC:
          PrintLowerCaseCharArray(array, asize);
          break;
        case CHAR_ARR_OPTIONS::CHAR_ARR_IS_DIGIT:
          print_is_digit(array, asize);
          break;
        default:
          std::cout << "End of work with char array" << std::endl;
          eow = false;
        }
      } while (eow);
      delete[] array;
      break;
    }
    case ARR_TYPE::INT_ARR: {
      bool eow{true};
      do {
        std::cout << "Please, choose function to work with int array:"
                  << std::endl;
        std::cout << "1 create and add elements to sorted int array;"
                  << std::endl;
        std::cout << "2 delete elements from int array;" << std::endl;
        std::cout << "0 Press to finish work with int array" << std::endl;
        int choise2;
        std::cin >> choise2;
        int *int_arr = new int[ksize]{};
        std::cout << "Enter the size of array with max " << ksize
                  << " elements." << std::endl;
        int user_arr_size;
        std::cin >> user_arr_size;
        switch (choise2) {
        case INT_ARR_OPTIONS::INT_ARR_ADD: {
          FillAndSortIntArray(int_arr, user_arr_size);
          break;
        }
        case INT_ARR_OPTIONS::INT_ARR_DELETE: {
          FillingIntArray(int_arr, user_arr_size);
          PrintIntArray(int_arr, user_arr_size);
          DeleteElemArray(int_arr, user_arr_size);
          PrintIntArray(int_arr, user_arr_size);
        }
        default:
          std::cout << " End of work with int array" << std::endl;
          eow = false;
        }
        delete[] int_arr;
      } while (eow);
      break;
    }
    default:
      std::cout << " End of Program " << std::endl;
      return 0;
    }

  } while (true);
  return 0;
}
