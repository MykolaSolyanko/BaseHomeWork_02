#include <iostream>
#include <random>

enum ARRAY_FILLING { DEFAULT = 1, RANDOM, CUSTOM };
char *alloc_char_array(size_t kSize) {
  char *array = new char[kSize];

  return array;
}
void fill_char_array(char *array, size_t kSize) {
  std::cout << "Please, enter char string with max " << kSize << " elements"
            << std::endl;
  std::cin >> array;
}
size_t length_char_array(char *array) {
  if (array == nullptr) {
    return 0;
  };
  size_t arr_size{0};
  while (array[arr_size] != '\0') {
    ++arr_size;
  }
  return arr_size;
}
void CharArrayReverse(char *array, int size) {
  if (array == nullptr) {
    return;
  };
  if (size != 0) {
    int half_size = size / 2;
    for (int i{0}; i < half_size; ++i) {
      int tmp{array[size - 1 - i]};
      array[size - 1 - i] = array[i];
      array[i] = tmp;
    }
  } else {
    std::cout << "Array is empty." << std::endl;
  }
}
void PrintCharArray(char *array, int size) {
  if (array == nullptr && size == 0) {
    std::cout << "Array is empty." << std::endl;
    return;
  };

  for (int i{0}; i < size; ++i) {
    std::cout << array[i];
  }
  std::cout << std::endl;
}
void PrintUpperCaseCharArray(char *array, int size) {
  if (array == nullptr) {
    return;
  }
  if (size != 0) {
    for (int i{0}; i < size; ++i) {
      if (array[i] >= 'a' && array[i] <= 'z') {
        std::cout << static_cast<char>(array[i] - 32);
      } else {
        std::cout << array[i];
      }
    }
    std::cout << std::endl;
  } else {
    std::cout << "Array is empty." << std::endl;
  }
}
void PrintLowerCaseCharArray(char *array, int size) {
  if (array == nullptr && size == 0) {
    std::cout << "Array is empty." << std::endl;
    return;
  }

  for (int i{0}; i < size; ++i) {
    if (array[i] >= 'A' && array[i] <= 'Z') {
      std::cout << static_cast<char>(array[i] + 32);
    } else {
      std::cout << array[i];
    }
  }
  std::cout << std::endl;
}
void print_is_digit(char *array, int size) {
  if (array == nullptr && size <= 0) {
    std::cout << "Array is empty." << std::endl;
    return;
  }
  bool digit_found{false};
  size_t iter{};
  while (array[iter] != '\0') {
    if (array[iter] >= '0' && array[iter] <= '9') {
      digit_found = true;
      break;
    }
    ++iter;
  }
  if (digit_found == true) {
    char *dig_array = new char[size];
    size_t iter{};
    for (int i{0}; i < size; ++i) {
      if (array[i] >= '0' && array[i] <= '9') {
        dig_array[iter++] = array[i];
      }
    }
    std::cout << "is_digit: ";
    size_t digit_iter{};
    while (digit_iter < iter) {
      std::cout << dig_array[digit_iter++] << " ";
    }
    delete[] dig_array;
  } else {
    std::cout << "No digits  in the string";
  }
  std::cout << std::endl;
}
void PartialSortElemArray(int *array, int size) {
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}
void PrintIntArray(int *array, int size) {
  for (int i{}; i < size; ++i) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}
void FillAndSortIntArray(int *array, int size) {
  int i{};

  while (i < size) {
    std::cout << "Enter the " << i + 1
              << " th element of array of numbers integer (from 0 to 100 ) "
              << std::endl;
    std::cin >> array[i++];
    PartialSortElemArray(array, i);
    PrintIntArray(array, size);
    std::cout << "To continue press y otherwise press any key to break."
              << std::endl;
    char answer{};
    std::cin >> answer;
    if (answer != 'y') {
      break;
    }
  };
}
void FillIntArrDefault(int *array, int size) {
  for (int i{0}; i < size; ++i) {
    *(array + i) = {i + 1};
  }
}
void FillIntArrRandom(int *array, int size) {
  std::random_device rd;
  std::uniform_int_distribution<> d(1, size);
  std::mt19937 gen{rd()};
  for (int i{}; i < size; ++i) {
    *(array + i) = {d(gen)};
  }
}
void FillIntArrCustom(int *array, int size) {

  for (int i{}; i < size; ++i) {
    std::cout << "Enter the " << i + 1
              << " th element of array of numbers integer (from 0 to 100 ) "
              << std::endl;
    std::cin >> array[i];
  }
}
void FillingIntArray(int *array, int size) {
  std::cout << "To create integer array, choose one of the function:"
            << std::endl;
  std::cout << "1 use template array (integer numbers from 1 to 100);"
            << std::endl;
  std::cout << "2 create random array;" << std::endl;
  std::cout << "3 create user array;" << std::endl;
  int answer;
  std::cin >> answer;

  switch (answer) {
  case ARRAY_FILLING::DEFAULT: {
    FillIntArrDefault(array, size);
    break;
  }
  case ARRAY_FILLING::RANDOM: {
    FillIntArrRandom(array, size);
    break;
  }
  case ARRAY_FILLING::CUSTOM: {
    FillIntArrCustom(array, size);
    break;
  }
  default:
    std::cout << "Incorrect choise. Exit" << std::endl;
    break;
  }
}
void DeleteElemArray(int *array, int &size) {
  std::cout << "Enter the integer number to delete in array (from 0 to 1024)"
            << std::endl;
  int delete_num, count{};
  std::cin >> delete_num;
  bool digit_found{false};
  int iter{};
  while (iter < size) {
    if (array[iter] == delete_num) {
      digit_found = true;
      break;
    }
    ++iter;
  }
  if (digit_found) {

    int new_size{};
    for (int i{0}; i < size; ++i) {
      if (array[i] != delete_num) {
        array[new_size++] = array[i];
      }
    }
    size = new_size;
    std::cout << " Number " << delete_num << " deleted from array. "
              << std::endl;
  } else {
    std::cout << " No number " << delete_num << " in the array. " << std::endl;
  };
}
