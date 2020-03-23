#include <iostream>
#include <limits>

int count(int value) {
  size_t count{};
  for (size_t tmp = value; tmp > 0; tmp /= 10)
    ++count;
  return count;
}
int summa(int value) {
  size_t summ{};
  const uint8_t kTen = 10;
  for (size_t tmp = value; tmp > 0; tmp /= kTen)
    summ += (tmp % kTen);
  return summ;
}

int main() {
  const uint8_t kHappy_Count{6};
  int happy_ticket{};
  char symbol = 'y';
  while (symbol == 'y' || symbol == 'Y') {
    std::cout << "Please enter your happy ticket, and pess 'Enter': ";
    while (!(std::cin >> happy_ticket) || std::cin.fail() || count(happy_ticket) != kHappy_Count) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      std::cout << "You enter wrong ticket number, please try again and pess 'Enter': ";
    }
    const uint16_t kThous = 1000;
    int lSum = happy_ticket / kThous, rSum = happy_ticket % kThous;
    std::cout << ((summa(lSum) == summa(rSum)) ? "Congratulations, you won!" : "Unfortunately you lost, the next time you are lucky!") << std::endl;
    std::cout << "Do you want try again?[y/n]: ";
    std::cin >> symbol;
  }
  return 0;
}
