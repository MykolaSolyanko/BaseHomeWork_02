#include <iostream>
#include <limits>
using namespace std;

int main() {
  unsigned long long num;
  int digits_in_number = 0;
  int sum_of_numbers = 0;

  cout << "Enter a number > 0" <<endl;            
  cin >> num;

	while (num > 0) {
    sum_of_numbers += num % 10;
    num /= 10;
    digits_in_number++;
  }
  cout << "Sum of digits of your number: " << sum_of_numbers << std::endl;
  
  auto arihm_mean = static_cast<double>(sum_of_numbers) / digits_in_number;
  std::cout << "Arithmetic mean of digits of your number: " << arihm_mean << std::endl;

  return 0;
}
