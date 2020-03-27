#include <iostream>

template <typename T>
using result = std::pair<T, bool>;

static size_t k_defult_max_size{100};

template <typename T>
struct layer {
  T inf{};
  layer<T> *next{nullptr};
};

template <typename T>
struct node2directions {
  T save{};
  node2directions<T> *next{nullptr};
  node2directions<T> *prev{nullptr};
};
// stack is based on a unidirectional list

template <typename T>
class Stack {
 public:
  Stack();
  Stack(const size_t size);
  ~Stack();

  bool push(const T value);
  result<T> top();
  result<T> pop();

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

// the queue is based on a bidirectional list

template <typename T>
class Equeue {
 public:
  Equeue(const size_t size);
  Equeue();

  ~Equeue();

  bool enqueue(const int value);
  result<T> peek();
  result<T> dequeue();

  bool printAllForward() const;
  bool printAllBackward() const;

  void clear();
  bool swap();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  node2directions<T> *head{nullptr};
  node2directions<T> *tail{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};

static const char k_mes_head[]{"}"};
static const char k_mes_forward[]{"forward"};
static const char k_mes_backward[]{"backward"};
static const char k_mes_empty[]{"empty"};
static const char k_mes_arrow[]{"=>"};
static const char k_mes_double_arrow[]{"<=>"};
static const char k_mes_nullptr[]{"]"};
static const char k_mes_tail[]{"{"};

// stack is based on a unidirectional list
template <typename T>
Stack<T>::Stack() {
  head = new layer<T>;
}

template <typename T>
Stack<T>::Stack(const size_t size) : k_max_size{size} {
  head = new layer<T>;
}

template <typename T>
Stack<T>::~Stack() {
  if (count != 0) {
    clear();
  }
  delete head;
}

template <typename T>
bool Stack<T>::push(const T value) {
  if (count == k_max_size) {
    return false;
  }
  layer<T> *NewLayer = new layer<T>;
  NewLayer->inf = value;
  NewLayer->next = head->next;
  head->next = NewLayer;
  count++;
  return true;
}

template <typename T>
result<T> Stack<T>::top() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->next->inf, true};
}

template <typename T>
result<T> Stack<T>::pop() {
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

template <typename T>
bool Stack<T>::printAll() const {
  std::cout << k_mes_head;
  if (head == nullptr) {
    std::cout << k_mes_empty << k_mes_nullptr << std::endl;
    return false;
  }
  layer<T> *arrow = head->next;
  while (arrow != nullptr) {
    std::cout << arrow->inf << k_mes_arrow;
    arrow = arrow->next;
  }
  std::cout << k_mes_nullptr << std::endl;
  return true;
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

template <typename T>
Equeue<T>::Equeue(size_t size) : k_max_size{size} {
  head = new node2directions<T>;
  tail = new node2directions<T>;
  head->next = tail;
  tail->prev = head;
}

template <typename T>
Equeue<T>::Equeue() {
  Equeue::head = new node2directions<T>;
  Equeue::tail = new node2directions<T>;
  head->next = tail;
  tail->prev = head;
}

template <typename T>
Equeue<T>::~Equeue() {
  if (count != 0) {
    clear();
  }
  delete head;
  delete tail;
}

template <typename T>
bool Equeue<T>::enqueue(int value) {
  if (count == k_max_size) {
    return false;
  }
  node2directions<T> *NewComponent = new node2directions<T>;
  node2directions<T> *first = head->next;
  NewComponent->save = value;
  NewComponent->next = first;
  NewComponent->prev = head;
  head->next = NewComponent;
  first->prev = NewComponent;
  count++;
  return true;
}

template <typename T>
result<T> Equeue<T>::peek() {
  if (count == 0) {
    return {{}, false};
  }
  return {head->next->save, true};
}

template <typename T>
result<T> Equeue<T>::dequeue() {
  if (head->next == nullptr) {
    return {{}, false};
  }
  node2directions<T> *to_delete = head->next;
  node2directions<T> *hold = to_delete->next;
  delete to_delete;
  head->next = hold;
  hold->prev = head;
  count--;
  return {{hold->save}, true};
}

template <typename T>
bool Equeue<T>::printAllForward() const {
  std::cout << k_mes_forward << k_mes_head;
  if (head->next == tail) {
    std::cout << k_mes_empty << k_mes_tail << std::endl;
    return false;
  }
  node2directions<T> *arrow = head->next;
  while (arrow->next != nullptr) {
    std::cout << k_mes_double_arrow;
    std::cout << arrow->save;
    arrow = arrow->next;
  }
  std::cout << k_mes_double_arrow << k_mes_tail << std::endl;
  return true;
};

template <typename T>
bool Equeue<T>::printAllBackward() const {
  std::cout << k_mes_backward << k_mes_head;
  if (tail->prev == head) {
    std::cout << k_mes_empty << k_mes_tail << std::endl;
    return false;
  }
  node2directions<T> *arrow = tail->prev;
  while (arrow->prev != nullptr) {
    std::cout << k_mes_double_arrow;
    std::cout << (arrow->save);  //
    arrow = arrow->prev;
  }
  std::cout << k_mes_double_arrow << k_mes_tail << std::endl;
  return true;
};

template <typename T>
void Equeue<T>::clear() {
  if (count == 0) {
    return;
  }
  node2directions<T> *arrow = head->next;
  head->next = tail;
  tail->prev = head;
  count = 0;
  while (arrow != nullptr) {
    node2directions<T> *hold = arrow;
    arrow = arrow->next;
    delete hold;
  }
}

template <typename T>
bool Equeue<T>::swap() {
  if (head->next == tail || head->next->next == tail) {
    return false;
  }

  node2directions<T> *first = head->next;
  node2directions<T> *second = first->next;
  node2directions<T> *hold = second->next;

  head->next = second;
  second->next = first;
  first->next = hold;
  hold->prev = first;
  first->prev = second;
  second->prev = head;
  return true;
}

template <typename T>
bool Equeue<T>::isEmpty() const {
  return count == 0;
}

template <typename T>
bool Equeue<T>::isFull() const {
  return count == k_max_size;
}

template <typename T>
size_t Equeue<T>::getCount() const {
  return count;
}

template <typename T>
size_t Equeue<T>::getMaxSize() const {
  return k_max_size;
}