#include <iostream>

void ticket_analize(int ticket_num) {
  int left_sum;
  left_sum = (ticket_num / 100000) + (ticket_num / 10000) % 10 +
             (ticket_num / 1000) % 10;
  int right_sum;
  right_sum =
      (ticket_num / 100) % 10 + (ticket_num / 10) % 10 + ticket_num % 10;
  std::cout << (left_sum == right_sum ? "You won!!!" : "You lose...")
            << std::endl;
}

int main(int argc, char *argv[]) {
  const int kMinNum = 100000, kMaxNum = 999999;
  std::cout << "This programm checks your ticket's number\n"
               "Enter number in range [ "
            << kMinNum << " ... " << kMaxNum << " ] for analize: ";
  int ticket_num;
  std::cin >> ticket_num;
  ticket_analize(ticket_num);
  return 0;
}
