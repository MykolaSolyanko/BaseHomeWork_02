#include <cstring>
#include <iostream>

void reverse_string(const char *tmp_string) {
  char *reverse_string = new char[std::strlen(tmp_string)];
  std::strcpy(reverse_string, tmp_string);
  std::cout << "Your reverse string is : ";
  for (size_t index = std::strlen(reverse_string) - 1; index > 0; index--) {
    std::cout << *(reverse_string + index);
  }

  std::cout << *reverse_string << std::endl;
  delete[] reverse_string;
}

int main() {
  char *tmp_string = new char;
  std::cout << "Please enter your string that you want reverse: ";
  std::cin >> tmp_string;

  char *string_full = new char[std::strlen(tmp_string) + 1];
  std::strcpy(string_full, tmp_string);
  delete tmp_string;

  std::cout << "Your origin string is: " << string_full << std::endl;
  reverse_string(string_full);

  delete[] string_full;

  return 0;
}
