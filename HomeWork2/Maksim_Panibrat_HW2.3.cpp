
#include <iostream>

int main() {
  std::cout << "This program turns number in reverse.\n";
  std::cout << "Enter number to reverse it\n";
  int32_t num;
  std::cin >> num;
  int64_t rev_num{0};
  if (num < 10) {
    std::cout << "reverse number is the same as you are entered\n";
  }
  do {
    rev_num *= 10;
    rev_num += num % 10;
    num /= 10;
  } while (num != 0);

  std::cout << rev_num << "\n";
  return 0;
}
