#include <iostream>

void reverse_array() {
  const size_t kAr_size{100};
  char ar[kAr_size + 1]{};
  std::cout << "Enter word: ";
  std::cin >> ar;
  const size_t size = strlen(ar);

  if (size >= kAr_size) {
    std::cout << "Wrong size of word." << std::endl;
    return;
  }

  char *begin{ar};
  char *end{begin + size};
  while (end != ar) {
    std::cout << *--end;
  }
  std::cout << "\n\n";
}

void print_array(const unsigned int *const array, const size_t size) {
  std::cout << "Array[";
  for (size_t i{0}; i < size; ++i) {
    std::cout << array[i];
    if (i != size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

void sort_for_insert(unsigned int *const array, const size_t size,
                     const unsigned int num_element) {
  unsigned int *begin{array};
  unsigned int *end{array + size - 1};

  while (*begin < num_element && *begin != 0 && begin <= end) {
    ++begin;
  }

  while (begin < end) {
    *end = *(end - 1);
    --end;
  }

  *begin = num_element;
}

void insert_element() {
  const auto kArraySize{10};
  const auto kMin{0};
  const auto kMax{100};

  unsigned int array[kArraySize]{0};
  unsigned int num_element{};

  print_array(array, kArraySize);
  for (size_t i{0}; i < kArraySize; i++) {
    do {
      std::cout << "Insert a (" << i << ") number_element in range [" << kMin
                << "..." << kMax << "]: ";
      while (std::cin >> num_element &&
             (num_element < kMin || num_element > kMax)) {
        std::cout << "\nYou entered an incorrect numbers, try entering "
                     "again.\nEnter a num: ";
      }
    } while (num_element == 0);

    sort_for_insert(array, kArraySize, num_element);
    print_array(array, kArraySize);
  }
  std::cout << std::endl;
}

enum { REVERSE_WORD = 1, INSERT_ELEMENT };

int main() {
  do {
    std::cout << "1) Enter 1 |  to reverse your word (look --> kool)"
              << std::endl;
    std::cout << "2) Enter 2 |  to insert element in massive\n" << std::endl;
    int key{};
    std::cin >> key;
    switch (key) {
    case REVERSE_WORD:
      reverse_array();
      break;
    case INSERT_ELEMENT:
      insert_element();
      break;
    default:
      return 0;
    }
  } while (true);

  return 0;
}
