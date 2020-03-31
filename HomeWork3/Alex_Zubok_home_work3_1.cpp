#include <cstring>
#include <iostream>

void reverse_string(char *string) {
  if (string == nullptr || string+std::strlen(string) == nullptr || std::strlen(string) == 0)
    return;
  char *tmp_string = new char[std::strlen(string)];
  std::strcpy(tmp_string, string);
  std::cout << "Your reverse string is : ";
  for (size_t index = std::strlen(tmp_string) - 1, i = 0; i < std::strlen(tmp_string); index--, i++) {
    *(string + i) = *(tmp_string + index);
    std::cout << *(tmp_string + index);
  }
  *(string + (std::strlen(tmp_string) - 1)) = *tmp_string;
  std::cout << std::endl;
  delete[] tmp_string;
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
  std::cout << "Your origin string is: " << string_full << std::endl;

  delete[] string_full;

  return 0;
}
