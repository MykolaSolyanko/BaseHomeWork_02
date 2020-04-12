#include "userlist.hpp"

void userList::push_back(int value) {
  if (next_node == nullptr && prev_node == nullptr && index == 0) {
    data = value;
    ++index;
    return;
  }
  userList *Head = this;
  while (Head->next_node != nullptr) {
    Head = Head->next_node;
  }
  userList *NewNode = new userList;
  NewNode->next_node = nullptr;
  NewNode->prev_node = Head;
  NewNode->data = value;
  Head->next_node = NewNode;
  ++index;
}
void userList::push_top(int value) {
  if (next_node == nullptr && prev_node == nullptr && index == 0) {
    data = value;
    ++index;
    return;
  }
  userList *tmp_node = next_node;
  userList *NewList = new userList;
  NewList->data = data;
  NewList->next_node = tmp_node;
  NewList->prev_node = this;
  tmp_node->prev_node = NewList;
  next_node = NewList;
  data = value;
  ++index;
}

void userList::pop_back() {
  if (prev_node == nullptr && next_node == nullptr && index == 0)
    return;
  userList *Head = this;
  while (Head != nullptr && Head->next_node != nullptr)
    Head = Head->next_node;
  if (Head->prev_node == nullptr) {
    Head->data = 0;
    --index;
    return;
  }
  userList *tmp_node = Head->prev_node;
  tmp_node->next_node = nullptr;
  --index;
  delete Head;
  Head = nullptr;
}

void userList::pop_top() {
  if (prev_node == nullptr && next_node == nullptr && index == 0)
    return;
  if (next_node == nullptr) {
    data = 0;
    --index;
    return;
  }
  userList *tmp_node = next_node;
  userList *tmp_next = tmp_node->next_node;
  data = tmp_node->data;
  next_node = tmp_node->next_node;
  tmp_next->prev_node = this;
  delete tmp_node;
  tmp_node = nullptr;
  --index;
}

void userList::insert(int value, const size_t pos) {
  if (prev_node == nullptr && next_node == nullptr && index == 0) {
    if (pos == 1) {
      data = value;
      ++index;
      return;
    }
    std::cout << "Invalid position for insert!" << std::endl;
    return;
  }
  if (pos >= 1 && pos <= index + 1) {
    userList *Head = this;
    size_t ind = 1;
    while (Head != nullptr) {
      if (ind == pos) {
        if (Head->prev_node == nullptr && Head->next_node != nullptr) {
          userList *NewList = new userList;
          userList *tmp_node = next_node;
          NewList->data = data;
          NewList->prev_node = Head;
          NewList->next_node = next_node;
          tmp_node->prev_node = NewList;
          next_node = NewList;
          data = value;
          ++index;
          return;
        }
        if (Head->prev_node == nullptr && Head->next_node == nullptr) {
          userList *NewList = new userList;
          NewList->data = data;
          NewList->next_node = nullptr;
          NewList->prev_node = Head;
          data = value;
          next_node = NewList;
          ++index;
          return;
        }
        userList *NewList = new userList;
        NewList->data = value;
        NewList->prev_node = Head->prev_node;
        NewList->next_node = Head;
        userList *tmp_node = Head->prev_node;
        Head->prev_node = NewList;
        tmp_node->next_node = NewList;
        ++index;
        return;
      }
      if (Head->next_node == nullptr && ind == pos - 1) {
        userList *NewList = new userList;
        NewList->data = value;
        NewList->prev_node = Head;
        NewList->next_node = nullptr;
        Head->next_node = NewList;
        ++index;
        return;
      }
      ++ind;
      Head = Head->next_node;
    }
  }
  std::cout << "Invalid position for insert!" << std::endl;
  return;
}

