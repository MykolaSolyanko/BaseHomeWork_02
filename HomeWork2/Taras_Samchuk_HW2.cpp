#include <iostream>
#include <cmath>
#include <limits>
const short K_l = 50;
const char Items[][K_l]{
    "EXIT",
    "Digits summ",
    "Happy ticket",
    "Reverse(!)",
    "The sum of the odd elements",
    "Best divisor(!)",
    "Christmas tree(!)",
    "Count the number of set bits in a number",
    "Bit test"};
const int Items_Count = sizeof(Items) / sizeof(Items[0]);
enum labels
{
  LABEL_EXIT,
  LABEL_DIGITS_SUMM,
  LABEL_HAPPY_TICKET,
  LABEL_REVERSE,
  LABEL_ODD_SUMM,
  LABEL_BEST_DIVISOR,
  LABEL_CHRISTMAS_TREE,
  LABEL_BITS_COUNT,
  LABEL_BITS_TEST,
};
typedef signed long s_long;
s_long GetInInRange(s_long aMin, s_long aMax)
{
  s_long INPUT;
  bool TryAgaine{true};
  do
  {
    std::cout << ">";
    std::cin >> INPUT;
    TryAgaine = aMin > INPUT || INPUT > aMax;
  } while (TryAgaine);
  return INPUT;
}
const short k_digit_10{10};
s_long GetDigit(s_long InputNumber, s_long Digit)
{
  /*
    1) Digit1=(X%10)/1
    2) Digit2=(X%100)/10
    ...
    N) Digit_N=(X%pow(10,N))/pow(10,N-1)
    */
  return (InputNumber % (s_long)pow(k_digit_10, Digit + 1)) / (s_long)pow(k_digit_10, Digit);
}
//================================================================
int MENU()
{
  std::cout << R"(
    +-----------------+
    |   SELECT TASK   |
    +-----------------+)";
  std::cout << std::endl;
  for (size_t i = 0; i < Items_Count; i++)
    std::cout << "\t(" << i << ")  " << Items[i] << std::endl;
  std::cout << "\tEnter the number and press [ENTER]" << std::endl;
  return GetInInRange(0, Items_Count - 1);
}
int DIGITS_SUMM()
{
  std::cout << R"(
    +-----------------+
    |   DIGITS SUMM   |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    | The program breaks the numbers |
    |  into numbers and calculates   |
    | their sum and arithmetic mean  |
    +--------------------------------+
  )";
  // 10 is the minimum two-digit number
  const size_t k_min_limit = 10;
  const size_t k_max_limit = std::numeric_limits<size_t>::max() >> 1;
  std::cout << "\tPlease enter a number\tMust be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  size_t Number = GetInInRange(k_min_limit, k_max_limit);
  std::cout << "The numbers ( ";
  //We decompose the number
  short Digits_Count{0};
  short Digits_Summ{0};
  do
  {
    int Digit = GetDigit(Number, Digits_Count);
    Digits_Summ += Digit;
    std::cout << Digit << " ";
    Digits_Count++;
  } while (Number >= pow(k_digit_10, Digits_Count));
  const double arithmetic_mean = (Digits_Summ + 0.f) / Digits_Count;
  std::cout << ") have the sum equal " << Digits_Summ << " and arithmetic mean " << arithmetic_mean << std::endl;
  return 0;
}
int HAPPY_TICKET()
{
  std::cout << R"(
    +-----------------+
    |  HAPPY TICKET   |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |  The  program  checks  whether |
    |     your ticket is happy       |
    +--------------------------------+
  )";
  const size_t k_min_limit = 0; // identical 000000
  //The maximum six-digit number
  const size_t k_max_limit = 999999;
  std::cout << "\tPlease enter a number\tMust be between 000000 and " << k_max_limit << "!" << std::endl;
  int Number = GetInInRange(k_min_limit, k_max_limit);
  int HiSumm{0};
  int LoSumm{0};
  for (size_t i = 0; i < 3; i++)
  {
    //HiSumm += (TicketNumber % (size_t)pow(k_digit_10, i + 4)) / (size_t)pow(k_digit_10, i+3);
    HiSumm += GetDigit(Number, i);
    //LoSumm += (TicketNumber % (size_t)pow(k_digit_10, i + 1)) / (size_t)pow(k_digit_10, i);
    LoSumm += GetDigit(Number, i + 3);
  }
  if (HiSumm == LoSumm)
  {
    std::cout << "Congratulations to you, Lucky\n";
    return 0;
  }
  std::cout << "Try again, you will surely enjoy it";
  return 0;
}
int REVERSE()
{
  std::cout << R"(
    +-----------------+
    |     REVERSE     |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |  In the process of development |
    +--------------------------------+
  )";
  return 0;
}
int ODD_SUMM()
{
  std::cout << R"(
    +-----------------+
    |    ODD  SUMM    |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |   We   calculate   the   sum   |
    |        of odd numbers          |
    +--------------------------------+
  )";
  const size_t k_count_min_limit = 1;
  const size_t k_count_max_limit = 50;
  std::cout << "\tPlease enter a count numbers\tMust be between " << k_count_min_limit << " and " << k_count_max_limit << "!" << std::endl;
  size_t Counts = GetInInRange(k_count_min_limit, k_count_max_limit);
  size_t Summ{0};
  const int k_min_limit = -60;
  const int k_max_limit = 90;
  for (size_t i = 0; i < Counts; i++)
  {
    std::cout << "Please enter the " << i + 1 << " number" << std::endl;
    std::cout << "Must be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
    size_t Num = GetInInRange(k_min_limit, k_max_limit);
    if (Num & 1)
      Summ += Num;
  }
  std::cout << Summ << std::endl;
  return 0;
}
int BEST_DIVISOR()
{
  std::cout << R"(
    +-----------------+
    |   BESTDIVISOR   |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |  In the process of development |
    +--------------------------------+
  )";
  return 0;
}
int CHRISTMAS_TREE()
{
  std::cout << R"(
    +-----------------+
    |  CHRISTMASTREE  |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |  In the process of development |
    +--------------------------------+
  )";
  return 0;
}
int BITS_COUNT()
{
  std::cout << R"(
    +-----------------+
    |   BITS COUNT    |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |   We count the number of bits  |
    |       established              |
    +--------------------------------+
  )";
  const size_t k_min_limit = 0;
  //The maximum six-digit number
  const size_t k_max_limit = std::numeric_limits<int32_t>::max();
  std::cout << "\tPlease enter a number\tMust be between 0 and " << k_max_limit << "!" << std::endl;
  int Number = GetInInRange(k_min_limit, k_max_limit);
  short Checked{0};
  for (size_t i = 0; i < 32; i++)
  {
    size_t MASK = (size_t)pow(2, i);
    if (Number & MASK)
      Checked++;
  }
  std::cout << "The number " << Number << " have " << Checked << "checked bits" << std::endl;
  return 0;
}
int BITS_TEST()
{
  std::cout << R"(
    +-----------------+
    |    BITS TEST    |
    +-----------------+)";
  std::cout << R"(
    +--------------------------------+
    |  In the process of development |
    +--------------------------------+
  )";
    const size_t k_min_limit = 0;
  //The maximum six-digit number
  const size_t k_max_limit = std::numeric_limits<int32_t>::max();
  const size_t k_max_bits = 32;
  std::cout << "\tPlease enter a number\tMust be between 0 and " << k_max_limit << "!" << std::endl;
  int Number = GetInInRange(k_min_limit, k_max_limit);
  std::cout << "\tEnter a number bit\tMust be between 0 and " << k_max_bits << "!" << std::endl;
  int bit = GetInInRange(k_min_limit, k_max_bits);
  size_t MASK = (size_t)pow(2, bit);
  if(MASK&Number)std::cout<<"YES";else std::cout<<"NO";
  std::cout<<std::endl;
  return 0;
}
int main()
{
  std::cout << R"(
    +-----------------+
    |   HOME WORK 2   |
    +-----------------+)";
  std::cout << std::endl;
  do //forever loop
  {
    switch (MENU())
    {
    case LABEL_EXIT:
      return 0;
      break;
    case LABEL_DIGITS_SUMM:
      DIGITS_SUMM();
      break;
    case LABEL_HAPPY_TICKET:
      HAPPY_TICKET();
      break;
    case LABEL_REVERSE:
      REVERSE();
      break;
    case LABEL_ODD_SUMM:
      ODD_SUMM();
      break;
    case LABEL_BEST_DIVISOR:
      BEST_DIVISOR();
      break;
    case LABEL_CHRISTMAS_TREE:
      CHRISTMAS_TREE();
      break;
    case LABEL_BITS_COUNT:
      BITS_COUNT();
      break;
    case LABEL_BITS_TEST:
      BITS_TEST();
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