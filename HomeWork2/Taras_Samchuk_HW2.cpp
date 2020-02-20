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
const int Names_langth=12;
const char Items[][Names_langth]{
    "Digits summ"
};
enum{LABEL_EXIT,
    LABEL_DIGITS_SUMM,
}
const int Items_Count = sizeof(Items) / sizeof(Items[0]);
//=================================================================================
//    MENU TO SCREEN
//=================================================================================
int PrintMenu()
{
  bool TryAgain {true};
  size_t MyChoice;
  do{
    std::cout << "\tSelect a task"<<std::endl;
    for (size_t i = 0; i < Items_Count; i++)
      std::cout <<"\t("<<i+1<<")  "<< Items[i]<<std::endl;
    std::cout<<"\tEnter the number from 0 to "<<Items_Count<<" and press [ENTER]\n\tType 0 for exit"<<std::endl;
    std::cin>>MyChoice;
    TryAgain=0 > MyChoice || MyChoice > Items_Count;
    if (!TryAgain)break;
  }while (TryAgain);
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
  //Used from homework # 1
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
int main()
{
  do
  {
    std::cout<<std::endl;
    switch (PrintMenu())
    {
    case 0:
      return 0;
      break;
    case 1:
        DigitsSumm();
      break;
    
    default:
      return 0;
      break;
    }
  } while (true);
  return 0;
}