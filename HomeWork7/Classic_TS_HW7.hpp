#include <iostream>

using result = std::pair<int, bool>;

static size_t k_defult_max_size{100};

template <typename T>
struct layer {
  T inf{};
  layer<T> *next{nullptr};
};

// Implementing a stack using a linked list
template <typename T>
class Stack {
 public:
  Stack();
  Stack(const size_t size);
  // Stack(const Stack &Stack) = delete;
  ~Stack();

  bool push(const T value);
  result top();
  result pop();

  void clear();
  bool swap();
  bool printAll() const;

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  layer<T> *head{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};

static const char k_mes_head[]{"}"};
static const char k_mes_empty[]{"empty"};
static const char k_mes_arrow[]{"=>"};
static const char k_mes_nullptr[]{"]"};

template <typename T>
Stack<T>::Stack() {
  Stack::head = new layer<T>;
}
template <typename T>
Stack<T>::Stack(const size_t size) : k_max_size{size} {
  Stack::head = new layer<T>;
}

template <typename T>
Stack<T>::~Stack() {
  if (count != 0) {
    clear();
  }
  delete Stack::head;
}
//--------------------------------------

template <typename T>
bool Stack<T>::push(T *value) {
  if (count == k_max_size) {
    return false;
  }
  layer<char> *NewLayer = new layer<char>;
  NewLayer->inf = value;
  NewLayer->next = head->next;
  head->next = NewLayer;
  count++;
  return true;
}

template <typename T>
bool Stack<T>::push(T value) {
  if (count == k_max_size) {
    return false;
  }
  layer<T> *NewLayer = new layer<T>;
  // NewLayer->inf = value;
  NewLayer->next = head->next;
  head->next = NewLayer;
  count++;
  return true;
}

// template <char *>

//---------------------------------------
template <typename T>
result Stack<T>::top() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->next->inf, true};
}

template <typename T>
result Stack<T>::pop() {
  if (head->next == nullptr) {
    return {{}, false};
  }
  layer<T> *to_delete = head->next;
  layer<T> *hold = to_delete->next;
  delete to_delete;
  head->next = hold;
  count--;
  return {hold->inf, true};
}

template <typename T>
void Stack<T>::clear() {
  if (count == 0) {
    return;
  }
  layer<T> *arrow = head;
  while (arrow != nullptr) {
    layer<T> *hold = arrow;
    arrow = arrow->next;
    delete hold;
  };
  count = 0;
}

template <typename T>
bool Stack<T>::swap() {
  if (head->next == nullptr || head->next->next == nullptr) {
    return false;
  }
  layer<T> *first = head->next;
  layer<T> *second = first->next;
  layer<T> *hold = second->next;

  head->next = second;
  second->next = first;
  first->next = hold;
  return true;
}
//===========================================================
template <typename T>                                        //
bool Stack<T>::printAll() const {                            //
  std::cout << k_mes_head;                                   //
  if (head == nullptr) {                                     //
    std::cout << k_mes_empty << k_mes_nullptr << std::endl;  //
    return false;                                            //
  }                                                          //
  layer<T> *arrow = head->next;                              //
  while (arrow != nullptr) {                                 //
    std::cout << arrow->inf << k_mes_arrow;                  //
    arrow = arrow->next;                                     //
  }                                                          //
  std::cout << k_mes_nullptr << std::endl;                   //
  return true;                                               //
}

template <typename T>
bool Stack<T>::isEmpty() const {
  return count == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
  return count == k_max_size;
}

template <typename T>
size_t Stack<T>::getCount() const {
  return count;
}

template <typename T>
size_t Stack<T>::getMaxSize() const {
  return k_max_size;
}