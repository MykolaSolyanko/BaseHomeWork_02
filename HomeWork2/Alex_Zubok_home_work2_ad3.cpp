#include <iostream>

int main() {
  size_t value{}, check_bit{};
  std::cout << "Please enter value from 1 till 2550000 and checking bit: ";
  std::cin >> value >> check_bit;
  std::cout << ((value & (1 << (check_bit - 1))) ? "Yes" : "No") << std::endl;
  return 0;
}
