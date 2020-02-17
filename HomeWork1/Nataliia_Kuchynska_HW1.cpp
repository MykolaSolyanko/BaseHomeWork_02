#include <cmath>
#include <iostream>

int main() {

  long int a{}, b{}, c{};

  long min_val = std::numeric_limits<int>::min();
  long max_val = std::numeric_limits<int>::max();

  std::cout << "To solve a quadratic equation \n\tA*X^2+B*X+C=0" << std::endl;
  std::cout << "Please, enter integers A, B and C (in the range from "
            << min_val << " to " << max_val << " )" << std::endl;

  std::cout << "A = ";
  std::cin >> a;

  std::cout << "B = ";
  std::cin >> b;

  std::cout << "C = ";
  std::cin >> c;

  if (a == 0 || a < min_val || a > max_val || b < min_val || b > max_val ||
      c < min_val || c > max_val) {
    std::cout << "Wrong initial data" << std::endl;
    return 1;
  }
  long double d{};
  d = b * b - 4 * a * c;
  long double x1{}, x2{};
  if (d >= 0) {
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    std::cout << "The equation has one solution X = " << x1
              << " of multiplicity 2 " << std::endl;
  } else {
    std::cout << "The equation has two solutions: \nX1 = " << x1
              << "\nX2 =" << x2 << std::endl;
  }
}
else {
  std::cout << "The equation has no solutions" << std::endl;
}

return 0;
}
