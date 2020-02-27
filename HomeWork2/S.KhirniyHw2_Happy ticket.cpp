// Happy ticket.cpp

#include <iostream>

int main() {
  std::cout << "input 6 digit number of your ticket : " << std::endl;
  int32_t number;
  std::cin >> number;

  if (number >= 100'00 && number <= 999'999) {
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    a = number % 10;
    b = (number / 10) % 10;
    c = (number / 100) % 10;
    d = (number / 1000) % 10;
    e = (number / 10000) % 10;
    f = (number / 100000) % 10;
    (a + b + c == e + d + f) ? std::cout << "Happy ticket!"
                             : std::cout << "No happy(" << std::endl;
  } else {
    std::cout << "Input error, Please try again" << std::endl;
  }

  return 0;
}
