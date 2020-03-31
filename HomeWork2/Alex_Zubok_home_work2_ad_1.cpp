#include <iostream>

int main() {
  long long value{};
  const int kZero = 0;
  const int kOne = 1;
  const int kTwo = 2;
  std::cin >> value;
  if ((value % kTwo) == kZero)
    ++value;
  size_t index{};
  while (value > kZero) {
    value -= kTwo;
    ++index;
  }
  for (size_t i_ind = index, t_ind = kOne; i_ind > kZero; i_ind--, t_ind += kTwo) {
    if (i_ind - kOne > kZero) {
      for (size_t j_ind = i_ind - kOne; j_ind > kZero; j_ind--) {
        std::cout << " ";
      }
    }
    for (size_t k_ind = t_ind; k_ind > kZero; k_ind--) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  return 0;
}
