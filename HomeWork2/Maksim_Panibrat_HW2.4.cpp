int main() {
  std::cout << "This programm sums up even numbers.\n Uneven numbers will be "
               "discarded.\n";
  const int kMinNum = 1, kMaxNum = 50;
  std::cout << "Enter amount of numbers in range [" << kMinNum << "..."
            << kMaxNum << "]\n";
  int num;
  std::cin >> num;
  while (num < kMinNum || num > kMaxNum) {
    std::cout << "Error, out of amount range\n";
    std::cin >> num;
  }
  const int kMinVal = -60, kMaxVal = 90;
  std::cout << "Enter numbers in range [" << kMinVal << "..." << kMaxVal
            << "]\n";
  int sum{0};
  size_t iter{1};
  while (iter <= num) {
    int val;
    std::cin >> val;
    if (val < kMinVal || val > kMaxVal) {
      std::cout << "Error, out of value range, please try again\n";
      continue;
    }
    if (val % 2) {
      sum += val;
    }
    ++iter;
  }
  std::cout << "Sum of even numbers = " << sum << std::endl;
  return 0;
}
