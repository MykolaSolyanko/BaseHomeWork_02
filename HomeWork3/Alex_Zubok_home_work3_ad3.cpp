#include <cstring>
#include <iostream>

void is_diget(char *string) {
  size_t is_first{};
  for (size_t i = 0; i < std::strlen(string); i++) {
    if (*(string + i) > 47 && *(string + i) < 58 && is_first != 0)
      std::cout << ", " << *(string + i);
    else if (*(string + i) > 47 && *(string + i) < 58 && is_first == 0) {
      std::cout << *(string + i);
      ++is_first;
    }
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "Please enter string: ";
  char *tmp_string = new char;
  std::cin >> tmp_string;
  char *string = new char[std::strlen(tmp_string) + 1];
  std::strcpy(string, tmp_string);
  delete tmp_string;
  std::cout << "Your string is: " << string << std::endl;
  std::cout << "Is diget: ";
  is_diget(string);
  delete[] string;
  return 0;
}
