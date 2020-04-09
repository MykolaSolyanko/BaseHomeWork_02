#include <iostream>
#include <random>

void arr_remove_element(int *array, size_t &index, const int search_elem) {
  bool element_find = false;
  for (size_t i = 0; i < index; i++) {
    if (search_elem == array[i]) {
      for (size_t j = i; j < index - 1; j++)
        array[j] = array[j + 1];
      --index;
      std::cout << "The element was deleted successfully!" << std::endl;
      element_find = true;
    }
  }
  if (!element_find)
    std::cout << "The searching element not found!\n";
  std::cout << "Checking filling array...\n";
  if (index > 0) {
    std::cout << "Array[ " << *array;
    for (size_t i = 1; i < index; i++)
      std::cout << ", " << array[i];
    std::cout << " ]" << std::endl;
  } else
    std::cout << "Array is empty: Array[ ]" << std::endl;
}

enum user_choice { eManual = 1, eAuto };

int main() {
  std::cout << "Please enter size of array: ";
  size_t arr_size{};
  std::cin >> arr_size;
  std::cout << "Please enter how you fill integer array: 1) manual, 2) auto: ";
  uint16_t fill_array{};
  std::cin >> fill_array;
  int *array = new int[arr_size];
  if (fill_array == eManual) {
    for (size_t i = 0; i < arr_size; i++) {
      std::cout << "Pelase enter " << i << " element of array: ";
      std::cin >> array[i];
    }
  } else if (fill_array == eAuto) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uid(0, 100);
    for (size_t i = 0; i < arr_size; i++)
      array[i] = uid(gen);
  } else
    std::cout << "You don't entered the type of filling the array!";
  while (arr_size > 0) {
    std::cout << "Please enter element that you want delete from array: ";
    int element{};
    std::cin >> element;
    arr_remove_element(array, arr_size, element);
  }

  delete[] array;
  return 0;
}
