#include <iostream>

void insert_element(int *const ptr_array, const size_t size,
                    const int element) {
  auto *begin = ptr_array, *end = begin + size - 1;
  while (*begin < element && *begin != 0 && begin <= end) {
    ++begin;
  }
  while (begin < end) {
    *end = *(end - 1);
    --end;
  }
  *begin = element;
}

void print_array(const int array[], const size_t size) {
  std::cout << "[";
  for (size_t i = 0; i < size; i++) {
    std::cout << array[i];
    if (i != size - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]";
}

int main(int argc, char *argv[]) {
  const size_t kMaxSize = 5;
  std::cout << "This program inserts elements into array, and sorts them by "
               "their size\n"
               "Array's max size = "
            << kMaxSize << "\n";
  int array[kMaxSize]{};
  for (size_t i = 0; i < kMaxSize; i++) {
    int element;
    do {
      std::cout << "Insert element number " << i << " of " << kMaxSize
                << " greater than 0\n";
      std::cin >> element;
    } while (element == 0);
    insert_element(array, kMaxSize, element);
    print_array(array, kMaxSize);
  }

  return 0;
}
