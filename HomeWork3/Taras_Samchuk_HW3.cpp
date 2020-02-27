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
bool IsDigit(const char *const Data) {
  /*
      Fragment of ASCI table
      for digits
      DEC OCT HEX CH     BIN
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
  return (k_ZERO_code <= *Data && *Data <= k_NINE_code) ? true : false;
}

/*

    An excerpt of the ASCI table for some letters
dec  oct  hex    BIN    ch    dec  oct  hex     BIN
              76543210                       76543210
65   101  41  100'0001  A     97   141   61  110'0001  a
66   102  42  100'0010  B     98   142   62  110'0010  b
67   103  43  100'0011  C     99   143   63  110'0011  c
...  ...  ...   ...    ...   ...   ...  ...    ...    ...
89   131  59  101'1001  Y    121   171   79  101'1001  y
90   132  5A  101'1010  Z    122   172   7A  101'1010  z
              [^]                            [^]
          Look at 5 bits               Look at 5 bits
*/
// down
int DOWNto(char *const DOWN2) {
  if (DOWN2 == nullptr) {
    return 1;  // ERROR
  }
  const u_int8_t k_letter_BIG_A = 65;
  const u_int8_t k_letter_BIG_Z = 90;
  u_int8_t Mask = 1 << 5;
  // u_int8_t Mask = 0b100'000;
  *DOWN2 = (k_letter_BIG_A <= *DOWN2 && *DOWN2 <= k_letter_BIG_Z)
               ? *DOWN2 | Mask
               : *DOWN2;
  return 0;  // OK
}
// UP
int toUP(char *const toUP) {
  if (toUP == nullptr) {
    return 1;  // ERROR
  }
  const u_int8_t k_letter_small_a = 97;
  const u_int8_t k_letter_small_z = 122;

  u_int8_t Mask = ~(1 << 5);
  // u_int8_t Mask = 0b11'011'111;
  *toUP = (k_letter_small_a <= *toUP && *toUP <= k_letter_small_z)
              ? *toUP & Mask
              : *toUP;
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

void MyToLower() {
  const size_t k_max_char_len{255};
  const size_t k_len{k_max_char_len};
  std::cout << "Enter String" << std::endl;
  char text[k_len];
  std::cin >> text;
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  size_t len{0};
  while (*(text + len) != '\0') {
    // TODO переробити обхід масиву
    DOWNto(text + len);
    len++;
  }
  std::cout << " lowercase letters \"" << text << "\"" << std::endl;
}

void MyToUpper() {
  const size_t k_max_char_len{255};
  const size_t k_len{k_max_char_len};
  std::cout << "Enter String" << std::endl;
  char text[k_len];
  std::cin >> text;
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  size_t len{0};
  while (*(text + len) != '\0') {
    // TODO переробити обхід масиву
    toUP(text + len);
    len++;
  }
  std::cout << "IN CAPITAL LETTERS \"" << text << "\"" << std::endl;
}

int main() {
  MyToUpper();
  /*
  char test = 'T';
  std::cout << test << std::endl;
  DOWNto(&test);

  std::cout << test << std::endl;
    toUP(&test);

  std::cout << test << std::endl;*/

  // char test[]{"test string-"};
  // std::cout << "";
  // std::cin >> test;
  // char *test_ptr = test;
  // std::cout << test << std::endl;
  // Reverse(test_ptr);
  // std::cout << test << std::endl;
  return 0;
}