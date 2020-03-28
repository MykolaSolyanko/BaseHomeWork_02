#include <iostream>

void bite_check(uint16_t byte_arr[8], size_t index) {
  std::cout << ((byte_arr[8 - index]) ? "Yes" : "No") << std::endl;
}

int main() {
  unsigned long value{}, number{};
  uint16_t one_byte[8]{};
  std::cout << "Please enter a number from 0 till 255 and number of the bit that you want a check for set: ";
  std::cin >> value >> number;
  const uint8_t kByte = 7;

  for (uint16_t tmp = value, index = 0; tmp > 0; tmp /= 2, index++)
    one_byte[kByte - index] = tmp % 2;

  bite_check(one_byte, number);

  return 0;
}
