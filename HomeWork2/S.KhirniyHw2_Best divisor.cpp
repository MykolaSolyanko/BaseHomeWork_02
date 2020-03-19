// Best divisor.

#include <iostream>

int main() {

  std::cout << "Enter number to search best divisor " << std::endl;

  int n;
  std::cin >> n;
  if (n < 0) {
    n = -n;
  }
  int best_sum{}, best_divisor{}, divisor{n};
  while (divisor != 0) {
    if (n % divisor == 0) {
      int sum{}, temp_divisor{divisor};
      while (temp_divisor != 0) {
        sum += temp_divisor % 10;
        temp_divisor /= 10;
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
}
