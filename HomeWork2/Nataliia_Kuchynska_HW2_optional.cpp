#include <iostream>
#include <limits>

const int MAX_VAL = std::numeric_limits<int>::max();
const int MINBITSET = 0;
const int MAXBITSET = 32;
void CristmasTree() {
  std::cout << " Please enter the number in the range from 0 to 100"
            << std::endl;
  int n;
  do {
    std::cin >> n;
    if (n > 0 && n < 101) {
      break;
    }
    std::cout << " Incorrect value. Try again." << std::endl;
  } while (true);
  if (n % 2 == 0) {
    n += 1;
  }
  const int n_half = n / 2;
  for (int i = 0; i < n_half + 1; ++i) {
    for (int j = 0; j < n; j++) {
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
  int n;
  do {
    std::cin >> n;
    if (n > 0 && n < std::numeric_limits<short>::max()) {
      break;
    }
    std::cout << "Incorrect value. Try again." << std::endl;
  } while (true);
  unsigned bit_counter = 0;
  while (n) {
    n &= n - 1;
    ++bit_counter;
  }
  std::cout << " The amount of setted bit is " << bit_counter << std::endl;
}
void isSetBit() {
  std::cout << " Please enter the number in the range from 0 to "
            << std::numeric_limits<int32_t>::max() << std::endl;
  int32_t n;
  do {
    std::cin >> n;
    if (n > 0 && n < std::numeric_limits<int32_t>::max()) {
      break;
    }
    std::cout << "Incorrect value. Try again." << std::endl;
  } while (true);
  std::cout << " Please enter the bit number in the range from 0 to 31."
            << std::endl;
  int32_t bit_set;
  do {
    std::cin >> bit_set;
    if (bit_set >= MINBITSET && bit_set < MAXBITSET) {
      break;
    }
    std::cout << "Incorrect value. Try again." << std::endl;
  } while (true);
  bool b = (n >> bit_set) & 1LL;
  std::cout << ((b == 1) ? "Yes." : "No.") << std::endl;
}
void NumberCreation() {
  std::cout << " Please enter the number in the range from 0 to " << MAX_VAL
            << " ." << std::endl;
  int32_t n;
  do {
    std::cin >> n;
    if (n > 0 && n < MAX_VAL) {
      break;
    }
    std::cout << "Incorrect value. Try again." << std::endl;
  } while (true);
  std::cout << " Please enter " << n << " numbers in the range from 0 to "
            << MAX_VAL << std::endl;
  long long sum{};
  int value;

  for (int j{}; j < n; ++j) {
    do {
      std::cin >> value;
      if (value > 0 && value < MAX_VAL) {
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
  int i{1};
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
  } while (i != 0);
  return 0;
}
