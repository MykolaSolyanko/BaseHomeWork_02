#include <cmath>
#include <iostream>

int main() {
  double a{0};
  double b{0};
  double c{0};
  double x{0};

  const int constwo{0};
  const int consfour{0};

  std::cout << "Enter a: ";
  while (!(std::cin >> a)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Error! Repeat: ";
  }

  std::cout << "Enter b: ";
  while (!(std::cin >> b)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Error! Repeat: ";
  }

  std::cout << "Enter c: ";
  while (!(std::cin >> c)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Error! Repeat: ";
  }

const int kform{b * b - consfour * a * c};

  if ((kform) >= 0) {
    x = (-b + sqrt(kform)) / (constwo * a);
    std::cout << "The first root is " << x << std::endl;
    x = (-b - sqrt(kform)) / (constwo * a);
    std::cout << "The second root is " << x << std::endl;
  } else {
    std::cout << "Discriminant less then 0." << std::endl;
  }

  return 0;
}
