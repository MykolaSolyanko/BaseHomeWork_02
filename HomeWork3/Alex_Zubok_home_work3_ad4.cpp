#include <cstring>
#include <iostream>

void lower_string(char *string) {
  if (string == nullptr || string + strlen(string) == nullptr ||
      strlen(string) == 0)
    return;
  for (size_t i = 0; i < strlen(string); i++) {
    if (*(string + i) >= 'A' && *(string + i) <= 'Z')
      *(string + i) += 32;
    std::cout << *(string + i);
  }
  std::cout << std::endl;
}

char *ret_lower_string(char *string) {
  if (string == nullptr || string + strlen(string) == nullptr ||
      strlen(string) == 0)
    return string;
  for (size_t i = 0; i < strlen(string); i++) {
    if (*(string + i) >= 'A' && *(string + i) <= 'Z')
      *(string + i) += 32;
  }
  return string;
}

int main() {
  const size_t kMaxStringSize = 1000;
  const char kEnter = '\n';
  std::cout << "Please enter string to : ";
  char *tmp_string = new char[kMaxStringSize]{};
  std::cin.get(tmp_string, kMaxStringSize, kEnter);
  char *string = new char[strlen(tmp_string) + 1]{};
  strcpy(string, tmp_string);
  delete[] tmp_string;
  std::cout << "Your string is: " << string << std::endl;
  std::cout << "Your lower string is: ";
  lower_string(string);
  std::cout << "Your lower return string is " << ret_lower_string(string)
            << std::endl;
  delete[] string;
  return 0;
}
