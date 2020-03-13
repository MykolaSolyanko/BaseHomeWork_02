#include <iostream>

int main() {

  std::cout << "This program can sums all odd digits from your number. Enter "
               "amount - ";

  const int k_min_number = 1, k_max_number = 50;
  int number;
  std::cin >> number;

  while (number < k_min_number || k_max_number < number) {
    std::cout << "Error! Nuber out of amound range. Enter again - ";
    std::cin >> number;
  }

  const int k_min_value = -60, k_max_value = 90;
  std::cout << "Enter range - " << std::endl;

  int sum{0};
  size_t count{1};

  while (count <= number) {

    int value;
    std::cin >> value;

    if (value < k_min_value || k_max_value < value) {
      std::cout << "Error, out of value range, please try again\n";
      continue;
    }

    if (value % 2) {
      sum += value;
    }
    ++count;
  }

  std::cout << "Sum of your odd numbers = " << sum << std::endl;
 
  return 0;
}
