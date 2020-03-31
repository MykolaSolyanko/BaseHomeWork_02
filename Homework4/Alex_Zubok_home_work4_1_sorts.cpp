#include <cstring>
#include <iostream>

using Comp = bool (*)(int, int);
bool More(int a, int b) { return a > b; }
bool Less(int a, int b) { return a < b; }

void bSort(int *begin, const int *const end, Comp func = More) {
  if (begin == nullptr || end == nullptr || begin == end)
    return;
  for (int *i = begin; i != end; i++) {
    for (int *j = begin + 1; j != end; j++) {
      if (!func(*j, *(j - 1))) {
        int tmp = *(j - 1);
        *(j - 1) = *j;
        *j = tmp;
      }
    }
  }
}

int *user_partiotion(int *begin, int *end, Comp func = More) {
  int pivot = *(end - 1);
  int *i = begin - 1;
  for (int *j = begin; j != end; j++) {
    if (func(pivot, *j)) { //*j < pivot !func
      i++;
      int tmp = *j;
      *j = *i;
      *i = tmp;
    }
  }
  int tmp = *(i + 1);
  *(i + 1) = *(end - 1);
  *(end - 1) = tmp;
  return (i + 1);
}

void qSort(int *begin, int *end, Comp func = More) {
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
