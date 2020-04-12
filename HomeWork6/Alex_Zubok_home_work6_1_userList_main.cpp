#include "userlist.hpp"

int main() {
  userList test;
  // first test delete from empty list
  test.pop_back();
  test.pop_top();

  // second test add element and delete
  test.push_back(10);
  test.print();
  test.pop_back();
  test.print();
  test.push_top(20);
  test.print();
  test.pop_top();
  test.print();

  // insert into empty list
  test.insert(10, 1);
  test.print();
  test.clear();

  test.insert(10, 2);

  // delete from empty list
  test.eraze_elem(10);
  test.eraze_pos(1);

  // mix test
  test.push_back(30);
  test.print();
  test.pop_back();
  test.print();
  test.push_top(5);
  test.print();
  std::cout << test.find_elem(1) << std::endl;
  std::cout << test.find_pos(20) << std::endl;
  test.print();
  test.pop_top();
  test.push_back(4);
  test.insert(15, 1);
  test.print();
  test.insert(7, 3);
  test.print();
  test.push_back(2);
  test.insert(7, 7);
  test.insert(7, 9);
  test.insert(7, 10);
  test.print();
  test.sort();
  test.print();
  test.clear();
  test.print();
  return 0;
}
