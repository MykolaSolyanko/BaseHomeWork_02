#include <cmath>
#include <iostream>
#include <limits>
// Constant for show menu sub programs
const short k_item_len = 50;
const short k_digit_10{10};
const size_t k_max_bits = 31;
enum Label {
  LABEL_EXIT = 0,
  LABEL_DIGITS_SUMM,
  LABEL_HAPPY_TICKET,
  LABEL_REVERSE,
  LABEL_ODD_SUMM,
  LABEL_BEST_DIVISOR,
  LABEL_CHRISTMAS_TREE,
  LABEL_BITS_COUNT,
  LABEL_BITS_TEST,
  LABEL_COUNT
};
const char k_Items[LABEL_COUNT][k_item_len]{
    "EXIT", //
    "Digits summ",
    "Happy ticket",
    "Reverse",
    "The sum of the odd elements",
    "Best divisor",
    "Christmas tree",
    "Count the number of set bits in a number",
    "Bit test"};

// The function returns a value if it is within the range.
// Executes until the correct value is entered
int64_t GetInInRange(const int64_t aMin,const int64_t aMax) {
  int64_t Input;
  do {
    std::cout << ">";
    std::cin >> Input;
  } while (aMin > Input || Input > aMax);
  return Input;
}

// The function breaks the number into digits
int64_t GetDigit(const int64_t InputNumber,const size_t Digit) {
  /*
    1) Digit1=(X%10)/1
    2) Digit2=(X%100)/10
    ...
    N) Digit_N=(X%pow(10,N))/pow(10,N-1)
    */
  return (InputNumber % static_cast<int64_t>((pow(k_digit_10, Digit + 1)))) /
         static_cast<int64_t>((pow(k_digit_10, Digit)));
}

// Displays the menu and returns the selected item number
int Menu() {
  std::cout << R"(
    +-----------------+
    |   SELECT TASK   |
    +-----------------+)";
  std::cout << std::endl;
  for (size_t i = 0; i < LABEL_COUNT; i++) {
    std::cout << "\t(" << i + 1 << ")  " << k_Items[i] << std::endl;
  }
  std::cout << "\tEnter the number and press [ENTER]" << std::endl;
  return GetInInRange(1, LABEL_COUNT) - 1;
}

// home work
void Digits_Summ() {
  std::cout << R"(
    +-----------------+
    |   DIGITS SUMM   |
    +-----------------+
    +--------------------------------+
    | The program breaks the numbers |
    |  into numbers and calculates   |
    | their sum and arithmetic mean  |
    +--------------------------------+
  )";
  // 10 is the minimum two-digit number
  const size_t k_min_limit = 10;
  // Almost the maximum for this type
  const size_t k_max_limit = std::numeric_limits<u_int32_t>::max();
  ;
  std::cout << "\tPlease enter a number\n\tMust be between " << k_min_limit
            << " and " << k_max_limit << "!" << std::endl;
  const size_t Number = GetInInRange(k_min_limit, k_max_limit);
  std::cout << "The numbers ( ";
  // We decompose the number
  short Digits_Count{0};
  short Digits_Summ{0};
  do {
    size_t Digit = GetDigit(Number, Digits_Count);
    Digits_Summ += Digit;
    std::cout << Digit << " ";
    Digits_Count++;
  } while (Number >= pow(k_digit_10, Digits_Count));
  const double k_arithmetic_mean = (Digits_Summ + 0.f) / Digits_Count;
  std::cout << ") have the sum equal " << Digits_Summ << " and arithmetic mean "
            << k_arithmetic_mean << std::endl;
  ;
}

