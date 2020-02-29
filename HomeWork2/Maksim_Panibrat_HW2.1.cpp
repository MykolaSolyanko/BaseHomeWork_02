#include <iostream>

int main() {
  std::cout << "This program breaks a number into digits and displays a sum of "
               "those digits with their arithmetic mean.\n";
  std::cout << "Enter number\n";
  int number;
  std::cin >> number;
  while (number == 0) {
    std::cout << "Enter more than 0\n";
    std::cin >> number;
  }
  float sum = 0;
  int digits {0};
  while (number>0) {
    sum += (number % 10);
    number /= 10;
    digits++;
  }
  std::cout << "Sum of digits = " << sum << std::endl;
  float arithmetic_mean = sum / digits;
  std::cout << "Arithmetic mean = " << arithmetic_mean << std::endl;
  return 0;
}
