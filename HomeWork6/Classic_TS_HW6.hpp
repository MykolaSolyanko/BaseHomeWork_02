#include <iostream>

using result = std::pair<int, bool>;

static size_t k_defult_max_size{100};

struct layer {
  int inf{};
  layer *next{nullptr};
};

// Implementing a stack using a linked list
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