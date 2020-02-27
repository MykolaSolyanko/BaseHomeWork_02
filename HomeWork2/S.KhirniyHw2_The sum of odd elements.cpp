#include <iostream>
#include <vector>

int main(int argc, const char **argv) {

  int n;
  std::cout << "Enter the number of elements in sequence" << std::endl;
  std::cin >> n;
  std::vector<int> a(n);
  std::cout << "Enter the elements of sequence" << std::endl;

  for (size_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int sum = 0;

  for (size_t i = 0; i < n; ++i) {
    if (a[i] % 2 != 0) {
      sum += a[i];
    }
  }
  std::cout << "Sum of odd elements is " << sum << std::endl;

  return 0;
}
