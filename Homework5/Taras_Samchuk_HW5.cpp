#include <iostream>

#include "Classic_TS_HW5.hpp"
int main(int argc, char const *argv[]) {
  node_one_ptr *tmp{nullptr};
  node_one_ptr *list{nullptr};
  // print_list(list);
  push_front(list, 1);
  push_front(list, 2);
  push_front(list, 3);
  push_front(list, 4);
  push_front(list, 5);
  push_front(list, 6);
  print_list(list);
  push_back(list, 7);
  tmp = find(list, 4);
  insert(list, tmp, 55);
  print_list(list);
  pop_front(list);
  // pop_back(list);
  print_list(list);
  std::cout << (find(list, 4)) << std::endl;

  // std::cout << viewfront(list) << std::endl;
  // std::cout << viewback(list) << std::endl;
  return 0;
}
