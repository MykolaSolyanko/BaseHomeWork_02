#include <cstring>
#include <iostream>

void lower_string(char *string) {
  for (size_t i = 0; i < std::strlen(string); i++) {
    if (*(string + i) > 64 && *(string + i) < 89)
      *(string + i) += 32;
    std::cout << *(string + i);
  }
  std::cout << std::endl;
}

char *ret_lower_string(char *string) {
  for (size_t i = 0; i < std::strlen(string); i++) {
    if (*(string + i) > 64 && *(string + i) < 89)
      *(string + i) += 32;
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
  std::cout << "Your lower string is: ";
  lower_string(string);
  std::cout << "Your lower return string is " << ret_lower_string(string) << std::endl;
  delete[] string;
  return 0;
}
