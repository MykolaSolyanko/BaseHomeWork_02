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
  while (head != nullptr) {
    std::cout << head->Data << k_mes_arrow;
    head = head->next;
  }
  std::cout << k_mes_nullptr << std::endl;
};

void push_back(node_one_ptr *&head, const int info) {
  node_one_ptr *NewNode = new node_one_ptr{info, nullptr};
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
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  node_one_ptr *arrow = head;
  while (arrow->next->next != nullptr) {
    arrow = arrow->next;
  }
  delete arrow->next;
  arrow->next = nullptr;
};

void pop_front(node_one_ptr *&head) {
  if (head == nullptr) {
    return;
  }
  node_one_ptr *delete_this = head;
  node_one_ptr *hold = delete_this->next;
  delete delete_this;
  head = hold;
};

void clear_list(node_one_ptr *&head) {
  node_one_ptr *arrow = head;
  while (arrow != nullptr) {
    node_one_ptr *hold = arrow;
    arrow = arrow->next;
    delete hold;
  };
  head = nullptr;
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
  while (head->next != nullptr) {
    head = head->next;
  };
  return head->Data;
};

node_one_ptr *insert(node_one_ptr *&head, node_one_ptr *pos, const int value) {
  if (pos == nullptr) {
    return nullptr;
  }
  node_one_ptr *NewNode = new node_one_ptr{value, nullptr};
  node_one_ptr *arrow = head;
  while (arrow->next != nullptr && arrow != pos) {
    arrow = arrow->next;
  }
  NewNode->next = arrow->next;
  arrow->next = NewNode;
  return NewNode;
};

node_one_ptr *find(node_one_ptr *head, const int value) {
  if (head == nullptr) {
    return nullptr;  // empty
  }
  node_one_ptr *arrow = head;
  while (arrow != nullptr) {
    if (arrow->Data == value) {
      return arrow;  // first found
    }
    arrow = arrow->next;
  }
  return nullptr;  // did not find anything;
};