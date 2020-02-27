#include <iostream>

int main() {
  std::cout << "Enter the number of items, and press Enter " << std::endl;
  int n{0};
  std::cin >> n;
  std::cout << "Enter items, and press Enter" << std::endl;

  int s{0};

  for (size_t i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    s += val;
  }

  double amean; // Arithmetic mean
  amean = double(s) / double(n);

  std::cout << "Sum is = " << s << std::endl;
  std::cout << "Arithmetic mean is = " << amean << std::endl;
  return 0;
}