void Happy_Ticket() {
  std::cout << R"(
    +-----------------+
    |  HAPPY TICKET   |
    +-----------------+
    +--------------------------------+
    |  The  program  checks  whether |
    |     your ticket is happy       |
    +--------------------------------+
  )";
  const size_t k_min_limit = 0; // identical 000'000
  // The maximum six-digit number
  const size_t k_max_limit = 999'999;
  const size_t k_min_happy_ticket = 1'001; // identical 001'001
  std::cout << "\tPlease enter a number\n\tMust be between 000000 and "
            << k_max_limit << "!" << std::endl;
  const size_t Number = GetInInRange(k_min_limit, k_max_limit);
  if (Number >= k_min_happy_ticket) {
    short LSumm{0};
    short RSumm{0};
    for (size_t i = 0; i < 3; i++) {
      LSumm += GetDigit(Number, i);
      RSumm += GetDigit(Number, i + 3);
    }
    std::cout << ((LSumm == RSumm) ? "Congratulations to you, Lucky"
                                   : "Try again, you will surely enjoy it")
              << std::endl;
  }
}

void Reverse() {
  std::cout << R"(
    +-----------------+
    |     REVERSE     |
    +-----------------+
    +--------------------------------+
    |  In the process of development |
    +--------------------------------+
  )";
  const int64_t k_min_limit = std::numeric_limits<int32_t>::min();
  const int64_t k_max_limit = std::numeric_limits<int32_t>::max();
  std::cout << "\tPlease enter a count numbers\n\tMust be between "
            << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  size_t Digits_Count{0};
  int64_t Number = GetInInRange(k_min_limit, k_max_limit);
  bool k_Negative = Number < 0;
  Number = (k_Negative) ? -Number : Number;
  do {
    Digits_Count++;
  } while (Number >= pow(k_digit_10, Digits_Count));
  int64_t NewNumber{0};
  for (size_t i = 0; i < Digits_Count; i++) {
    NewNumber =
        pow(k_digit_10, i) * GetDigit(Number, Digits_Count - i - 1) + NewNumber;
  }
  NewNumber = (k_Negative) ? -NewNumber : NewNumber;
  std::cout << NewNumber;
}

void Odd_Summ() {
  std::cout << R"(
    +-----------------+
    |    ODD  SUMM    |
    +-----------------+
    +--------------------------------+
    |   We   calculate   the   sum   |
    |        of odd numbers          |
    +--------------------------------+
  )";
  const size_t k_count_min_limit = 1;  // Constants of exercise conditions
  const size_t k_count_max_limit = 50; // Constants of exercise conditions
  std::cout << "\tPlease enter a count numbers\n\tMust be between "
            << k_count_min_limit << " and " << k_count_max_limit << "!"
            << std::endl;
  size_t Counts = GetInInRange(k_count_min_limit, k_count_max_limit);
  int Summ{0};
  const int k_min_limit = -60; // Constants of exercise conditions
  const int k_max_limit = 90;  // Constants of exercise conditions
  for (size_t i = 0; i < Counts; i++) {
    std::cout << "Please enter the " << i + 1 << " number" << std::endl;
    std::cout << "Must be between " << k_min_limit << " and " << k_max_limit
              << "!" << std::endl;
    size_t Num = GetInInRange(k_min_limit, k_max_limit);
    Summ = (Num & 1) ? Summ + Num : Summ;
  }
  std::cout << Summ << std::endl;
}
void Best_Divisor() {
  std::cout << R"(
    +-----------------+
    |   BESTDIVISOR   |
    +-----------------+
    +--------------------------------+
    |     Finds the best divisor     |
    |         for the number         |
    +--------------------------------+
  )";
  const int k_min_limit = 1;
  const int k_max_limit = std::numeric_limits<int>::max();
  std::cout << "\tPlease enter a count numbers\n\tMust be between "
            << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  const int Number = GetInInRange(k_min_limit, k_max_limit);
  int BestDivisor{Number};
  int MaxSum{0};
  int Digits_Summ{0};
  for (size_t i = 2; i < Number; i++) {
    if (Number % i == 0) {
      if (i > 10) {
        size_t Digits_Count{0};
        do {
          int Digit = GetDigit(i, Digits_Count);
          Digits_Summ += Digit;
          Digits_Count++;
        } while (i >= pow(k_digit_10, Digits_Count));
        if (Digits_Summ > MaxSum) {
          MaxSum = Digits_Summ;
          BestDivisor = i;
        }
      }
    }
  }
  std::cout << BestDivisor << " is the best divisor of the number " << Number
            << std::endl;
}
void Christmas_Tree() {
  std::cout << R"(
    +-----------------+
    |  CHRISTMASTREE  |
    +-----------------+
    +--------------------------------+
    |  In the process of development |
    +--------------------------------+
  )";
  const size_t k_min_limit = 1;
  const size_t k_max_limit = 79;
  std::cout << "\tPlease enter size of tree\n\tMust be between " << k_min_limit
            << " and " << k_max_limit << "!" << std::endl;
  size_t size;
  do {
    size = GetInInRange(k_min_limit, k_max_limit);
    if (size % 2 != 0)
      break;
    std::cout << "Please enter an odd number " << std::endl;
  } while (true);
  const size_t k_center_align = size / 2;
  for (size_t y = 0; y <= k_center_align; y++) {
    for (size_t x = 0; x < size; x++) {
      const char k_star = '*';
      const char k_spase = ' ';
      size_t left_align = k_center_align - y;
      size_t rihgt_align = k_center_align + y;
      std::cout << ((left_align <= x && x <= rihgt_align) ? k_star : k_spase);
    }
    std::cout << std::endl;
  }
}

