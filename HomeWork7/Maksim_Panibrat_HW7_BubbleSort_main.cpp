#include "Header.h"

int main() {
  std::cout << "This program bubble sorts array by isung templates.\n"
               "Select number type: \n"
               "\t1 - whole (int, short, long)\n"
               "\t2 - fractional (float, double)\n"
               "\t3 - letter (char)\n";
  short select;
  std::cin >> select;
  switch (select) {
  case WHOLE:
    std::cout << "You selected whole numbers.\n";
    Create_whole();
    break;
  case FRACTIONAL:
    std::cout << "You selected fractional numbers.\n";
    Create_fractional();
    break;
  case LETTERS:
    std::cout << "You selected letters.\n";
    Create_char();
    break;
  default:
    std::cout << "Error, using default-whole numbers.\n";
    Create_whole();
    break;
  }
  return 0;
}

