#include <iostream>

void Reverse(char *array, const size_t kMaxInput) {
  size_t i = 1;
  while (i <= kMaxInput) {
    if (array[kMaxInput - i] != 0) {
      std::cout << array[kMaxInput - i];
    }
    i++;
  }
}

int main(int argc, char *argv[]) {
  std::cout << "This program reverses string\n";
  const size_t kMaxInput = 100;
  char array[kMaxInput]{};
  std::cout << "Enter string for reverse, in range of " << kMaxInput
            << " symbols:\n";
  std::cin >> array;
  Reverse(array, kMaxInput);
  return 0;
}
