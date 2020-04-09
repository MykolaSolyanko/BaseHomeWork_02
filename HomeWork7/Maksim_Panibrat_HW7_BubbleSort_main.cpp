#include "Header.h"

int main() {
  std::cout << "This program bubble sorts array by isung templates.\n"
               "Select number type: \n"
               "\t1 - natural (int, short, long)\n"
               "\t2 - real (float, double)\n"
               "\t3 - letter (char)\n";
  short select;
  std::cin >> select;
  switch (select) {
  case (1):
    std::cout << "You selected natural numbers.\n";
    Create_natural();
    break;
  case (2):
    std::cout << "You selected real numbers.\n";
    Create_real();
    break;
  case (3):
    std::cout << "You selected letters.\n";
    Create_char();
    break;
  default:
    std::cout << "Error, using default-natural selection.\n";
    Create_natural();
    break;
  }
  return 0;
}
