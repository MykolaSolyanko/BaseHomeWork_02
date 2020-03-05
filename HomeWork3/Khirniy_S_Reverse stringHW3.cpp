// Reverse string.cpp

#include <algorithm>
#include <iostream>
#include <string>

int main() {
  // Input string from user
  std::string input;
  std::cout << "Input string to reverse:" << std::endl;
  getline(std::cin, input);

  // Reverse string
  reverse(input.begin(), input.end());
  std::cout << "Reverced string: " << std::endl << input << std::endl;
  std::cin.get();
  return 0;
}
