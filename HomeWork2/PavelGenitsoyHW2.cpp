#include <iostream>

auto GetInputFromCin(long long min, size_t max) {
  size_t number{};
  while (std::cin >> number && (number < min || number > max)) {
    std::cout << "\nYou entered an incorrect numbers, try entering "
                 "again.\nEnter a num: ";
  }
  return number;
}

void digits_in_number() {
  int num{};
  std::cout << "\nEnter some number: " << std::endl;
  std::cin >> num;
  int sum_digits{}, count{0};
  if (num > 0) {
    for (int i{num}; i > 0; i /= 10) {
      sum_digits += i % 10;
      ++count;
    }
    const auto arithmetic_mean = static_cast<double>(sum_digits) / count;
    std::cout << "\nThe sum of digits in the number: " << sum_digits
              << ", and arithmetic mean of digits in the number: "
              << arithmetic_mean << "\n\n"
              << std::endl;
    return;
  }
  if (num == 0) {
    std::cout << "\nThe sum and arithmetic mean of digits in the number: "
              << num << "\n\n"
              << std::endl;
    return;
  }
  std::cout << "\nTry a number which >0"
            << "\n\n"
            << std::endl;
}

void lucky_ticket() {
  const auto kMin = 100000;
  const auto kMax = 999999;
  std::cout << "\nEnter number in range[" << kMin << "..." << kMax
            << "]: " << std::endl;
  auto num = GetInputFromCin(kMin, kMax);

  const auto kHalf_num{num / 1000};
  int first_sum_digits{};
  for (int i{kHalf_num}; i > 0; i /= 10) {
    first_sum_digits += i % 10;
  }

  int second_sum_digits{};
  for (int i{num}; i > kHalf_num; i /= 10) {
    second_sum_digits += i % 10;
  }

  if (first_sum_digits == second_sum_digits) {
    std::cout << "\nNICE!! You have a lucky ticket!"
              << "\n\n"
              << std::endl;
    return;
  }
  std::cout << "\nGG. Its is not a lucky ticket."
            << "\n\n"
            << std::endl;
}

void reverse_num() {
  int32_t num{};
  std::cout << "\nEnter some number: " << std::endl;
  std::cin >> num;
  int r_num{};
  if (num == 0) {
    std::cout << "You entered is " << num << ", and reverse of your number is "
              << r_num << "\n\n"
              << std::endl;
    return;
  } 
  auto i{num};
  while (i != 0) {
    r_num *= 10;
    r_num += i % 10;
    i /= 10;
  }
  std::cout << "You entered is " << num << ", and reverse of your number is "
            << r_num << "\n\n"
            << std::endl;
}

void sum_odd_elements() {
  const auto kMin_amount = 1;
  const auto Max_amount = 50;
  std::cout << "\nEnter amount of numbers in this range [" << kMin_amount
            << "..." << Max_amount
            << "], which you will be input: " << std::endl;
  auto amount = GetInputFromCin(kMin_amount, kMax_amount);

  int sum_num{};
  while (amount != 0) {
    const auto kMin_range = -60;
    const auto kMax_range = 90;
    std::cout << "\nEnter number in range[" << kMin_range << "..." << kMax_range
              << "]: ";
    auto num = GetInputFromCin(kMin_range, kMax_range);

    if (num % 2 == 1) {
      sum_num += num;
    }
    --amount;
  }
  std::cout << "\nThe sum of odd elements: " << sum_num << std::endl;
}

void best_divisior() {
  const auto kMin = std::numeric_limits<unsigned short>::min() + 1;
  const auto kMax = std::numeric_limits<unsigned int>::max();
  std::cout << "\nEnter a number in range [" << kMin << " ... " << kMax
            << "]: " << std::endl;
  unsigned int number = GetInputFromCin(kMin, kMax);

  unsigned int best_digit{number}, best_sum{};
  for (size_t i = 1; i <= number; i++) {
    unsigned int sum{};
    if (number % i == 0) {
      unsigned int temp{i};
      std::cout << i << ' ';

      do {
        sum += temp % 10;
        temp /= 10;
      } while (temp);

      if (sum > best_sum) {
        best_sum = sum;
        best_digit = i;
      }
    }
  }
  std::cout << "\nThe best divisor is " << best_digit << std::endl;
}

enum {
  DIGITS_IN_NUMBER = 1,
  LUCKY_TICKET,
  REVERSE_NUMBER,
  SUM_ODD_ELEMENTS,
  BEST_DIVISIOR
};

int main() {
  do {
    std::cout << "\n1) Enter 1 | to calculate the sum and arithmetic mean of "
                 "digits in the number."
              << std::endl;
    std::cout << "2) Enter 2 | to check if you have a happy ticket (A ticket "
                 "is considered lucky if the sum of the first three digits of "
                 "the number is equal to the sum of the last three)."
              << std::endl;
    std::cout << "3) Enter 3 | to make a reverse number of number what you "
                 "will be enter  (143-->341)"
              << std::endl;
    std::cout << "4) Enter 4 | to calculate the sum of the odd elements"
              << std::endl;
    std::cout << "5) Enter 5 | to find the best divisior of number"
              << std::endl;
    std::cout << "EXIT: Enter any another key" << std::endl;
    int key{};
    std::cin >> key;
    switch (key) {
    case DIGITS_IN_NUMBER:
      digits_in_number();
      break;
    case LUCKY_TICKET:
      lucky_ticket();
      break;
    case REVERSE_NUMBER:
      reverse_num();
      break;
    case SUM_ODD_ELEMENTS:
      sum_odd_elements();
      break;
    case BEST_DIVISIOR:
      best_divisior();
      break;
    default:
      return 0;
    }
  } while (true);

  return 0;
}
