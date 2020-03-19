// arithmetic mean.cpp

#include <iostream>

int main() {
  std::cout << "Enter the number of items, and Press Enter " << std::endl;
  int number{0};
  std::cin >> number;
  while (number == 0) {
    std::cout << "Enter number different than 0 \n";
    std::cin >> number;
  }
  double sum{0};
  int digits{0};
  while (number > 0) {
    sum += (number % 10);
    number /= 10;
    digits++;
  }
  std::cout << "Sum of digits = " << sum << std::endl;
  double arithmetic_mean = sum / digits;
  std::cout << "Arithmetic mean is = " << arithmetic_mean << std::endl;
  return 0;
}
