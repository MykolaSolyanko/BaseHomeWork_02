#include <iostream>

int main() {

  int number;

  std::cout << "Please, enter any number\n" << std::endl;
  std::cout << "This is arithmetic mean of your digits number" << std::endl;
  std::cin >> number;

  int sum = 0;
  size_t count = 0;

  if (number == 0) {
    std::cout << "Error! Enter number more then zero!" << std::endl;
    return 1;
  }
    while (number != 0) {
      sum += number % 10;
      number /= 10;
      count++;
    }

    auto arithmetic_mean = static_cast<double>(sum) / count;
    std::cout << "The sum of digits your number is " << sum << std::endl;
    std::cout << "The arithmetic mean of digits your number is "
              << arithmetic_mean << std::endl;


  return 0;
}
