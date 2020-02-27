// Best divisor.

#include <iostream>

int main() {

  std::cout << "Enter number to search best divisor " << std::endl;

  int n;
  std::cin >> n;

  int i = n / 2;
  while (n % i != 0)
    i--;
  if (i != 1)
    std::cout << "The best divisor is -  " << i << std::endl;
  else
    std::cout << "There is no better divisor \n";
  return 0;
}
