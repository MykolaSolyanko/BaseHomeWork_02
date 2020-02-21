//Samchuk Taras
//DigitsSumm.cpp
//18-02-20 (22:43)
#include <iostream>
#include <cmath>
#include <limits>
//=================================================================================
//    INTRO
//=================================================================================
int Intro(void)
{
  std::cout << R"(
  +------------------+
)";
  return 0;
}
//=================================================================================
//    CONSTANTS
//=================================================================================
const int Names_langth = 52;
const char Items[][Names_langth]{
    "Digits summ",
    "Happy ticket",
    // "Reverse",
    // "The sum of the odd elements",
    // "Best divisor",
    // "Christmas tree",
    // "Count the number of set bits in a number",
    // "Bit test"
};
enum
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
const int Items_Count = sizeof(Items) / sizeof(Items[0]);
//=================================================================================
//    MENU TO SCREEN
//=================================================================================
int PrintMenu()
{
  bool TryAgain{true};
  size_t MyChoice;
  do
  {
    std::cout << "\tSelect a task" << std::endl;
    for (size_t i = 0; i < Items_Count; i++)
      std::cout << "\t(" << i + 1 << ")  " << Items[i] << std::endl;
    std::cout << "\tEnter the number from 0 to " << Items_Count << " and press [ENTER]\n\tType 0 for exit" << std::endl;
    std::cin >> MyChoice;
    TryAgain = 0 > MyChoice || MyChoice > Items_Count;
    if (!TryAgain)
      break;
  } while (TryAgain);
  return MyChoice;
}
//=================================================================================
//    SUB PROGRAMMs
//=================================================================================

int DigitsSumm()
{
  std::cout << R"(
      +--------------------------------+
      | The program breaks the numbers |
      |  into numbers and calculates   |
      | their sum and arithmetic mean  |
      +--------------------------------+
  )";
  std::cout << "\tPlease enter a number" << std::endl;
  // 10 is the minimum two-digit number
  const size_t k_min_limit = 10;
  // "almost max" for this type
  const size_t k_max_limit = std::numeric_limits<size_t>::max() >> 1;
  size_t Number;
  bool Incorrect; //true=incorrect; false=correct;
  //We get the number
  do
  {
    std::cout << "NUMBER=";
    std::cin >> Number;
    Incorrect = (Number < k_min_limit) || (Number > k_max_limit);
    if (Incorrect)
    {
      std::cout << "\tYou entered an incorrect number.\n"
                   "\tMust be between "
                << k_min_limit << " and " << k_max_limit << "!" << std::endl;
    }
  } while (Incorrect);
  std::cout << "The numbers ( ";
  //We decompose the number
  const short k_digit_10 = 10;
  short Digits_Count{0};
  short Digits_Summ{0};
  do
  {
    /*
    1) Digit1=(X%10)/1
    2) Digit2=(X%100)/10
    ...
    N) Digit_N=(X%pow(10,N))/pow(10,N-1)
    */
    int Digit = (Number % (size_t)pow(k_digit_10, Digits_Count + 1)) / (size_t)pow(k_digit_10, Digits_Count);
    Digits_Summ += Digit;
    std::cout << Digit << " ";
    Digits_Count++;
  } while (Number > pow(k_digit_10, Digits_Count));
  const double arithmetic_mean = (Digits_Summ + 0.f) / Digits_Count;
  std::cout << ") have the sum equal " << Digits_Summ << " and arithmetic mean " << arithmetic_mean << std::endl;
  return 0;
}
//=================================================================================
//    MAIN PROGRAMM
//=================================================================================
int HappyTicket()
{
  std::cout << R"(
      +--------------------------------+
      |  The  program  checks  whether |
      |     your ticket is happy       |
      +--------------------------------+
  )";
  std::cout << "\tPlease enter a number" << std::endl;
  const size_t k_min_limit = 0; // identical 000000
  //The maximum six-digit number
  const size_t k_max_limit = 999999;
  bool Incorrect; //true=incorrect; false=correct;
  unsigned int TicketNumber;
  do
  {
    std::cout << "TICKET=";
    std::cin >> TicketNumber;
    Incorrect = (TicketNumber < k_min_limit) || (TicketNumber > k_max_limit);
    if (Incorrect)
    {
      std::cout << "\tYou entered an incorrect ticket number.\n"
                   "\tMust be between 000000 and " << k_max_limit << "!" << std::endl;
    }
  } while (Incorrect);
  unsigned int HiSumm{0};
  unsigned int LoSumm{0};
  for (size_t i = 0; i < 3; i++)
  {
    const short k_digit_10 = 10;
    HiSumm += (TicketNumber % (size_t)pow(k_digit_10, i + 4)) / (size_t)pow(k_digit_10, i+3);
    LoSumm += (TicketNumber % (size_t)pow(k_digit_10, i + 1)) / (size_t)pow(k_digit_10, i);
  }
  if(HiSumm==LoSumm)
  {
    std::cout<<"Congratulations to you, Lucky\n";
    return 0;
  }
  std::cout<<"Try again, you will surely enjoy it";
  return 0;
}
//=================================================================================
//    MAIN PROGRAMM
//=================================================================================
int main()
{
  do
  {
    std::cout << std::endl;
    switch (PrintMenu())
    {
    case LABEL_EXIT:
      return 0;
      break;
    case LABEL_DIGITS_SUMM:
      DigitsSumm();
      break;
    case LABEL_HAPPY_TICKET:
      HappyTicket();
      break;
    case LABEL_REVERSE:
      return 0;
      break;
    case LABEL_ODD_SUMM:
      return 0;
      break;
    case LABEL_BEST_DIVISOR:
      return 0;
      break;
    case LABEL_CHRISTMAS_TREE:
      return 0;
      break;
    case LABEL_BITS_COUNT:
      return 0;
      break;
    case LABEL_BITS_TEST:
      return 0;
      break;
    default:
      return 0;
      break;
    }
  } while (true);
  return 0;
}