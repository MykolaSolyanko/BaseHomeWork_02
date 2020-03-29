#include <iostream>

enum NUMBERS { UPPERCASE = 1, IS_DIGIT, LOWERCASE };

void upper_case() {
  const size_t kSize = 15;
  std::cout << "This programm transforms string to uppercase.\n"
               "Enter string for analize, in range of "
            << kSize << " symbols: ";
  char array[kSize]{};
  std::cin >> array;
  char *begin = array, *end = begin + kSize - 1;
  while (begin != end) {
    if (*begin >= 'a') {
      *begin = *begin - 32;
    }
    ++begin;
  }
  std::cout << "Result: " << array << std::endl;
}

void lower_case() {
  const size_t kSize = 15;
  std::cout << "This programm transforms string to lowercase.\n"
               "Enter string for analize, in range of "
            << kSize << " symbols: ";
  char array[kSize]{};
  std::cin >> array;
  char *begin = array, *end = begin + kSize - 1;
  while (begin != end) {
    if (*begin >= 'A' && *begin <= 'Z') {
      *begin = *begin + 32;
    }
    ++begin;
  }
  std::cout << "Result: " << array << std::endl;
}

void is_digit() {
  const size_t kSize = 15;
  std::cout << "This programm finds digits in string.\n"
               "Enter string for analize, in range of "
            << kSize << " symbols: ";
  char array[kSize]{};
  std::cin >> array;
  char *begin = array, *end = begin + kSize - 1;
  std::cout << "Found digits: ";
  while (begin != end) {
    if (*begin >= '0' && *begin <= '9') {
      std::cout << *begin << " ";
    }
    ++begin;
  }
}

int main() {
  std::cout << "Program list:\n"
               "1: Transform string to upper case.\n"
               "2: Find digits in string.\n"
               "3: Transform string to lower case.\n"
               "Choice program for implementation: ";
  int choice;
  while (!(std::cin >> choice)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Error, not number\n";
  }
  switch (choice) {
  case UPPERCASE:
    upper_case();
    break;
  case IS_DIGIT:
    is_digit();
    break;
  case LOWERCASE:
    lower_case();
    break;
  default:
    std::cout << "End of program.";
  }
  return 0;
}

