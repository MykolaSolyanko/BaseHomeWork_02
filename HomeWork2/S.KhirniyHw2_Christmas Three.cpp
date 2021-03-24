// Christmas Three.cpp

#include <iostream>

int main() {
  std::cout << "Enter elements for build christmass three \n";
  char z = '*', space = ' ';
  int n;
  std::cin >> n;

  n--;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    if (i >= 2 && !f)
      f = true;

    for (int j = 1; j <= n - i; j++)
      std::cout << space;

    for (int j = n - i; j < n; j++)
      std::cout << z;

    if (f)
      for (int j = 1; j < i; j++)
        std::cout << z;

    std::cout << std::endl;
  }

  for (int i = 1; i <= n; ++i) {
    if (i == n) {
      std::cout << z;
      break;
    }
    std::cout << space;
  }
  std::cout << std::endl;
}
