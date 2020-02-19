#include <cmath>
#include <iostream>

int main() {

  long int a{}, b{}, c{};

  long const min_val = std::numeric_limits<int>::min();
  long const max_val = std::numeric_limits<int>::max();

  std::cout << "To solve a quadratic equation \n\tA*X^2+B*X+C=0" << std::endl;
  std::cout << "Please, enter integers A, B and C (in the range from "
            << min_val << " to " << max_val << " )" << std::endl;

  std::cout << "A = ";
  std::cin >> a;
  if (a == 0 || a < min_val || a > max_val) {
    std::cout << "Wrong initial data" << std::endl;
    return 1;
  }
  std::cout << "B = ";
  std::cin >> b;
  if (b < min_val || b > max_val) {
    std::cout << "Wrong initial data" << std::endl;
    return 1;
  }
  std::cout << "C = ";
  std::cin >> c;

  if (c < min_val || c > max_val) {
    std::cout << "Wrong initial data" << std::endl;
    return 1;
  }
  long double d = b * b - 4 * a * c;
  long double x1 = (-b + sqrt(d)) / (2 * a);
  long double x2 = (-b - sqrt(d)) / (2 * a);
  if (d == 0) {
    std::cout << "The equation has one solution X = " << x1
              << " of multiplicity 2 " << std::endl;
  } else if (d > 0) {
    std::cout << "The equation has two solutions: \nX1 = " << x1
              << "\nX2 =" << x2 << std::endl;
  } else {
    std::cout << "The equation has no solutions" << std::endl;
  }

  return 0;
}
