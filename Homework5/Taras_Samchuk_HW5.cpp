#include <iostream>

#include "Classic_TS_HW5.hpp"
int main(int argc, char const *argv[]) {
  node_one_ptr *list = nullptr;  // new node_one_ptr;
  print_list(list);
  push_front(&list, 1);
  print_list(list);
  push_front(&list, 2);
  print_list(list);
  push_front(&list, 3);
  print_list(list);
  push_front(&list, 4);
  print_list(list);
  push_front(&list, 5);
  print_list(list);
  push_front(&list, 6);
  print_list(list);
  push_back(&list, 7);
  print_list(list);
  pop_front(&list);
  pop_back(&list);
  print_list(list);
  // std::cout << view_front(list) << std::endl;
  // std::cout << view_back(list) << std::endl;
  // std::cout << view_front(list) << std::endl;
  return 0;
}
