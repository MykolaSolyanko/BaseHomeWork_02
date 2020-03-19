// Program for translating characters in uppercase

#include <iostream>
#include <stdio.h>

int main() {
  const size_t kSize{100};
  char a[kSize];
  std::cout << "Enter string for translating characters in uppercase: \n";
  std::cin >> a;
  int i;
  for (i = 0; a[i] != 0; i++) {
    if (a[i] <= 'z' && a[i] >= 'a') {
      a[i] += 'A' - 'a';
    }
  }
  std::cout << a << std::endl;
  return 0;
}
