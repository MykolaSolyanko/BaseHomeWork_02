#include <cmath>
#include <iostream>
#include <limits>

void input_check(int &value, const int kMinNum, const int kMaxNum,
                 const char check) {
  std::cout << "Enter ' " << check << " ' number in range [ " << kMinNum
            << " ... " << kMaxNum << " ]\n";
  while (!(std::cin >> value) || value < kMinNum || value > kMaxNum) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!value) {
      std::cout << "Error, not number" << std::endl;
    } else if (value > kMinNum) {
      std::cout << "Error, bigger than maximum" << std::endl;
    } else {
      std::cout << "Error, less than minimum" << std::endl;
    }
  }
  return;
}

void Discriminant_check(int a, int b, int c) {
  double D{}, x1{}, x2{};
  const double cons4 = 4, cons2 = 2;
  D = pow(b, 2) - (cons4 * a * c);
  if (D <= 0) {
    std::cout << (D < 0 ? "D<0, no real roots" : "D=0, not quadratic")
              << std::endl;
    return;
  }
  std::cout << "D>0\t Initilizating...\n";
  x1 = ((-b) + sqrt(pow(b, 2) - (cons4 * a * c))) / (cons2 * a);
  x2 = ((-b) - sqrt(pow(b, 2) - (cons4 * a * c))) / (cons2 * a);
  std::cout << "x1 = " << x1 << "\n x2 = " << x2 << std::endl;
  return;
}

int main(int argc, char *argv[]) {
  const int kMinNum = 2, kMaxNum = 255;
  std::cout << "This programm calculates discriminant \n"
               "ax^2+bx+c=0\n"
               "D = b^2 - 4 * a * c\n";
  int a, b, c;
  const char a_check = 97, b_check = 98, c_check = 99;
  input_check(a, kMinNum, kMaxNum, a_check);
  input_check(b, kMinNum, kMaxNum, b_check);
  input_check(c, kMinNum, kMaxNum, c_check);
  Discriminant_check(a, b, c);
  return 0;
}
