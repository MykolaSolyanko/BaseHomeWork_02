#include <iostream>

int main() {
  std::cout << "This program turns number in reverse.\n";
  std::cout << "Enter number to reverse it\n";
  int number;
  std::cin >> number;
  int reverse_number{0};
  if (number < 10) {
    std::cout << "There is no need to reverse.\n Reverse number: " << number
              << std::endl;
    return 0;
  }
  do {
    reverse_number *= 10;
    reverse_number += number % 10;
    number /= 10;
  } while (number != 0);

  std::cout << "Reverse number: " << reverse_number << "\n";
  return 0;
}

