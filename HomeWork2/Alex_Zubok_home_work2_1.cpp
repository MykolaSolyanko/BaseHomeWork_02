#include <cmath>
#include <iostream>

void check_valid_input(long long &value) {
  while (!(std::cin >> value) || value < std::numeric_limits<unsigned int>::min() || value > std::numeric_limits<unsigned int>::max()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Sorry, you enter not positive integer value, please enter again: ";
  }
}

int main() {
  long long var{}, summ_var{};
  std::cout << "Please enter a positive integer value:";
  check_valid_input(var);
  if (var == 0) {
    std::cout << "Summ of 1 element is 0" << std::endl;
    std::cout << "Arithmetic means of 0 is 0" << std::endl;
    return 0;
  }
  size_t index{};
  const uint8_t kZero = 0;
  const uint8_t kTen = 10;
  for (size_t tmp = var, summ{}; tmp > kZero; tmp /= kTen) {
    ++index;
    summ_var += tmp % kTen;
  }
  std::cout << "Summ of ";
  for (size_t tmp = var, i = index; i > kZero; i--) {
    int tmp_num = tmp / pow(kTen, i - 1);
    std::cout << tmp_num;
    tmp -= tmp_num * pow(kTen, i - 1);
    std::cout << (i < 2 ? " = " : " + ");
  }
  std::cout << summ_var << std::endl;
  std::cout << "Arithmetic means of " << summ_var << " / " << index << " = " << (summ_var / index) << std::endl;
  return 0;
}
