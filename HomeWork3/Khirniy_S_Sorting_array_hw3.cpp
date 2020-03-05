// Sorting array

#include <iostream>

// Function for add numbers to array
void addToArray(int a[], size_t arrSize) {
  for (size_t i{0}; i < arrSize; i++) {
    std::cin >> a[i];
  }
}
// Function for print to screen
void printToScreen(int a[], size_t arrSize) {
  for (size_t i{0}; i < arrSize; i++) {
    std::cout << a[i] << " ";
  }
}

int main(int argc, char const *argv[]) {
  const size_t arrSize{6};
  int a[arrSize];

  // Input array from keyboard
  std::cout << "Input " << arrSize << " elements in array: " << std::endl;
  addToArray(a, arrSize);
  std::cout << std::endl;

  // Output array before sorting
  std::cout << "Array has " << arrSize << " elements: " << std::endl;
  printToScreen(a, arrSize);
  std::cout << std::endl;

  int temp; // Temporary variable for swapping elements

  // Sorting array
  for (size_t i{0}; i < arrSize - 1; i++) {
    for (size_t j{0}; j < arrSize - i - 1; j++) {
      if (a[j] > a[j + 1]) {
        // Moove elements
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  // Output array after sorting
  std::cout << std::endl;
  std::cout << "Sorting array of " << arrSize << " elements: " << std::endl;

  printToScreen(a, arrSize);
  std::cout << std::endl;
  std::cout << std::endl;
  return 0;
}
