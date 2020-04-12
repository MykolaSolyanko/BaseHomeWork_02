#pragma once

#include <iostream>

struct BidirectList {
  BidirectList *previous_node = nullptr;
  BidirectList *next_node = nullptr;
  int data{};
};

void add(BidirectList &Node, int value);
void add(BidirectList &Node, int value, const size_t id_elem);
void del(BidirectList &Node, const size_t id_elem);
void clearList(BidirectList &Node);
size_t size(BidirectList &Node);
void viewListMore(BidirectList &Node);
void viewListLess(BidirectList &Node);
void cheatClear(BidirectList &Node);
void find(BidirectList &Node, int value);
bool empty(BidirectList &Node);
