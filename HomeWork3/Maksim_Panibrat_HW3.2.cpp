#include <iostream>

void insert_element(int *begin, int *end, int element) {
  while (*begin < element && *begin != 0 && begin <= end) {
    ++begin;
  }
  while (begin != end) {
    *end = *(end - 1);
    --end;
  }
  *begin = element;
}

void print_array(int array[], const size_t kSize) {
  std::cout << "[";
  for (int i = 0; i < kSize; i++) {
    std::cout << array[i];
    if (i != kSize - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]\n";
}

int main() {
  const size_t kSize = 5;
  std::cout << "This programm sorts elements that user inserts into array.\n"
               "Array size = "
            << kSize << std::endl;
  int array[kSize]{};
  for (size_t i = 0; i < kSize; i++) {
    int *begin = {array}, *end = begin + kSize - 1, element;
    std::cout << "Enter '" << i << "' element: ";
    std::cin >> element;

    insert_element(begin, end, element);
    print_array(array, kSize);
  }

  return 0;
}

