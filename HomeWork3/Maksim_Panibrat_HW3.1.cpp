#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "This program reverses string\n";
  const size_t kMaxSize = 31;
  char array[kMaxSize]{};
  std::cout << "Enter string for reverse, in range of " << kMaxSize - 1
            << " symbols: ";
  std::cin >> array;
  const size_t size = strlen(array);
  char *begin = {array - 1}, *end = {begin + size}, temp_array[kMaxSize]{},
       *temp = temp_array, *arr = array;
  while (*end != *begin) {
    *temp = *end;
    --end;
    temp++;
  }
  temp = temp_array - 1;
  while (array[size - 1] != temp_array[size - 1]) {
    *arr = *(temp + 1);
    temp++;
    arr++;
  }
  std::cout << "Result: " << array;
  return 0;
}