void userList::eraze_pos(const size_t pos) {
  if (prev_node == nullptr && next_node == nullptr && index == 0) {
    std::cout << "List is empty!" << std::endl;
    return;
  }
  size_t ind = 1;
  userList *Head = this;
  while (Head != nullptr) {
    if (ind == pos) {
      if (Head->prev_node == nullptr) {
        userList *tmp_node = next_node;
        userList *tmp_next = tmp_node->next_node;
        data = tmp_node->data;
        next_node = tmp_node->next_node;
        tmp_next->prev_node = Head;
        delete tmp_node;
        --index;
        return;
      }
      if (Head->next_node == nullptr) {
        userList *tmp_node = Head->prev_node;
        tmp_node->next_node = nullptr;
        delete Head;
        --index;
        return;
      }
      userList *tmp_prev = Head->prev_node;
      userList *tmp_next = Head->next_node;
      tmp_prev->next_node = tmp_next;
      tmp_next->prev_node = tmp_prev;
      delete Head;
      --index;
      return;
    }
    ++ind;
    Head = Head->next_node;
  }
  std::cout << "Invalid posiotion for erase!" << std::endl;
}

void userList::eraze_elem(int value) {
  if (prev_node == nullptr && next_node == nullptr && index == 0) {
    std::cout << "List is empty!" << std::endl;
    return;
  }
  userList *Head = this;
  while (Head != nullptr) {
    if (Head->data == value) {
      if (Head->prev_node == nullptr) {
        userList *tmp_node = next_node;
        userList *tmp_next = tmp_node->next_node;
        data = tmp_node->data;
        next_node = tmp_node->next_node;
        tmp_next->prev_node = Head;
        delete tmp_node;
        --index;
        return;
      }
      if (Head->next_node == nullptr) {
        userList *tmp_node = Head->prev_node;
        tmp_node->next_node = nullptr;
        delete Head;
        --index;
        return;
      }
      userList *tmp_prev = Head->prev_node;
      userList *tmp_next = Head->next_node;
      tmp_prev->next_node = tmp_next;
      tmp_next->prev_node = tmp_prev;
      delete Head;
      --index;
      return;
    }
    Head = Head->next_node;
  }
  std::cout << "Element with value for erase not found!" << std::endl;
}

size_t userList::find_pos(int element) {
  if (prev_node == nullptr && next_node == nullptr && index == 0) {
    return 0;
  }
  userList *Head = this;
  size_t ind = 1;
  while (Head != nullptr) {
    if (Head->data == element) {
      return ind;
    }
    Head = Head->next_node;
    ++ind;
  }
  return 0;
}

int userList::find_elem(const size_t pos) {
  if (prev_node == nullptr && next_node == nullptr && index == 0)
    return 0;
  userList *Head = this;
  size_t ind = 1;
  while (Head != nullptr) {
    if (ind == pos) {
      return Head->data;
    }
    Head = Head->next_node;
    ++ind;
  }
  return 0;
}

size_t userList::size() const { return index; }

void userList::clear() {
  if (prev_node == nullptr && next_node == nullptr && index == 0)
    return;
  userList *Head = next_node;
  while (Head != nullptr) {
    userList *tmp_node = Head->next_node;
    delete Head;
    Head = nullptr;
    Head = tmp_node;
  }
  data = 0;
  next_node = nullptr;
  index = 0;
}

void userList::print() {
  if (prev_node == nullptr && next_node == nullptr && index == 0) {
    std::cout << "List is empty!" << std::endl;
    return;
  }
  userList *Head = this;
  while (Head != nullptr) {
    std::cout << Head->data << " ";
    Head = Head->next_node;
  }
  std::cout << std::endl;
}

bool userList::empty() const { return index == 0; }

void userList::sort() {
  if (prev_node == nullptr && next_node == nullptr && index == 0)
    return;
  for (userList *list_1 = this; list_1 != nullptr; list_1 = list_1->next_node) {
    for (userList *list_2 = list_1->next_node; list_2 != nullptr;
         list_2 = list_2->next_node) {
      if (list_2->data < list_1->data) {
        int tmp = list_2->data;
        list_2->data = list_1->data;
        list_1->data = tmp;
      }
    }
  }
}