void Bit_Count() {
  std::cout << R"(
    +-----------------+
    |   BITS COUNT    |
    +-----------------+
    +--------------------------------+
    |   We count the number of bits  |
    |       established              |
    +--------------------------------+
  )";
  const size_t k_min_limit = 0;
  const size_t k_max_limit = std::numeric_limits<u_int32_t>::max();
  std::cout << "\tPlease enter a number\n\tMust be between 0 and "
            << k_max_limit << "!" << std::endl;
  int Number = GetInInRange(k_min_limit, k_max_limit);
  short Checked{0};
  for (size_t i = 0; i <= k_max_bits; i++) {
    size_t MASK = 1LL << i;
    Checked = (Number & MASK) ? Checked + 1 : Checked;
  }
  std::cout << "The number " << Number << " have " << Checked << " checked bits"
            << std::endl;
}
void Bits_Test() {
  std::cout << R"(
    +-----------------+
    |    BITS TEST    |
    +-----------------+
    +--------------------------------+
    |  Check whether the bit is set  |
    |  to the number by  its number  |
    +--------------------------------+
  )";
  const size_t k_min_limit = 0;
  const size_t k_max_limit = std::numeric_limits<u_int32_t>::max();
  std::cout << "\tPlease enter a number\n\tMust be between " << k_min_limit
            << " and " << k_max_limit << "!" << std::endl;
  int const k_Number = GetInInRange(k_min_limit, k_max_limit);
  std::cout << "\tEnter a number bit\n\tMust be between " << k_min_limit
            << " and " << k_max_bits << "!" << std::endl;
  int bit = GetInInRange(k_min_limit, k_max_bits);
  size_t MASK = 1LL << bit;
  std::cout << ((MASK & k_Number) ? "YES" : "NO") << std::endl;
}

// main progamm
int main() {
  std::cout << R"(
    +-----------------+
    |   HOME WORK 2   |
    +-----------------+)";
  do // forever loop
  {
    switch (Menu()) {
    case LABEL_EXIT:
      return 0;
      break;
    case LABEL_DIGITS_SUMM:
      Digits_Summ();
      break;
    case LABEL_HAPPY_TICKET:
      Happy_Ticket();
      break;
    case LABEL_REVERSE:
      Reverse();
      break;
    case LABEL_ODD_SUMM:
      Odd_Summ();
      break;
    case LABEL_BEST_DIVISOR:
      Best_Divisor();
      break;
    case LABEL_CHRISTMAS_TREE:
      Christmas_Tree();
      break;
    case LABEL_BITS_COUNT:
      Bit_Count();
      break;
    case LABEL_BITS_TEST:
      Bits_Test();
      break;
    default:
      break;
    }
  } while (true);
  std::cout << R"(
    +-----------------+
    |      E N D      |
    +-----------------+)";
  return 0;
}