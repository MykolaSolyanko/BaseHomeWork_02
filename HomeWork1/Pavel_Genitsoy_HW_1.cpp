#include <cmath>
#include <iostream>

int main() {
  std::cout << "A*x^2+B*x+C=0, where A, B and C are the coefficients of the "
               "equation and  x  is the root of the equation"
            << std::endl;
  const int min_Range{2};
  const int max_Range{255};
  std::cout << "\nPlease enter 3 coefficients (A,B,C) in range [" << min_Range
            << ".." << max_Range << "].\nSo, lets start from A = ";
  int a{};
  while (std::cin >> a && (a < min_Range || a > max_Range)) {
    std::cout << "You entered an incorrect number, try entering the number "
                 "again.\nEnter num: ";
  }
  std::cout << "A = " << a << "\nEnter next num is B = ";
  int b{};
  while (std::cin >> b && (b < min_Range || b > max_Range)) {
    std::cout << "You entered an incorrect number, try entering the number "
                 "again.\nEnter num: ";
  }
  std::cout << "B = " << b << "\nEnter next num is C = ";
  int c{};
  while (std::cin >> c && (c < min_Range || c > max_Range)) {
    std::cout << "You entered an incorrect number, try entering the number "
                 "again.\nEnter num: ";
  }
  std::cout << "C = " << c << "\nNow check our equation: " << a << "*x^2+" << b
            << "*x+" << c << "=0" << std::endl;

  const int L_4{4};
  const int L_2{2};
  const auto D{pow(b, 2) - L_4 * a * c};
  int x1{}, x2{};
  if (D > 0) {
    x1 = (-b - sqrt(D)) / (L_2 * a);
    x2 = (-b + sqrt(D)) / (L_2 * a);
    std::cout << "First root is x1=" << x1 << ", and second is x2=" << x2
              << std::endl;
    return 0;
  }
  if (D == 0) {
    x1 = -b / (L_2 * a);
    std::cout << "Only 1 root is x =" << x1 << std::endl;
    return 0;
  }
  std::cout << "Real roots are not exist" << std::endl; 
  return 0;
}
