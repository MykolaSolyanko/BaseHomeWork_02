#include <iostream>

bool is_delimiter(int value, int value_delim) {
  return (value % value_delim) == 0;
}
int summ_number(int value) {
  int summ{};
  const uint8_t kTen = 10;
  for (int tmp = value; tmp > 0; tmp /= kTen)
    summ += (tmp % kTen);
  return summ;
}

void check_valid_input(long long &value) {
  while (!(std::cin >> value) || value < std::numeric_limits<unsigned int>::min() || value > std::numeric_limits<unsigned int>::max()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Sorry, you enter not positive integer value, please enter again: ";
  }
}

int main() {
  unsigned int value{};
  check_valid_input(value);
  unsigned int best_delimeter = value;
  for (int i = value; i > 0; i--) {
    if (is_delimiter(value, i)) {
      for (int j = i - 1; j > 0; j--) {
        if (is_delimiter(value, j)) {
          if (summ_number(best_delimeter) < summ_number(j)) {
            best_delimeter = j;
          }
        }
      }
    }
  }
  std::cout << "The best delimeter for " << value << " is a number " << best_delimeter << std::endl;
  return 0;
}
