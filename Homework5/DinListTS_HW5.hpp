#pragma once
#include "Taras.hxx"

struct node_one_ptr {
  int Data{};
  node_one_ptr *next{};
};

struct node_two_ptr {
  node_two_ptr *pNext{};
  node_two_ptr *pPrev{};
  int Inf;
};
#ifdef ONE
bool print_list(node_one_ptr *root);
void push_back(node_one_ptr *root, const int info);
void push_front(node_one_ptr *root, const int info);
void pop_back(node_one_ptr *root);
void pop_front(node_one_ptr *root);
void clear_list(node_one_ptr *root);
int view_front(node_one_ptr *root);
int view_back(node_one_ptr *root);
#endif
#ifdef TWO
void print_list_forward(node_two_ptr *head, node_two_ptr *tail);

#endif