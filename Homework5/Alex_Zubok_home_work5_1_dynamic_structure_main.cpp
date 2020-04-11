#include "dynamic_structure.hpp"

int main() {
  BidirectList NewList;
  viewListMore(NewList);
  add(NewList, 10);
  add(NewList, 20);
  add(NewList, 30);
  add(NewList, 40);
  viewListMore(NewList);
  add(NewList, 50, 1);
  viewListMore(NewList);
  add(NewList, 50, size(NewList));
  viewListMore(NewList);
  std::cout << "Your size of list is: " << size(NewList) << std::endl;
  find(NewList, 30);
  del(NewList, 50);
  viewListMore(NewList);
  clearList(NewList);
  viewListMore(NewList);
  return 0;
}
