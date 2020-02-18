#include <cmath>
#include <iostream>
// Equation ax^2+bx+c=0
// Equation solution x1=(-b+sqrt(b^2-4ac))/(2a);x2=(-b-sqrt(b^2-4ac))/(2a);
//Koefficient calculation k1=x1-x2 (distance); k2=x1/x2 (ratio);
/*Decision limitations for output real roots
a>0 range [2...255];
b>0 range [2...255];
c>0 range [0...b*b/(4*a)];
*/
int main() {
  int a, amin, amax, b, bmin, bmax, c, cmin, cmax;
  double D, x1, x2;
  const int i2 = 2, i4 = 4;
  amin = 2;
  amax = 255;
  bmin = 2;
  bmax = 255;
  cmin = 0;

  std::cout << "\tSolution of equation "
               "ax^2+bx+c=0\n\tx1=(-b+sqrt(b^2-4ac))/"
               "(2a);\n\tx2=(-b-sqrt(b^2-4ac))/(2a);"
            << std::endl;
  std::cout << "\tOutput real roots" << std::endl;
  std::cout << "\tPlease, enter number a in range [2...255]" << std::endl;
  std::cin >> a;
  while ((a < amin) || (a > amax)) {
    std::cout << "\tYou enter an incorrect number in range [2...255]"
              << std::endl;
    std::cin >> a;
  }
  std::cout << "\tPlease, enter number b in range [2...255]" << std::endl;
  std::cin >> b;
  while ((b < bmin) || (b > bmax)) {
    std::cout << "\tYou enter an incorrect number in range [2...255]"
              << std::endl;
    std::cin >> b;
  }
  double temp1 = 1. * b * b / (i4 * a);
  int ival = static_cast<int>(temp1);
  cmax = ival;
  std::cout << "\tPlease, enter number c in range [0..." << cmax << "]"
            << std::endl;
  std::cin >> c;
  while ((c > cmax)) {
    std::cout << "\tYou enter an incorrect number in range [0..." << cmax << "]"
              << std::endl;
    std::cin >> c;
  }
  D = 1. * b * b - i4 * a * c;

  x1 = (-1 * b + sqrt(D)) / (i2 * a);
  std::cout << "\tRoot_1 = " << x1 << std::endl;
  x2 = (-1 * b - sqrt(D)) / (i2 * a);
  std::cout << "\tRoot_2 = " << x2 << "\n" << std::endl;

  //Ñoefficient calculation k1=x1-x2 (distance); k2=x1/x2 (ratio);
  double k1, k2;
  k1 = x1 - x2;
  k2 = x2 / x1;
  std::cout
      << "\tCoefficient calculation k1=x1-x2 (distance); k2=x1/x2 (ratio)\n"
      << std::endl;
  std::cout << "\tk1=" << k1 << "\tk2=" << k2 << std::endl;
  return 0;
}
