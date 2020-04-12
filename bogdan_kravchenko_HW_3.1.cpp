#include <iostream>

void reverse(char *array, const size_t kMax_Enter) {
  size_t min = 1;
  while (min <= kMax_Enter) {
    if (array[kMax_Enter - min] != 0) {
      std::cout << array[kMax_Enter - min];
    }
    min++;
  }
  std::cout << "\n";
}

int main() {
  std::cout << "You can reverse your string!" << std::endl;
  const int kMax_Enter = 50;
  char array[kMax_Enter]{};
  std::cout << "Enter string for reverse: ";
  std::cin >> array;
  reverse(array, kMax_Enter);
  return 0;
}
