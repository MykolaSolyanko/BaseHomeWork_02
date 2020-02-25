#include <iostream>
#include <cmath>
#include <limits>
//Constant for show menu sub programs
const short K_l = 50;
const char k_Items[][K_l]{
    "EXIT",
    "Digits summ",
    "Happy ticket",
    "Reverse",
    "The sum of the odd elements",
    "Best divisor",
    "Christmas tree",
    "Count the number of set bits in a number",
    "Bit test"};
const size_t k_Items_Count = sizeof(k_Items) / sizeof(k_Items[0]);
enum labels
{
  Label_Exit,
  Label_Digits_Summ,
  Label_Happy_Ticket,
  Label_Reverse,
  Label_Odd_Summ,
  Label_Best_Divisor,
  Label_Christmas_Tree,
  Label_Bits_Count,
  Label_Bits_Test
};

//The function returns a value if it is within the range.
//Executes until the correct value is entered
int64_t GetInInRange(int64_t aMin, int64_t aMax)
{
  int64_t Input;
  bool TryAgaine{true};
  do
  {
    std::cout << ">";
    std::cin >> Input;
    TryAgaine = aMin > Input || Input > aMax;
  } while (TryAgaine);
  return Input;
}

const short k_digit_10{10};

//The function breaks the number into digits
int64_t GetDigit(int64_t InputNumber, size_t Digit)
{
  /*
    1) Digit1=(X%10)/1
    2) Digit2=(X%100)/10
    ...
    N) Digit_N=(X%pow(10,N))/pow(10,N-1)
    */
  return (InputNumber % (int64_t)pow(k_digit_10, Digit + 1)) / (int64_t)pow(k_digit_10, Digit);
}
//Displays the menu and returns the selected item number
int Menu()
{
  std::cout << R"(
    +-----------------+
    |   SELECT TASK   |
    +-----------------+)";
  std::cout << std::endl;
  for (size_t i = 0; i < k_Items_Count; i++)
    std::cout << "\t(" << i << ")  " << k_Items[i] << std::endl;
  std::cout << "\tEnter the number and press [ENTER]" << std::endl;
  return GetInInRange(0, k_Items_Count - 1);
}

