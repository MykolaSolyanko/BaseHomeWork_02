
#include <iostream>

int main() {
  std::cout << "This program checks ticket number.\n";
  std::cout << "Enter ticket number\n";
  int num;
  std::cin >> num;
  const int kMinNum = 100000, kMaxNum = 999999;
  while (num < kMinNum || num > kMaxNum) {
    std::cout << "Not in range\n";
    std::cin >> num;
  }
  int left_num = (num / 100000) + ((num / 10000) % 10) + ((num / 1000) % 10);
  std::cout << "left sum = " << left_num << std::endl;
  int right_num = ((num / 100) % 10) + ((num / 10) % 10) + ((num / 1) % 10);
  std::cout << "right_sum = " << right_num << std::endl;
  if (left_num == right_num)
    std::cout << "You won!!!\n";
  else
    std::cout << "You lose...\n";
  return 0;
