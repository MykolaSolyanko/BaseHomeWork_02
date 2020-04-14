// Happy ticket.cpp

#include <iostream>

int main() {
  std::cout << "Input 6 digit number of your ticket " << std::endl;
  int num;
  std::cin >> num;
  const int kMinNumber = 100000, kMaxNumber = 999999;
  while (num < kMinNumber || num > kMaxNumber) {
    std::cout << "Your ticket number is out of range\n";
    std::cin >> num;
  }
  int left_num = (num / 100000) + ((num / 10000) % 10) + ((num / 1000) % 10);
  std::cout << "left sum = " << left_num << std::endl;
  int right_num = ((num / 100) % 10) + ((num / 10) % 10) + ((num / 1) % 10);
  std::cout << "right sum = " << right_num << std::endl;
  std::cout << "You "
            << (left_num == right_num ? "Ticket is HAPPY!!!"
                                      : "The ticket is not happy( ...");
  std::cout << std::endl;
  return 0;
}
