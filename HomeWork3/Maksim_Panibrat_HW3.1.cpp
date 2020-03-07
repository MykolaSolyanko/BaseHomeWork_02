#include <iostream>

void Reverse(char *array, const size_t kMaxInput) {
  size_t tic = 1;
  while (tic <= kMaxInput) {
    if (array[kMaxInput - tic] != 0) {
      std::cout << array[kMaxInput - tic];
    }
    tic++;
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
