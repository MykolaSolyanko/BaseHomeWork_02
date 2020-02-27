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
int main() {
  Reverse();
  // char test[]{"test string-"};
  // std::cout << "";
  // std::cin >> test;
  // char *test_ptr = test;
  // std::cout << test << std::endl;
  // Reverse(test_ptr);
  // std::cout << test << std::endl;
  // return 0;
}