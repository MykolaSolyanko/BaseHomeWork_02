#include <cstring>
#include <iostream>

void upper_string(char *string) {
  for (size_t i = 0; i < std::strlen(string); i++) {
    if (*(string + i) > 96 && *(string + i) < 123)
      *(string + i) -= 32;
    std::cout << *(string + i);
  }
  std::cout << std::endl;
}

char *ret_upper_string(char *string) {
  for (size_t i = 0; i < std::strlen(string); i++) {
    if (*(string + i) > 96 && *(string + i) < 123)
      *(string + i) -= 32;
  }
  return string;
}

int main() {
  std::cout << "Please enter string: ";
  char *tmp_string = new char;
  std::cin >> tmp_string;
  char *string = new char[std::strlen(tmp_string) + 1];
  std::strcpy(string, tmp_string);
  delete tmp_string;
  std::cout << "Your string is: " << string << std::endl;
  std::cout << "Your upper string is: ";
  upper_string(string);
  std::cout << "Your upper return string is " << ret_upper_string(string) << std::endl;
  delete[] string;
  return 0;
}