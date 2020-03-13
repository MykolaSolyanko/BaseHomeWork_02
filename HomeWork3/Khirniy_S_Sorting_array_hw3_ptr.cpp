// Sorting array

#include <iostream>

// Function for add numbers to array
void addToArray(int *const ptr_a, const size_t arrSize, const int number) {
  int *begin = ptr_a, *end = begin + arrSize - 1;
  while (*begin < number && *begin != 0 && begin <= end) {
    ++begin;
  }
  while (begin < end) {
    *end = *(end - 1);
    --end;
  }
  *begin = number;
}

// Function for print to screen
void printToScreen(const int a[], const size_t arrSize) {
  std::cout << "array{";
  for (size_t i{0}; i < arrSize; i++) {
    std::cout << a[i];
    if (i != arrSize - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}";
}

int main(int argc, char const *argv[]) {
  const size_t arrSize{6};
  int a[arrSize]{};

  // Input array from keyboard
  std::cout << "Input " << arrSize
            << " elements in array greater than 0: " << std::endl;
  for (size_t i{0}; i < arrSize; i++) {
    int number;
    do {
      std::cout << "\n";
      std::cout << "Insert number: ";
      std::cin >> number;
    } while (number == 0);
    addToArray(a, arrSize, number);
    printToScreen(a, arrSize);
  }
  return 0;
}
