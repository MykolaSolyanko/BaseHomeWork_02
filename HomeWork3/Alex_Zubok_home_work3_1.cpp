#include <cstring>
#include <iostream>

void reverse_string(char *string) {
  if (string == nullptr || string + strlen(string) == nullptr ||
      strlen(string) == 0)
    return;
  for (char *c_start = string, *c_end = string + strlen(string) - 1;
       c_start != string + strlen(string) / 2; c_start++, c_end--) {
    char tmp = *c_start;
    *c_start = *c_end;
    *c_end = tmp;
  }
}

int main() {
  size_t kMaxSizeString = 1000;
  char *tmp_string = new char[kMaxSizeString]{};
  std::cout << "Please enter your string that you want reverse to "
            << kMaxSizeString << " symbols and press 'Enter': ";
  std::cin.get(tmp_string, kMaxSizeString, '\n');

  char *string_full = new char[strlen(tmp_string) + 1]{};
  strncpy(string_full, tmp_string, strlen(tmp_string));
  delete[] tmp_string;

  std::cout << "Your origin string is: " << string_full << std::endl;
  reverse_string(string_full);
  std::cout << "Your origin string is: " << string_full << std::endl;

  delete[] string_full;

  return 0;
}
