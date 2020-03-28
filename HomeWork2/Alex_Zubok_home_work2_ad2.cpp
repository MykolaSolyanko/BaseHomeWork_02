#include <iostream>

void print_byte(uint16_t byte_arr[8]) {
  for (size_t index = 0; index < 8; index++)
    std::cout << byte_arr[index];
}
size_t count_byte(uint16_t byte_arr[8]) {
  size_t count{};
  for (size_t index = 0; index < 8; index++) {
    if (byte_arr[index] == 1)
      ++count;
  }
  return count;
}

int main() {
  unsigned long value{};
  uint16_t one_byte[8]{};
  std::cout << "Please enter number from 0 till 255: ";
  std::cin >> value;
  const uint8_t kByte = 7;

  for (uint16_t tmp = value, index = 0; tmp > 0; tmp /= 2, index++)
    one_byte[kByte - index] = tmp % 2;

  std::cout << value << " ---> ";
  print_byte(one_byte);
  std::cout << " set bites is " << count_byte(one_byte) << std::endl;

  return 0;
}
