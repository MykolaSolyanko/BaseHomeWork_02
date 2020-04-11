// Khirniy.S HW6 - Linked list

#include <iostream>

template <typename T> class List {
public:
  List();
  ~List();
  void pop_front();
  void push_back(T data);          // add the elements of the end of list
  void clear();                    // method to clear the list
  void push_front(T data);         // add the elements of the start of list
  void insert(T value, int index); // insert element from index to list
  void removeAt(int index);        // remove element from index
  void pop_back();                 // remove element from end of list
  int GetSize() { return Size; }   // method for return number of items
  T &operator[](const int index);  // operator[] for return data from list

private:
  // class Node with data
  template <typename T> class Node {
  public:
    Node *pNext;
    T data;
    Node(T data = T(), Node *pNext = nullptr) {
      this->data = data;
      this->pNext = pNext;
    }

  private:
  };
  int Size;
  Node<T> *head;
};

template <typename T> List<T>::List() {
  Size = 0; // field size for save number of nodes
  head = nullptr;
}
template <typename T> List<T>::~List() { clear(); }
template <typename T>
void List<T>::pop_front() { // method to delete the first item in the list
  Node<T> *temp = head;
  head = head->pNext;
  delete temp;
  Size--;
}
template <typename T> void List<T>::push_back(T data) {
  if (head == nullptr) {
    head = new Node<T>(data);
  } else {
    Node<T> *current = this->head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node<T>(data);
  }
  Size++;
}
template <typename T> void List<T>::clear() {
  while (Size) {
    pop_front();
  }
}
template <typename T> void List<T>::push_front(T data) {
  head = new Node<T>(data, head);
  Size++;
}
template <typename T> void List<T>::insert(T data, int index) {
  if (index == 0) {
    push_front(data);
  } else {
    Node<T> *previous = this->head;

    for (int i{0}; i < index - 1; i++) {
      previous = previous->pNext;
    }

    Node<T> *newNode = new Node<T>(data, previous->pNext);
    previous->pNext = newNode;
    Size++;
  }
}
template <typename T> void List<T>::removeAt(int index) {
  if (index == 0) {
    pop_front();
  } else {
    Node<T> *previous = this->head;
    for (int i{0}; i < index - 1; i++) {
      previous = previous->pNext;
    }
    Node<T> *toDelete = previous->pNext;
    previous->pNext = toDelete->pNext;
    delete toDelete;
    Size--;
  }
}
template <typename T> void List<T>::pop_back() { removeAt(Size - 1); }
template <typename T> T &List<T>::operator[](const int index) {
  int counter = 0;
  Node<T> *current = this->head;
  while (current != nullptr) {
    if (counter == index) {
      return current->data;
    }
    current = current->pNext;
    counter++;
  }
}
int main() {

  List<int> lst;

  lst.push_back(5); // add elements to list
  lst.push_back(10);
  lst.push_back(20);
  lst.push_front(11);
  lst.insert(87, 3);

  for (int i{0}; i < lst.GetSize(); i++) { // print elements
    std::cout << lst[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Number of items in the list - " << lst.GetSize() << std::endl;
  std::cout << std::endl;

  std::cout << "Remove element from index(2): " << std::endl;
  lst.removeAt(2);

  for (int i{0}; i < lst.GetSize(); i++) { // print elements
    std::cout << lst[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Number of items in the list - " << lst.GetSize() << std::endl;
  std::cout << std::endl;

  std::cout << "Run pop_back: " << std::endl;
  lst.pop_back();

  for (int i{0}; i < lst.GetSize(); i++) { // print elements
    std::cout << lst[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Number of items in the list - " << lst.GetSize()
            << ", run method pop_front: ";
  lst.pop_front();
  std::cout << std::endl;

  for (int i{0}; i < lst.GetSize(); i++) { // print elements
    std::cout << lst[i] << std::endl;
  }
  std::cout << std::endl;

  std::cout << "Number of items in the list - " << lst.GetSize()
            << ", run method clear." << std::endl;
  lst.clear();
  std::cout << std::endl;

  std::cout << "Number of items in the list - " << lst.GetSize() << std::endl;
  std::cout << std::endl;
  return 0;
}
