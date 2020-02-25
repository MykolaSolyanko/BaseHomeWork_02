#include <iostream>
#include <limits>
void sum_am();
void lucky_ticket();
void reverse_number();
void odd_el_sum();
void best_divisor();
void cristmas_tree();
enum {
  SUM_AM = 1,
  LUCKY_TICKET,
  REVERSE_NUMBER,
  ODD_ELEMENTS_SUM,
  BEST_DIVISOR,
};
int main() {
  int i{1};
  do {
    std::cout << "\n Please, choose the function from the list:" << std::endl;
    std::cout << " 1 to compute for given number the sum and arithmetic mean "
                 "of digits;"
              << std::endl;
    std::cout << " 2 to compute lucky-ticket function for given 6-digit number;"
              << std::endl;
    std::cout
        << " 3 to obtain reverse number for given 32-bit signed integer number;"
        << std::endl;
    std::cout << " 4 to compute the sum of odd elements for given array of "
                 "integer numbers;"
              << std::endl;
    std::cout << " 5 to obtain the best divisor for given number;" << std::endl;
    std::cout << " Press any other key to exit from this program." << std::endl;
    int choise;
    std::cin >> choise;
    switch (choise) {
    case SUM_AM:
      sum_am();
      break;
    case LUCKY_TICKET:
      lucky_ticket();
      break;
    case REVERSE_NUMBER:
      reverse_number();
      break;
    case ODD_ELEMENTS_SUM:
      odd_el_sum();
      break;
    case BEST_DIVISOR:
      best_divisor();
      break;
    default:
      std::cout << " End of Program " << std::endl;
      i = 0;
      break;
    }
  } while (i != 0);
  return 0;
}
void sum_am() {
  std::cout << " Please, enter integer number from 1 to "
            << std::numeric_limits<short>::max() << std::endl;
  long int value{};
  std::cin >> value;
  if (value <= 0 || value > std::numeric_limits<short>::max()) {
    std::cout << "Incorrect input number" << std::endl;
  } else {
    long int v_sum{}, v_am{}, k{};
    for (int i{value}; i > 0; i /= 10) {
      v_sum += i % 10;
      ++k;
    };
    v_am = v_sum / k;
    std::cout << " For number " << value << " :\n the sum of number digits is "
              << v_sum << "; \n the arithmetic mean is " << v_am << "."
              << std::endl;
  }
}
void lucky_ticket() {
  std::cout << " Please, enter 6-digit integer number" << std::endl;
  long int value{};
  std::cin >> value;
  if (value < 100'000 || value > 999'999) {
    std::cout << "Invalid ticket number. " << std::endl;
    return;
  }
  long int first_part{}, second_part{};
  for (int i{value}, k{}; i > 0; i /= 10, ++k) {
    if (k < 3) {
      second_part += i % 10;
    } else {
      first_part += i % 10;
    }
  };
  if ((first_part - second_part) == 0) {
    std::cout << " The ticket " << value << " is lucky. Congrats!" << std::endl;
  } else {
    std::cout << " The ticket " << value << " is NOT lucky. Buy another one :)"
              << std::endl;
  }
}
void reverse_number() {
  std::cout << "Please, enter 32-bit signed integer number" << std::endl;
  int value{};
  std::cin >> value;
  long int v_sum{}, v_am{};
  bool is_negative = (value < 0);
  if (is_negative) {
    value = -value;
  }
  for (int i{value}; i > 0; i /= 10) {
    v_sum *= 10;
    v_sum += i % 10;
  };
  if (is_negative) {
    v_sum = -v_sum;
    value = -value;
  }
  std::cout << "For number " << value << " :\nthe reverse is " << v_sum << "."
            << std::endl;
}
void odd_el_sum() {
  std::cout << "Please, enter the size of integer numbers array (from 1 to 50)"
            << std::endl;
  size_t value;
  std::cin >> value;
  if ((value > 50) || (value < 1)) {
    std::cout << "Incorrect size of array" << std::endl;
  } else {
    std::cout << "Please, enter " << value
              << " numbers in interval -60 <= x <= 90" << std::endl;
    int element;
    size_t i{};
    long long sum{};
    while (i < value) {
      std::cout << "Please, enter the " << i + 1 << "th number: " << std::endl;
      std::cin >> element;
      if (element < -60 || element > 90) {
        std::cout << "Incorrect element. Try again." << std::endl;
        continue;
      }
      if (element % 2 != 0) {
        sum += element;
      }
      ++i;
    }

    std::cout << "The summ of odd numbers is " << sum << "." << std::endl;
  }
}
void best_divisor() {
  std::cout << "Please, enter any natural number from 1 to "
            << std::numeric_limits<uint32_t>::max() << " ." << std::endl;
  uint32_t value{};
  std::cin >> value;
  uint32_t b_div{1}, dig_sum_b_div{1}, dig_sum_i;
  if (value > 0) {
    for (uint32_t i{1}; i <= value; ++i) {
      if (value % i == 0) {
        dig_sum_i = 0;
        for (uint32_t j{i}; j > 0; j /= 10) {
          dig_sum_i += (j % 10);
        };
        if (dig_sum_b_div < dig_sum_i) {
          b_div = i;
          dig_sum_b_div = dig_sum_i;
        }
      }
    };
  } else {
    std::cout << " Incorrect natural number " << std::endl;
  }
  std::cout << "For the number " << value << " :" << std::endl;
  std::cout << "The best divisor is " << b_div << " with the digits sum "
            << dig_sum_b_div << std::endl;
}
