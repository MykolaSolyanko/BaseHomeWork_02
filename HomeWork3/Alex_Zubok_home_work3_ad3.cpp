#include <cstring>
#include <iostream>

void is_diget(const char *string) {
  if (string == nullptr || (string + strlen(string)) == nullptr ||
      strlen(string) == 0)
    return;
  size_t is_first{};
  for (size_t i = 0; i < strlen(string); i++) {
    if (*(string + i) >= '0' && *(string + i) <= '9' && is_first != 0)
      std::cout << ", " << *(string + i);
    else if (*(string + i) >= '0' && *(string + i) <= '9' && is_first == 0) {
      std::cout << *(string + i);
      ++is_first;
    }
  }
  std::cout << std::endl;
}

int main() {
  size_t kMaxSizeString = 1000;
  const char kEnter = '\n';
  std::cout << "Please enter string to " << kMaxSizeString << " symbols: ";
  char *tmp_string = new char[kMaxSizeString]{};
  std::cin.get(tmp_string, kMaxSizeString, kEnter);
  char *string = new char[strlen(tmp_string) + 1]{};
  strncpy(string, tmp_string, strlen(tmp_string));
  delete[] tmp_string;
  std::cout << "Your string is: " << string << std::endl;
  std::cout << "Is diget: ";
  is_diget(string);
  delete[] string;
  return 0;
}
