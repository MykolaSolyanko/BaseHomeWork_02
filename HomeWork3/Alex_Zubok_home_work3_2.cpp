#include <iostream>

void sort_array(int *array, size_t index) {
  for (size_t i = 0; i < index; i++) {
    for (size_t j = i + 1; j < index + 1; j++) {
      if (*(array + j) < *(array + i)) {
        int tmp = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = tmp;
      }
    }
  }
}

void print_array(const int *array, size_t index) {
  std::cout << "Array[ " << *array;
  for (size_t i = 1; i < index; i++)
    std::cout << ", " << *(array + i);
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
    sort_array(sorted_array, i);
    print_array(sorted_array, arr_size);
  }

  return 0;
}
