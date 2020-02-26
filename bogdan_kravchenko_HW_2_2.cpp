#include <iostream>

int main() {
  std::cout << "You can win a prize. Please, enter a six digit number - "
            << std::endl;
  int magic_number;
  std::cin >> magic_number;

  const int Km_nMin = 100000, Km_nMax = 999999;

  while (magic_number < Km_nMin || Km_nMax < magic_number) {
    std::cout << "Error! Enter a six digit number - " << std::endl;
    std::cin >> magic_number;
  }

  int left_m_n = ((magic_number / 100000) % 10) +
                 ((magic_number / 10000) % 10) + ((magic_number / 1000) % 10);
  std::cout << "left part sum = " << left_m_n << std::endl;
  int right_m_n = ((magic_number / 100) % 10) + ((magic_number / 10) % 10) +
                  ((magic_number / 1) % 10);
  std::cout << "right part sum = " << right_m_n << std::endl;

  if (left_m_n == right_m_n) {
    std::cout << "Congratulation! You win!" << std::endl;
  } else {
    std::cout << "Sorry, you lose :(" << std::endl;
  }

  return 0;
}
