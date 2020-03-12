#include <iostream>

void breaking(int value, float &sum, int &digits) {
  while (value != 0) {
    sum += (value % 10);
    value = value / 10;
    digits++;
  }
  std::cout << "Sum of digits: " << sum << std::endl;
  return;
}

void arithmetic(float &arithmetic_mean, float sum, int digits) {
  arithmetic_mean = sum / digits;
  std::cout << "Arithmetic mean: " << arithmetic_mean << std::endl;
  return;
}

int main(int argc, char *argv[]) {
  std::cout << "This program breaks value into digits\n and calculates sum of "
               "digits with their arithmetic_mean\n"
               "Enter value for analize: ";
  int value;
  std::cin >> value;
  float sum{};
  int digits{};
  breaking(value, sum, digits);
  float arithmetic_mean{};
  arithmetic(arithmetic_mean, sum, digits);

  return 0;
}
