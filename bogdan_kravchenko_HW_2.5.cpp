#include <iostream>

int main() {
  std::cout << "This programm can find the best divider. Enter number: ";
  int number;
  std::cin >> number;
  if (number < 0) {
    std::cout << "Error! Enter positive number: ";
    std::cin >> number;
  }
  int sum_best{}, divisor_best{}, divisor{number};
  while (divisor != 0) {
    if (number % divisor == 0) {
      int sum{}, temporary_divisor{divisor};
      while (temporary_divisor != 0) {
        sum += temporary_divisor % 10;
        temporary_divisor /= 10;
      }
      if (sum > sum_best) {
        divisor_best = divisor;
        sum_best = sum;
      }
      std::cout << "Divisor: " << divisor << std::endl;
    }
    divisor--;
  }
  std::cout << "Your best divisor = " << divisor_best << std::endl;
  return 0;
}
