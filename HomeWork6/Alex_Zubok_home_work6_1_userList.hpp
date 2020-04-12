#pragma once

#include <cstring>
#include <iostream>

class userList {
public:
  userList() = default;
  userList(int element);
  userList(userList &src);
  ~userList();
  void push_back(int value);
  void push_top(int value);
  void pop_back();
  void pop_top();
  void insert(int value, const size_t pos);
  void eraze_pos(const size_t pos);
  void eraze_elem(int value);
  size_t find_pos(int value);
  int find_elem(const size_t pos);
  size_t size() const;
  void clear();
  void print();
  bool empty() const;
  void sort();

private:
  int data{};
  userList *next_node{nullptr};
  userList *prev_node{nullptr};
  size_t index{};
};
