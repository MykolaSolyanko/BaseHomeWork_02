#include <iostream>
#include <limits>

auto ReadValueFromCin(size_t min, size_t max) {
  size_t n{};
  do {
    std::cin >> n;
    if (n > min && n < max) {
      break;
    }
    std::cout << "Incorrect value. Try again." << std::endl;
  } while (true);
  return n;
}
void CristmasTree() {
  std::cout << " Please enter the number in the range from 0 to 100"
            << std::endl;

  const int8_t MINVALUE = 0;
  const int8_t MAXVALUE = 101;
  size_t n = ReadValueFromCin(MINVALUE, MAXVALUE);
  if (n % 2 == 0) {
    n += 1;
  }
  const size_t n_half = n / 2;
  for (size_t i = 0; i < n_half + 1; ++i) {
    for (size_t j = 0; j < n; j++) {
      if (j < (n_half - i) || j > (n_half + i)) {
        std::cout << " ";
      } else {
        std::cout << "*";
      }
    }
    std::cout << std::endl;
  }
}
void BitCounter() {
  std::cout << " Please enter the number in the range from 0 to "
            << std::numeric_limits<short>::max() << std::endl;
  const int MINVALUE = 0;
  const int MAXVALUE = std::numeric_limits<short>::max();
  int32_t n = ReadValueFromCin(MINVALUE, MAXVALUE);
  unsigned bit_counter = 0;
  while (n != 0) {
    n &= n - 1;
    ++bit_counter;
  }
  std::cout << " The amount of setted bit is " << bit_counter << std::endl;
}
void isSetBit() {
  std::cout << " Please enter the number in the range from 0 to "
            << std::numeric_limits<int32_t>::max() << std::endl;
  const int MINVALUE = 0;
  const int MAXVALUE = std::numeric_limits<int32_t>::max();
  int32_t n = ReadValueFromCin(MINVALUE, MAXVALUE);
  std::cout << " Please enter the bit number in the range from 1 to 32."
            << std::endl;
  const int MINBITSET = 0;
  const int MAXBITSET = 32;
  int32_t bit_set = ReadValueFromCin(MINBITSET, MAXBITSET);
  bool b = (n >> bit_set) & 1LL;
  std::cout << ((b == 1) ? "Yes." : "No.") << std::endl;
}
void NumberCreation() {
  const int MINVALUE = 0;
  const int MAXVALUE = std::numeric_limits<int>::max();
  std::cout << " Please enter the number in the range from 0 to " << MAXVALUE
            << " ." << std::endl;
  int32_t n = ReadValueFromCin(MINVALUE, MAXVALUE);
  long long sum{};
  int value;
  for (int j{}; j < n; ++j) {
    do {
      std::cin >> value;
      if (value > MINVALUE && value < MAXVALUE) {
        for (int i{value}; i > 0; i /= 10) {
          sum += i % 10;
        };
        break;
      } else {
        std::cout << "Incorrect value. Try again." << std::endl;
      }
    } while (true);
  }
  std::cout << ((sum % 3 == 0) ? "Yes!" : "No.") << std::endl;
}
enum {
  CRISTMAS_TREE = 1,
  BIT_COUNTER,
  IS_SET_BIT,
  NUMBER_CREATION,
};
int main() {
  do {
    std::cout << "\n Please, choose the function from the list:" << std::endl;
    std::cout << " 1 to get a cristmas tree;" << std::endl;
    std::cout << " 2 to get an amount of setted bit in the number;"
              << std::endl;
    std::cout << " 3 to check if bit is set;" << std::endl;
    std::cout << " 4 to check if created number is divided by 3;" << std::endl;
    std::cout << " Press any other key to exit from this program." << std::endl;
    int choise;
    std::cin >> choise;
    switch (choise) {
    case CRISTMAS_TREE:
      CristmasTree();
      break;
    case BIT_COUNTER:
      BitCounter();
      break;
    case IS_SET_BIT:
      isSetBit();
      break;
    case NUMBER_CREATION:
      NumberCreation();
      break;
    default:
      std::cout << " End of Program " << std::endl;
      return 0;
    }
  } while (true);
  return 0;
}
