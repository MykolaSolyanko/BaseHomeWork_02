#include <iostream>
#include <limits>
int input_check(const int kMinNum, const int kMaxNum, const char check) {
  std::cout << "Enter ' " << check << " ' number in range [ " << kMinNum
            << " ... " << kMaxNum << " ]\n";
  int value;
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
  return value;
}
void Discriminant_check(int a, int b, int c) {
  double D{}, x1{}, x2{};
  const double cons4 = 4, cons2 = 2;
  D = pow(b, 2) - (cons4 * a * c);
  if (D <= 0) {
    std::cout << (D < 0 ? "D<0, no real roots" : "D=0, not quadratic")
              << std::endl;
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
  const char a_check = 'a', b_check = 'b', c_check = 'c';
  int a{input_check(kMinNum, kMaxNum, a_check)},
      b{input_check(kMinNum, kMaxNum, b_check)},
      c{input_check(kMinNum, kMaxNum, c_check)};
  Discriminant_check(a, b, c);
  return 0;
}

