#include <cmath>
#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
  std::cout << "x= ((-b) +- sqrt(b^2-4ac))/2a\n";

  const short kMinA = 1, kMaxA = 200;
  std::cout << "Enter 'a' number in range [" << kMinA << "..." << kMaxA << "]"
            << "\n";
  short a;
  while (!(std::cin >> a), a < kMinA || a > kMaxA) {
    std::cout << "Error, out of range or not number\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  const short kMinB = 1, kMaxB = 340;
  std::cout << "Enter 'b' number in range [" << kMinB << "..." << kMaxB << "]"
            << "\n";
  short b;
  while (!(std::cin >> b), b < kMinB || b > kMaxB) {
    std::cout << "Error, out of range or not number\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  const short kMinC = 1, kMaxC = 400;
  std::cout << "Enter 'c' number in range [" << kMinC << "..." << kMaxC << "]"
            << "\n";
  short c;
  while (!(std::cin >> c), c < kMinC || c > kMaxC) {
    std::cout << "Error, out of range or not number\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  double D = pow(b, 2) - 4 * a * c;
  if (D < 0) {
    std::cout << "No real roots\n";
    return 0;
  }
  if (D == 0) {
    std::cout << "Not quadratic\n";
    return 0;
  }

  std::cout << "There 2 roots\n";
  auto x1 = (-b + sqrt(D)) / (2 * a);
  auto x2 = (-b - sqrt(D)) / (2 * a);
  std::cout << "x1=" << x1 << "\n";
  std::cout << "x2=" << x2 << "\n";
  return 0;
}
