#include <iostream>

#include "DinListTS_HW5.hpp"

int main(int argc, char const *argv[]) {
  node_one_ptr *list = new node_one_ptr;
  print_list(list);
  push_back(list, 1);
  print_list(list);
  push_back(list, 2);
  print_list(list);
  push_back(list, 3);
  print_list(list);
  push_back(list, 4);
  print_list(list);
  push_back(list, 5);
  print_list(list);
  push_back(list, 6);
  print_list(list);
  push_front(list, -1);
  print_list(list);
  pop_back(list);
  print_list(list);
  clear_list(list);
  print_list(list);
  delete list;
  return 0;
}
