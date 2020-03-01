#include <iostream>
#include <string>

void Reverse(std::string input_string) {
  int letter = 1;
  size_t length = size(input_string);
  while (letter <= length) {
    std::cout << input_string[length - letter];
    letter++;
  }
}

int main() {
  std::cout << "This programm reverses string\n"
               "Enter string for analize: ";
  std::string input_string;
  std::getline(std::cin, input_string);
  Reverse(std::string(input_string));
  return 0;
}
