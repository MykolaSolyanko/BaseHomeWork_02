#include <cmath>
#include <iostream>

int main() {
  const int min = 2;
  const int max = 255;
  std::cout << "Please enter three numbers in range [" << min << ".. " << max
            << "]\n";

  float a;
  std::cout << "Enter a =";
  std::cin >> a;
  while (a <= min || a >= max) {
    std::cout << "Enter valid numder[" << min << ".. " << max << "]\nEnter a =";
    std::cin >> a;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  float b;
  std::cout << "Enter b =";
  std::cin >> b;
  while (b <= min || b >= max) {
    std::cout << "Enter valid numder[" << min << ".. " << max << "]\nEnter b =";
    std::cin >> b;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  float c;
  std::cout << "Enter c =";
  std::cin >> c;
  while (c <= min || c >= max) {
    std::cout << "Enter valid numder[" << min << ".. " << max << "]\nEnter c =";
    std::cin >> c;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  const int cF = 4;
  const int cT = 2;

  const auto D = pow(b, 2) - cF * a * c;

  // std::cout << sqrt(D); //проверял роботу корня

  if (D > 0) {
    std::cout << "We will have x1 and x2, because our D > 0\n";
    const auto xf = (-b - sqrt(D)) / (cT * a);
    std::cout << "x1 =" << xf << "\n";
    const auto xd = (-b + sqrt(D)) / (cT * a);
    std::cout << "x2 =" << xd << "\n";
    return 0;
  }
  if (D == 0) {
    std::cout << "We will have just one x, because our D = 0\n";
    const auto xs = -b / (cT * a);
    std::cout << "x =" << xs;
    return 0;
  }
  if (D < 0) {
    std::cout << "D < 0, so we don't have variants";
    return 0;
  }

  return 0;
}
