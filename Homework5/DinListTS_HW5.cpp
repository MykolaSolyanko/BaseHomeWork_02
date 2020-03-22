#include "DinListTS_HW5.hpp"

#include <iostream>

#include "Taras.hxx"

static const char k_mes_arrow[]{"=->"};
static const char k_mes_nullptr[]{"nullptr"};
static const char k_mes_head[]{"}>"};
static const char k_mes_tail[]{"<{"};
static const char k_mes_empty[]{"empty"};
static const char k_mes_reverse_arrow[]{"<=>"};
#ifdef ONE
//========================================================================
bool print_list(node_one_ptr *root) {
  std::cout << k_mes_head;
  node_one_ptr *arrow = root->next;
  while (arrow != nullptr) {
    std::cout << arrow->Data << k_mes_arrow;
    arrow = arrow->next;
  };
  std::cout << k_mes_nullptr << std::endl;
  return true;
}
void push_back(node_one_ptr *root, const int info) {
  node_one_ptr *NewNode = new node_one_ptr;
  NewNode->Data = info;
  node_one_ptr *arrow = root;
  while (arrow->next != nullptr) {
    arrow = arrow->next;
  };
  arrow->next = NewNode;
}
void push_front(node_one_ptr *root, const int info) {
  node_one_ptr *NewNode = new node_one_ptr;
  NewNode->Data = info;
  node_one_ptr *hold = root->next;
  root->next = NewNode;
  NewNode->next = hold;
}

void pop_back(node_one_ptr *root) {
  node_one_ptr *arrow = root;
  while (arrow->next->next != nullptr) {
    arrow = arrow->next;
  };
  delete arrow->next;
  arrow->next = nullptr;
}

void pop_front(node_one_ptr *root) {
  node_one_ptr *hold = root->next->next;
  node_one_ptr *arrow = root->next;
  delete arrow;
  root->next = hold;
}

void clear_list(node_one_ptr *root) {
  node_one_ptr *arrow = root;
  root->next = nullptr;
  while (arrow->next != nullptr) {
    node_one_ptr *hold = arrow;
    arrow = arrow->next;
    delete hold;
  };
}

int view_front(node_one_ptr *root) {
  if (root->next == nullptr) {
    return {};
  }
  return root->next->Data;
}
int view_back(node_one_ptr *root) {
  node_one_ptr *arrow = root;
  while (arrow->next != nullptr) {
    arrow = arrow->next;
  };
  return arrow->Data;
}
#endif
//========================================================================
#ifdef TWO
bool print_list_forward(node_two_ptr *head, node_two_ptr *tail) {
  std::cout << k_mes_head;
  node_two_ptr *arrow = head->next;
  while (arrow != nullptr) {
    std::cout << arrow->Data << k_mes_arrow;
    arrow = arrow->next;
  };
  std::cout << k_mes_nullptr << std::endl;
  return true;
}
#endif
