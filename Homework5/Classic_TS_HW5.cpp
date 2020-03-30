#include "Classic_TS_HW5.hpp"

#include <iostream>

static const char k_mes_arrow[]{"=->"};
static const char k_mes_nullptr[]{"nullptr"};
static const char k_mes_head[]{"}>"};
void print_list(node_one_ptr *head) {
  std::cout << k_mes_head;
  if (head == nullptr) {
    std::cout << k_mes_nullptr << std::endl;
    return;
  }
  node_one_ptr *arrow = head;
  while (arrow != nullptr) {
    std::cout << arrow->Data << k_mes_arrow;
    arrow = arrow->next;
  }
  std::cout << k_mes_nullptr << std::endl;
};

void push_back(node_one_ptr *&head, const int info) {
  node_one_ptr *NewNode = new node_one_ptr;
  NewNode->Data = info;
  if (head == nullptr) {
    head = NewNode;
    return;
  }
  node_one_ptr *arrow = head;
  while (arrow->next != nullptr) {
    arrow = arrow->next;
  }
  arrow->next = NewNode;
};

void push_front(node_one_ptr *&head, const int info) {
  node_one_ptr *NewNode = new node_one_ptr{info, head};
  head = NewNode;
};

void pop_back(node_one_ptr *&head) {
  if (head == nullptr) {
    return;
  }
  node_one_ptr *step_back{nullptr};
  node_one_ptr *arrow = head;
  while (arrow->next != nullptr) {
    step_back = arrow;
    arrow = arrow->next;
  }
  step_back->next = nullptr;
  delete arrow;
};

void pop_front(node_one_ptr *&head) {  //*&
  if (head == nullptr) {
    return;
  }
  node_one_ptr *delete_this = head;
  node_one_ptr *hold = delete_this->next;
  delete delete_this;
  *head = *hold;
};

void clear_list(node_one_ptr *head) {
  node_one_ptr *arrow = head;
  while (arrow->next != nullptr) {
    node_one_ptr *hold = arrow;
    arrow = arrow->next;
    delete hold;
  };
  delete head;
};

int viewfront(node_one_ptr *head) {
  if (head == nullptr) {
    return {};
  }
  return head->Data;
};

int viewback(node_one_ptr *head) {
  if (head == nullptr) {
    return {};
  }
  node_one_ptr *arrow = head;
  while (arrow->next != nullptr) {
    arrow = arrow->next;
  };
  return arrow->Data;
};