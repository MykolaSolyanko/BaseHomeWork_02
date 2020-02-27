// Working with pointers
#include <iostream>
int SwapChar(char *const first_ptr, char *const second_ptr) {
  if (first_ptr == nullptr || second_ptr == nullptr ||
      first_ptr == second_ptr) {
    return 1; // ERROR
  }
  // char tmp = '\0';
  // char *tmp_ptr = &tmp;
  char tmp_ptr = *first_ptr;
  *first_ptr = *second_ptr;
  *second_ptr = tmp_ptr;
  return 0; // OK
}
int Reverse(char *text) {
  if (text == nullptr) {
    return 1; // Error
  }
  size_t len{0};
  while (text[len] != '\0')
    len++;
  for (size_t i = 0; i < len / 2; i++) {
    if (!SwapChar(&text[i], &text[len - 1 - i]))
      return 0;
  }
  return 0;
}
int main() {
  char test[]{"test string-"};
  std::cout << "";
  std::cin >> test;
  char *test_ptr = test;
  std::cout << test << std::endl;
  Reverse(test_ptr);
  std::cout << test << std::endl;
  return 0;
}