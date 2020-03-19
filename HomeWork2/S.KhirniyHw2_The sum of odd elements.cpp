// The sum of odd elements.cpp

#include <iostream>

int main() {
  const int kMinNumber = 1, kMaxNumber = 50;
  std::cout << "Enter number of range [" << kMinNumber << "..." << kMaxNumber
            << "]\n";
  int number{};
  std::cin >> number;
  if (number < kMinNumber || number > kMaxNumber) {
    std::cout << "Input number is out of range \n";
    std::cin >> number;
  }
  const int kMinValue = -60, kMaxValue = 90;
  std::cout << "Enter numbers in range [" << kMinValue << "..." << kMaxValue
            << "] \n";
  size_t sum{}, iter{1};
  while (iter <= number) {
    int value;
    std::cin >> value;
    if (value < kMinValue || value > kMaxValue) {
      std::cout << "Value is out of range, enter again \n";
      continue;
    }
    if (value % 2) {
      sum += value;
    }
    ++iter;
  }
  std::cout << "The sum of odd elements = " << sum << std::endl;
  return 0;
}
