#include <iostream>

void sort_array(int *begin, const int *const end) {
  if (begin == nullptr || end == nullptr || begin == end)
    return;
  for (int *i = begin; i != end; i++) {
    for (int *j = i + 1; j != end + 1; j++) {
      if (*j < *i) {
        int tmp = *i;
        *i = *j;
        *j = tmp;
      }
    }
  }
}

void print_array(const int *begin, const int *const end) {
  std::cout << "Array[ " << *begin;
  for (const int *i = begin + 1; i != end; i++)
    std::cout << ", " << *i;
  std::cout << " ]" << std::endl;
}

int main() {
  std::cout << "Please enter your size of array: ";
  size_t arr_size{};
  std::cin >> arr_size;
  int *sorted_array = new int[arr_size]{};
  for (size_t i = 0; i < arr_size; i++) {
    std::cout << "Please enter the array element: ";
    std::cin >> *(sorted_array + i);
    sort_array(sorted_array, sorted_array + i);
    print_array(sorted_array, sorted_array + arr_size);
  }
  delete[] sorted_array;
  return 0;
}
