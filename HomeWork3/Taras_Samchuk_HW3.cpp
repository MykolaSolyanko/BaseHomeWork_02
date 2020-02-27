// Working with pointers
#include <iostream>
int SwapChar(char *const first_ptr, char *const second_ptr) {
  if (first_ptr == nullptr || second_ptr == nullptr ||
      first_ptr == second_ptr) {
    return 1;  // ERROR
  }
  char tmp_ptr = *first_ptr;
  *first_ptr = *second_ptr;
  *second_ptr = tmp_ptr;
  return 0;  // OK
}
void Reverse() {
  const size_t k_max_char_len{255};
  const size_t k_len{k_max_char_len};
  std::cout << "Enter String" << std::endl;
  char text[k_len];
  std::cin >> text;
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  size_t len{0};
  while (*(text + len) != '\0') len++;
  for (size_t i = 0; i < len / 2; i++) {
    SwapChar((text + i), (text + len - i - 1));
  }
  std::cout << "The reflected line \"" << text << "\"" << std::endl;
}
bool IsDigit(const char Data = 0) {
/*
    Fragment of ASCI table
    for digits
    DEC OCT HEX SYM BIN
    48  60  30  0   0011'0000
    49  61  31  1   0011'0001
    50  62  32  2   0011'0010
    51  63  33  3   0011'0011
    52  64  34  4   0011'0100
    53  65  35  5   0011'0101
    54  66  36  6   0011'0110
    55  67  37  7   0011'0111
    56  70  38  8   0011'1000
    57  71  39  9   0011'1001
*/
  // '0' in ASCI dec(48) hex(0x30) oct(060) bin(0b0011'0000)
  const char k_ZERO_code{48};
  // '9' in ASCI dec(57) hex(0x39) oct(071) bin(0b0011'1001)
  const char k_NINE_code{57};
  return (k_ZERO_code <= Data && Data <= k_NINE_code) ? true : false;
}
int main() {

  
  // char test[]{"test string-"};
  // std::cout << "";
  // std::cin >> test;
  // char *test_ptr = test;
  // std::cout << test << std::endl;
  // Reverse(test_ptr);
  // std::cout << test << std::endl;
   return 0;
}