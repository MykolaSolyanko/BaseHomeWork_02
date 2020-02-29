#include <iostream>

int main() {
  std::cout << "This programm finds up best divider\n"
               "Enter number to analize: ";
  int number;
  std::cin >> number;
  if (number < 0) {
    number = -number;
  }
  int best_sum{}, best_divisor{}, divisor{number};
  while (divisor != 0) {
    if (number % divisor == 0) {
      int sum{}, temporary_divisor{divisor};
      while (temporary_divisor != 0) {
        sum += temporary_divisor % 10;
        temporary_divisor /= 10;
      }
      if (sum > best_sum) {
        best_divisor = divisor;
        best_sum = sum;
      }
      std::cout << "Divisor: " << divisor << std::endl;
    }
    --divisor;
  }
  std::cout << "Best divisor = " << best_divisor << std::endl;
  return 0;
}