//home work
int Digits_Summ()
{
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
  //Almost the maximum for this type
  const size_t k_max_limit = std::numeric_limits<size_t>::max() >> 1;
  std::cout << "\tPlease enter a number\n\tMust be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  size_t Number = GetInInRange(k_min_limit, k_max_limit);
  std::cout << "The numbers ( ";
  //We decompose the number
  short Digits_Count{0};
  short Digits_Summ{0};
  do
  {
    size_t Digit = GetDigit(Number, Digits_Count);
    Digits_Summ += Digit;
    std::cout << Digit << " ";
    Digits_Count++;
  } while (Number >= pow(k_digit_10, Digits_Count));
  const double k_arithmetic_mean = (Digits_Summ + 0.f) / Digits_Count;
  std::cout << ") have the sum equal " << Digits_Summ << " and arithmetic mean " << k_arithmetic_mean << std::endl;
  return 0;
}
int Happy_Ticket()
{
  std::cout << R"(
    +-----------------+
    |  HAPPY TICKET   |
    +-----------------+
    +--------------------------------+
    |  The  program  checks  whether |
    |     your ticket is happy       |
    +--------------------------------+
  )";
  const size_t k_min_limit = 0; // identical 000000
  //The maximum six-digit number
  const size_t k_max_limit = 999999;
  std::cout << "\tPlease enter a number\n\tMust be between 000000 and " << k_max_limit << "!" << std::endl;
  size_t Number = GetInInRange(k_min_limit, k_max_limit);
  short HiSumm{0};
  short LoSumm{0};
  for (size_t i = 0; i < 3; i++)
  {
    //HiSumm += (TicketNumber % (size_t)pow(k_digit_10, i + 4)) / (size_t)pow(k_digit_10, i+3);
    HiSumm += GetDigit(Number, i);
    //LoSumm += (TicketNumber % (size_t)pow(k_digit_10, i + 1)) / (size_t)pow(k_digit_10, i);
    LoSumm += GetDigit(Number, i + 3);
  }
  if (HiSumm == LoSumm)
  {
    std::cout << "Congratulations to you, Lucky" << std::endl;
    return 0;
  }
  std::cout << "Try again, you will surely enjoy it\n";
  return 0;
}
int Reverse()
{
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
  std::cout << "\tPlease enter a count numbers\n\tMust be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  size_t Digits_Count{0};
  int64_t Number = GetInInRange(k_min_limit, k_max_limit);
  const bool k_Negative = Number < 0;
  if (k_Negative)
    Number = -Number;
  do
  {
    //size_t Digit = GetDigit(Number, Digits_Count);
    Digits_Count++;
  } while (Number >= pow(k_digit_10, Digits_Count));
  int64_t NewNumber{0};
  for (size_t i = 0; i < Digits_Count; i++)
  {
    NewNumber = pow(k_digit_10, i) * GetDigit(Number, Digits_Count - i - 1) + NewNumber;
  }
  if (k_Negative)
    NewNumber = -NewNumber;
  std::cout << NewNumber;

  return 0;
}
int Odd_Summ()
{
  std::cout << R"(
    +-----------------+
    |    ODD  SUMM    |
    +-----------------+
    +--------------------------------+
    |   We   calculate   the   sum   |
    |        of odd numbers          |
    +--------------------------------+
  )";
  const size_t k_count_min_limit = 1;  //Constants of exercise conditions
  const size_t k_count_max_limit = 50; //Constants of exercise conditions
  std::cout << "\tPlease enter a count numbers\n\tMust be between " << k_count_min_limit << " and " << k_count_max_limit << "!" << std::endl;
  size_t Counts = GetInInRange(k_count_min_limit, k_count_max_limit);
  int Summ{0};
  const int k_min_limit = -60; //Constants of exercise conditions
  const int k_max_limit = 90;  //Constants of exercise conditions
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
int Best_Divisor()
{
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
  std::cout << "\tPlease enter a count numbers\n\tMust be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  const int Number = GetInInRange(k_min_limit, k_max_limit);
  int MaxDivisor{1};
  int BestDivisor{Number};
  int MaxSum{0};
  int Digits_Summ{0};
  for (size_t i = 2; i < Number; i++)
  {
    if (Number % i == 0)
    {
      if (i == Number - 1)
        MaxDivisor = i;
      if (i > 10)
      {
        size_t Digits_Count{0};
        do
        {
          int Digit = GetDigit(i, Digits_Count);
          Digits_Summ += Digit;
          Digits_Count++;
        } while (i >= pow(k_digit_10, Digits_Count));
        if (Digits_Summ > MaxSum)
        {
          MaxSum = Digits_Summ;
          BestDivisor = i;
        }
      }
    }
  }
  std::cout << BestDivisor << " is the best divisor of the number " << Number << std::endl;
  return 0;
}
int Christmas_Tree()
{
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
  std::cout << "\tPlease enter size of tree\n\tMust be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  size_t size;
  do
  {
    size = GetInInRange(k_min_limit, k_max_limit);
    if (size % 2 != 0)
      break;
    std::cout << "Please enter an odd number " << std::endl;
  } while (true);
  const size_t k_center_align = size / 2;
  for (size_t y = 0; y <= k_center_align; y++)
  {
    const char k_star = '*';
    const char k_spase = ' ';
    for (size_t x = 0; x < size; x++)
    {
      size_t left_align = k_center_align - y;
      size_t rihgt_align = k_center_align + y;
      if (left_align <= x && x <= rihgt_align)
        std::cout << k_star;
      else
        std::cout << k_spase;
    }

    std::cout << std::endl;
  }
  return 0;
}
int Bit_Count()
{
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
  std::cout << "\tPlease enter a number\n\tMust be between 0 and " << k_max_limit << "!" << std::endl;
  int Number = GetInInRange(k_min_limit, k_max_limit);
  short Checked{0};
  for (size_t i = 0; i < 32; i++)
  {
    //size_t MASK = (size_t)pow(2, i);
    size_t MASK = 1LL << i;
    if (Number & MASK)
      Checked++;
  }
  std::cout << "The number " << Number << " have " << Checked << " checked bits" << std::endl;
  return 0;
}
int Bits_Test()
{
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
  const size_t k_max_bits = 32;
  std::cout << "\tPlease enter a number\n\tMust be between " << k_min_limit << " and " << k_max_limit << "!" << std::endl;
  int const k_Number = GetInInRange(k_min_limit, k_max_limit);
  std::cout << "\tEnter a number bit\n\tMust be between " << k_min_limit << " and " << k_max_bits << "!" << std::endl;
  int bit = GetInInRange(k_min_limit, k_max_bits);
  //size_t MASK = (size_t)pow(2, bit);
  size_t MASK = 1LL << bit;
  if (MASK & k_Number)
    std::cout << "YES";
  else
    std::cout << "NO";
  std::cout << std::endl;
  return 0;
}

//main progamm
int main()
{
  std::cout << R"(
    +-----------------+
    |   HOME WORK 2   |
    +-----------------+)";
  do //forever loop
  {
    switch (Menu())
    {
    case Label_Exit:
      return 0;
      break;
    case Label_Digits_Summ:
      Digits_Summ();
      break;
    case Label_Happy_Ticket:
      Happy_Ticket();
      break;
    case Label_Reverse:
      Reverse();
      break;
    case Label_Odd_Summ:
      Odd_Summ();
      break;
    case Label_Best_Divisor:
      Best_Divisor();
      break;
    case Label_Christmas_Tree:
      Christmas_Tree();
      break;
    case Label_Bits_Count:
      Bit_Count();
      break;
    case Label_Bits_Test:
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