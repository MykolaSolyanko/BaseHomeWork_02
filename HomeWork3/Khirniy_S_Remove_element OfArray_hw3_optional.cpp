// Remove element from array

#include <iostream>

// Function for remove idex of array
void remove_by_index(int *a, int size, int index_to_remove) {
  for (int i = index_to_remove; i < size - 1; i++) {
    a[i] = a[i + 1];
    a[size - 1] = 0;
  }
}
// Function print of array
void print_array(int *a, int size) {
  std::cout << "Array: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << a[i] << " ";
  }
}
int main(int argc, char const *argv[]) {
  int size, *a;
  std::cout << "Enter size array: \t" << std::endl;
  std::cin >> size;
  std::cout << "Enter elemts of array " << std::endl;
  a = new int[size];

  for (int i = 0; i < size; ++i) {
    std::cin >> a[i];
  }
  print_array(a, size);

  int Index_to_remove;
  std::cout << std::endl;
  std::cout << "Enter index of element to remove: \n";
  std::cin >> Index_to_remove;
  remove_by_index(a, size, Index_to_remove);
  print_array(a, size);
  std::cout << std::endl;

  delete[] a;

  return 0;
}
