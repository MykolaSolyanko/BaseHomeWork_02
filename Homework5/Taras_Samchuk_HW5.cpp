#include <iostream>

#include "Classic_TS_HW5.hpp"
int main(int argc, char const *argv[]) {
  node_one_ptr *finder{nullptr};
  node_one_ptr *list{nullptr};
  // show empty list
  print_list(list);
  push_front(list, 1);
  push_front(list, 2);
  push_front(list, 3);
  push_front(list, 4);
  push_front(list, 5);
  push_front(list, 6);
  print_list(list);
  push_back(list, 7);

  finder = find(list, 4);
  insert(list, finder, 55);

  print_list(list);
  pop_front(list);
  pop_back(list);
  print_list(list);

  std::cout << viewfront(list) << std::endl;
  std::cout << viewback(list) << std::endl;
  clear_list(list);
  return 0;
}
