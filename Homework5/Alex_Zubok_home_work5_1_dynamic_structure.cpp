#include <iostream>
/*
add element to list +
delete element from list +
find element in list+
clear list+
check is clear list?+
return number of element+
*/

struct BidirectList {
  BidirectList *previous_node = nullptr;
  BidirectList *next_node = nullptr;
  int data{};
};

// add element to list
void add(BidirectList &Node, int value) {
  BidirectList *Head = &Node;
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0) {
    Head->data = value;
    Head->previous_node = nullptr;
    Head->next_node = nullptr;
    return;
  }
  while (Head->next_node != nullptr)
    Head = Head->next_node;
  BidirectList *NewNode = new BidirectList;
  NewNode->data = value;
  NewNode->next_node = nullptr;
  NewNode->previous_node = Head;
  Head->next_node = NewNode;
  Head = NewNode;
}

// add element with id_elem
void add(BidirectList &Node, int value, const size_t id_elem) {
  BidirectList *Head = &Node;
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0) {
    return;
  }
  size_t index{1};
  while (Head != nullptr) {
    if (index == id_elem) {
      if (Head->next_node != nullptr) {
        BidirectList *NewNode = new BidirectList;
        BidirectList *tmp_node = Head->next_node;
        NewNode->data = Head->data;
        NewNode->previous_node = Head;
        NewNode->next_node = tmp_node;
        Head->data = value;
        Head->next_node = NewNode;
        tmp_node->previous_node = NewNode;
        return;
      } else {
        BidirectList *NewNode = new BidirectList;
        BidirectList *tmp_node = Head->next_node;
        NewNode->data = value;
        NewNode->previous_node = Head;
        NewNode->next_node = tmp_node;
        Head->next_node = NewNode;
        return;
      }
    }
    Head = Head->next_node;
    ++index;
  }
}

// delete element from list
void del(BidirectList &Node, const size_t id_elem) {
  BidirectList *Head = &Node;
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0) {
    return;
  }
  size_t index{1};
  while (Head != nullptr) {
    if (index == id_elem) {
      if (Head->previous_node == nullptr) {
        BidirectList *tmp_node = Head->next_node;
        BidirectList *tmp_next = tmp_node->next_node;
        Head->data = tmp_node->data;
        tmp_next->previous_node = Head;
        Head->next_node = tmp_next;
        delete tmp_node;
        return;
      }
      if (Head->next_node == nullptr) {
        BidirectList *tmp_prev = Head->previous_node;
        tmp_prev->next_node = nullptr;
        delete Head;
        return;
      }
      BidirectList *tmp_prev = Head->previous_node, *tmp_next = Head->next_node;
      tmp_next->previous_node = tmp_prev;
      tmp_prev->next_node = tmp_next;
      delete Head;
      return;
    }
    ++index;
    Head = Head->next_node;
  }
}

// view list
void viewListMore(BidirectList &Node) {
  BidirectList *Head = &Node;
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0) {
    std::cout << "List is empty!" << std::endl;
    return;
  }
  while (Head != nullptr) {
    std::cout << Head->data << " ";
    Head = Head->next_node;
  }
  std::cout << std::endl;
}

void viewListLess(BidirectList &Node) {
  BidirectList *Head = &Node;
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0) {
    std::cout << "List is empty!" << std::endl;
    return;
  }
  while (Head->next_node != nullptr)
    Head = Head->next_node;
  while (Head != nullptr) {
    std::cout << Head->data << " ";
    Head = Head->previous_node;
  }
  std::cout << std::endl;
}

// find element in list
void find(BidirectList &Node, int value) {
  BidirectList *Head = &Node;
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0) {
    return;
  }
  size_t index{1};
  while (Head != nullptr) {
    if (Head->data == value) {
      std::cout << "Element " << Head->data << " found in pos " << index
                << std::endl;
      return;
    }
    Head = Head->next_node;
    ++index;
  }
}

// clear list
void clearList(BidirectList &Node) {
  BidirectList *Head = &Node;
  Head = Head->next_node;
  while (Head != nullptr) {
    BidirectList *tmp_next = Head->next_node;
    delete Head;
    Head = tmp_next;
  }
  Head = &Node;
  Head->next_node = nullptr;
  Head->data = 0;
}

// cheating clear list
void cheatClear(BidirectList &Node) {
  Node.data = 0;
  Node.next_node = nullptr;
}

// Is empty list
bool empty(BidirectList &Node) {
  if (Node.previous_node == nullptr && Node.next_node == nullptr &&
      Node.data == 0)
    return true;
  return false;
}

// size list element
size_t size(BidirectList &Node) {
  BidirectList *Head = &Node;
  size_t size{};
  if (Head->previous_node == nullptr && Head->next_node == nullptr &&
      Head->data == 0)
    return size;
  while (Head != nullptr) {
    ++size;
    Head = Head->next_node;
  }
  return size;
}
