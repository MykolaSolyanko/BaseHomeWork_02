// Reverse.cpp

#include <iostream>

int main() {

  std::cout << "Enter number to reverse: \n";
  int32_t number;
  std::cin >> number;
  int reverse_number{0};
  if (number < 10) {
    std::cout << "This number is no reverse" << std::endl;
    return 0;
  }
  do {
    reverse_number *= 10;
    reverse_number += number % 10;
    number /= 10;
  } while (number != 0);
  std::cout << "Reverse number is: " << reverse_number << std::endl;
  return 0;
}
