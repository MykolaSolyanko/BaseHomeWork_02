// Samchuk Taras
// Homework # 1
// 16-02-20
//Solving the Quadratic Equation
#include <iostream>
#include <limits>
#include <cmath>
int main()
{
  //intro
  std::cout <<
      R"(
    +--------------------------------------+
    | A program for solving a square swing |
    |   The  equation  looks  like  this   |
    |                                      |
    |          a*x^2+b*x+c=0               |
    |                                      |
    |  ,where                              |
    | a, b and c are the coefficients of   |
    |             the equation             |
    |    x     is the root of the equation |
    +--------------------------------------+

)";
  std::cout << "Enter the coefficients" << std::endl;
  //Determination of the minimum number
  const short k_min_short = std::numeric_limits<short>::min();
  //Determination of maximum number
  const short k_max_short = std::numeric_limits<short>::max();
  //We show the message what number to enter
  std::cout << "Must be an integer between " << k_min_short << " and " << k_max_short << "!" << std::endl;
  //will check for the correct number input
  bool incorrect{true}; //true = wrong number, false = correct number
  //coefficient a
  int a;
  do
  {
    //We output the message that we need
    std::cout << "a=";
    //We read values
    std::cin >> a;
    //check if we are in range
    incorrect = (a < k_min_short) || (a > k_max_short);
    if (incorrect)
    {
      //We are reporting that we have gone beyond the range
      std::cout << "\tYou entered an incorrect number.\n"
                   "\tMust be between "
                << k_min_short << " and " << k_max_short << "!" << std::endl;
      //We ask "a =" again
      continue;
    }
    //we are in the range, but should not be zero because it is already a linear equation
    if (a == 0)
    {
      //we inform that zero is entered
      std::cout << "\tYou entered an incorrect number.\n"
                   "\tCan't be zero"
                << std::endl;
      //the number entered is incorrect
      incorrect = true;
    }
    //if incorrectly repeat the request
  } while (incorrect);
  //we enter the coefficient b according to the same algorithm as a, but we do not perform a zero check
  int b;
  do
  {
    std::cout << "b=";
    std::cin >> b;
    incorrect = (b < k_min_short) || (b > k_max_short);
    if (incorrect)
    {
      std::cout << "\tYou entered an incorrect number.\n"
                   "\tMust be between "
                << k_min_short << " and " << k_max_short << "!" << std::endl;
    }
  } while (incorrect);
  //enter the coefficient c as well as enter b
  int c;
  do
  {
    std::cout << "c=";
    std::cin >> c;
    incorrect = (c < k_min_short) || (c > k_max_short);
    if (incorrect)
    {
      std::cout << "\tYou entered an incorrect number.\n"
                   "\tMust be between "
                << k_min_short << " and " << k_max_short << "!" << std::endl;
    }
  } while (incorrect);
  //we derive the equation with the coefficients
  std::cout << "\t\t" << a << "*x^2+" << b << "*x+" << c << "=0" << std::endl;
  //"magic" 4
  const long k_digit_4 = 4;
  //we calculate the discriminant
  const long long k_D = (b * b) - (k_digit_4 * a * c);
  //we analyze the discriminant
  //if less than zero
  if (k_D < 0)
  {
    //we say that the equation has no real solutions
    std::cout << "\tThis equation has no real roots." << std::endl;
    //and complete the program
    return 0; //the program is executed without errors
  }
  /*
      formula is used to calculate the roots of the equation
          x1 = (- b + sqrt (D)) / (2 * a)
          x1 = (- b - sqrt (D)) / (2 * a)
      if D = 0 the root equations are equal to each other x1 = x2 so we only calculate one value.
      if D> 0 we have two possible roots, then we will calculate by both formulas
      In the formulas, the denominators are the same, so as not to calculate one and also make twice
      2 * a into a separate literal denominator, and calculate it once
      sqrt (D) also make a separate literal only once
      Our formulas
          denominator = 2 * a
          sqrt_D = sqrt (D)
          x1 = (- b + sqrt_D) / denominator
          x2 = (- b - sqrt_D) / denominator
  */

  //"magic" 2
  const int k_digit_2 = 2;
  //calculation
  const double k_denominator = k_digit_2 * a;//It is calculated once
  const double k_sqrt_D = sqrt(k_D);
  const double k_x1 = (-b + k_sqrt_D) / k_denominator;
  //If the discriminant is zero
  if (k_D == 0)
  {
    //we have one root
    std::cout << "\tThis equation has one root." << std::endl;
    //output it
    std::cout << "\tx=" << k_x1 << std::endl;
    //and complete the program
    return 0; //the program is executed without errors
  }
  //else
  // we have two possible roots
  std::cout << "\tThis equation has two roots." << std::endl;
  //calculation x2
  const double k_x2 = (-b - k_sqrt_D) / k_denominator;//It is calculated once
  // output it
  std::cout << "\tx=" << k_x1 << " and x=" << k_x2 << std::endl;
  //and complete the program
  return 0; //the program is executed without errors
  // the end of the program
}
//EOF