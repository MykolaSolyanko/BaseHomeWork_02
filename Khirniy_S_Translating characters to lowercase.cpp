// Program for translating characters to lowercase

#include <iostream>
#include <stdio.h>

int main() {
  const size_t kSize{100};
  char a[kSize];
  std::cout << "Enter string for translating characters to lowercase: \n";
  std::cin >> a;
  int i;
  for (i = 0; a[i] != 0; i++) {
    if (a[i] <= 'Z' && a[i] >= 'A') {
      a[i] += 'a' - 'A';
    }
  }
  std::cout << a << std::endl;
  return 0;
}
