#include <iostream>

int main() {
  std::cout << "This program breaks a number into digits and displays a sum of "
               "those digits with their arithmetic mean.\n";
  std::cout << "Enter number\n";
  int num;
  std::cin >> num;
  while (num == 0) {
    std::cout << "Out of range. Try again\n";
    std::cin >> num;
  }
  float sum = 0;
  int digits = 0;
  while (num) {
    sum += (num % 10);
    num /= 10;
    digits++;
  }
  std::cout << "Sum of digits = " << sum << std::endl;
  float ar_m = sum / digits;
  std::cout << "Arithmetic mean = " << ar_m << std::endl;
  return 0;
}
