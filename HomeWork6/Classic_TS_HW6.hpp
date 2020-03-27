#include <iostream>

using result = std::pair<int, bool>;

static size_t k_defult_max_size{100};

struct layer {
  int inf{};
  layer *next{nullptr};
};

// stack is based on a unidirectional list

class Stack {
 public:
  Stack();
  Stack(const size_t size);
  // Stack(const Stack &Stack) = delete;
  ~Stack();

  bool push(const int value);
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
  layer *head{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};

// the queue is based on a bidirectional list

struct node2directions {
  int save{};
  node2directions *next{nullptr};
  node2directions *prev{nullptr};
};

class Equeue {
 public:
  Equeue();
  Equeue(const size_t size);
  ~Equeue();

  bool enqueue(const int value);
  result peek();
  result dequeue();

  bool printAllForward() const;
  bool printAllBackward() const;

  void clear();
  bool swap();

  bool isEmpty() const;
  bool isFull() const;

  size_t getCount() const;
  size_t getMaxSize() const;

 private:
  node2directions *head{nullptr};
  node2directions *tail{nullptr};
  size_t count{0};
  const size_t k_max_size{k_defult_max_size};
};