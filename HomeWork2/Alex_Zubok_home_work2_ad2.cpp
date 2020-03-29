#include <bitset>
#include <iostream>

size_t count_bit(size_t value) {
  size_t count{};
  for (size_t i = 0, tmp = value; tmp > 0; i++, tmp /= 2) {
    if (value & (1 << i))
      ++count;
  }
  return count;
}

int main() {
  size_t value{};
  std::cout << "Please enter value from 1 till 2550000: ";
  std::cin >> value;
  std::bitset<24> bits{value};
  std::cout << value << " ---> " << bits << " > set bits is " << count_bit(value) << std::endl;
  return 0;
}
