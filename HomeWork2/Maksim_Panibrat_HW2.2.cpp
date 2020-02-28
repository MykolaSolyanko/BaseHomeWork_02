
#include <iostream>

int main() {
  std::cout << "This program checks ticket number.\n";
  std::cout << "Enter ticket number\n";
  int number;
  std::cin >> number;
  const int kMinNumber = 100000, kMaxNumber = 999999;
  while (number < kMinNumber || number > kMaxNumber) {
    std::cout << "Not in range\n";
    std::cin >> number;
  }
  int left_number = (number / 100000) + ((number / 10000) % 10) + ((number / 1000) % 10);
  std::cout << "left sum = " << left_number << std::endl;
  int right_number = ((number / 100) % 10) + ((number / 10) % 10) + ((number / 1) % 10);
  std::cout << "right sum = " << right_number << std::endl;
  if (left_number == right_number)
    std::cout << "You won!!!\n";
  else
    std::cout << "You lose...\n";
  return 0;
}
