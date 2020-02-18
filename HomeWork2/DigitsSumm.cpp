//Samchuk Taras
//DigitsSumm.cpp
//18-02-20 (22:43)
#include <iostream>
#include <cmath>
#include <limits>
int main(/*int argc, char const *argv[]*/)
{
  std::cout << R"(
      +--------------------------------+
      | The program breaks the numbers |
      |  into numbers and calculates   |
      | their sum and arithmetic mean  |
      +--------------------------------+
  )";
  //Used from homework # 1
  std::cout << "\tPlease enter a number" << std::endl;
  // 10 is the minimum two-digit number
  const size_t k_min_limit = 10;
  // "almost max" for this type
  const size_t k_max_limit = std::numeric_limits<size_t>::max()>>1;
  size_t Number;
  bool Incorrect;//true=incorrect; false=correct;
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
  std::cout << ") have the sum equal " << Digits_Summ << 
               " and arithmetic mean " <<arithmetic_mean<< std::endl;
  return 0;
}
