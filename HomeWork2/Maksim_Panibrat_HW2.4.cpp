
#include <iostream>

int main() {
  std::cout << "This programm sums up even numbers.\n Uneven numbers will be "
               "discarded.\n";
  const int kMinN = 1, kMaxN = 50;
  std::cout << "Enter amount of numbers in range [" << kMinN << "..." << kMaxN
            << "]\n";
  int n;
  std::cin >> n;
  while (n < kMinN || n > kMaxN) {
    std::cout << "Error, out of amount range\n";
    std::cin >> n;
  }
  const int kMinVal = -60, kMaxVal = 90;
  std::cout << "Enter numbers in range [" << kMinVal << "..." << kMaxVal
            << "]\n";
  int x{0};
  for (int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    while (val < kMinVal || val > kMaxVal) {
      std::cout << "Error, out of value range\n";
      std::cin >> val;
    }
    if (val % 2) {
      x += val;
    }
  }
  std::cout << "Sum of even numbers = " << x << std::endl;
  return 0;
}
