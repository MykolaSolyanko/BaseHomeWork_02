// Reverse.cpp

#include <iostream>

int main() {

  std::cout << "Enter digit to reverse: " << std::endl;
  int32_t s;
  std::cin >> s;
  while (s) {
    std::cout << s % 10;
    s /= 10;
  }
  std::cout << std::endl;

  return 0;
}
