#include <cstring>
#include <iostream>

using Comp = bool (*)(int, int);
bool More(int a, int b) { return a > b; }

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bSort(int *begin, int *end, Comp func = More) {
  if (begin == nullptr || end == nullptr || begin == end)
    return;
  for (int *i = begin, *last = end; i != end; i++, last--) {
    for (int *j = begin + 1; j != last; j++) {
      if (func(*(j - 1), *j))
        swap(j - 1, j);
    }
  }
}

int *user_partiotion(int *begin, int *end, Comp func = More) {
  int pivot = *(end - 1);
  int *i = begin - 1;
  for (int *j = begin; j != end; j++) {
    if (func(pivot, *j)) { //*j < pivot !func
      i++;
      swap(i, j);
    }
  }
  swap(i + 1, end - 1);
  return (i + 1);
}

void qSort(int *begin, int *end, Comp func = More) {
  if (begin == nullptr || end == nullptr || begin == end)
    return;
  if (begin < end) {
    int *pi = user_partiotion(begin, end, func);
    qSort(begin, pi, func);
    qSort(pi + 1, end, func);
  }
}

void print_array(const int *begin, const int *const end) {
  std::cout << "Array[ " << *begin;
  for (const int *i = begin + 1; i != end; i++)
    std::cout << ", " << *i;
  std::cout << " ]" << std::endl;
}
