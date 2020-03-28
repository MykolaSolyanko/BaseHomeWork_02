#include <iostream>

const auto kFirstLowRegister{ 'a' };
const auto kLastLowRegister{ 'z' };
const auto kFirstUpRegister{ 'A' };
const auto kLastUpRegister{ 'Z' };
const auto kNumForChangeRegister{ 32 };
const auto kFirstNum{ '0' };
const auto kLastNum{ '9' };

enum UpOrDown : bool { UP = true, DOWN = false };

void swap(char *const begin_ptr, char *const end_ptr) {
  if (begin_ptr == nullptr || end_ptr == nullptr || begin_ptr == end_ptr) {
    return;
  }
  char tmp = *begin_ptr;
  *begin_ptr = *end_ptr;
  *end_ptr = tmp;
}

void reverse_array() {
  const size_t kAr_size{100};
  char ar[kAr_size]{};
  std::cout << "Enter word: ";
  std::cin >> ar;
  const size_t size = strlen(ar);

  if (size >= kAr_size) {
    std::cout << "Wrong size of word." << std::endl;
    return;
  }

  char *begin_ptr{ar};
  char *end_ptr{begin_ptr + size - 1};

  while (begin_ptr < end_ptr) {
    swap(begin_ptr++, end_ptr--);
  }
  std::cout << "Reverse word: " << ar << std::endl;
}

void print_array(const unsigned int array[], const size_t size) {
  if (array == nullptr) {
		std::cout << "Error/nullptr" << std::endl;
		return;
	}
  std::cout << "Array[";
  for (size_t i{0}; i < size; ++i) {
    std::cout << array[i];
    if (i != size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

void sort_for_insert_in_valid_range(unsigned int* begin, unsigned int* end,
                     const unsigned int num_element) {
  if (begin == nullptr && end == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }

  while (*begin < num_element && *begin != 0 && begin < end) {
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
  const auto kMin{1};
  const auto kMax{100};

  unsigned int array[kArraySize]{0};
  unsigned int num_element{};

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

    sort_for_insert(array, array + kArraySize - 1, num_element);

    std::cout
        << "\n\nInsert (any number) if you want to see a content of tha array."
        << std::endl;
    std::cout << "Insert (any only 1 letter) if you don't want to see."
              << std::endl;
    char key{};
    std::cin >> key;
    if (isdigit(key)) {
      print_array(array, kArraySize);
    }
  }
  std::cout << std::endl;
}

void sort_upOrdownto(char *const begin, UpOrDown choice) {
  if (begin == nullptr) {
    std::cout << "Error/nullptr" << std::endl;
    return;
  }

  if (choice) {
    if (*begin >= kFirstLowRegister && *begin <= kLastLowRegister) {
      *begin -= kNumForChangeRegister;
    }
    return;
  }
  if (*begin >= kFirstUpRegister && *begin <= kLastUpRegister) {
    *begin += kNumForChangeRegister;
  }
}

void UPorDOWNto(UpOrDown choice) {
  char word[_MAX_PATH]{};
  std::cout << "Input word: ";
  std::cin >> word;
  char *begin = word;
  if (choice) {
    while (*begin) {
      sort_upOrdownto(begin++, UpOrDown::UP);
    }
    std::cout << "Word in upper register: " << word << "\n" << std::endl;
    return;
  }
  while (*begin) {
    sort_upOrdownto(begin++, UpOrDown::DOWN);
  }
  std::cout << "Word in lower register: " << word << "\n" << std::endl;
}

void is_digit() {
  char word[_MAX_PATH]{};
  std::cout << "Input word: ";
  std::cin >> word;
  char *begin = word;

  std::cout << "Is digit: ";
  while (*begin) {
    if (*begin >= kFirstNum && *begin <= kLastNum) {
      std::cout << "_" << *begin;
    }
    begin++;
  }
  std::cout << "\n" << std::endl;
}

enum { REVERSE_WORD = 1, INSERT_ELEMENT, UPPER_WORD, DOWN_WORD, IS_DIGIT };

int main() {
  do {
    std::cout << "1) Enter 1 |  to reverse your word (look --> kool)"
              << std::endl;
    std::cout << "2) Enter 2 |  to insert element in massive\n" << std::endl;
    std::cout << "3) Enter 3 |  to translate word in upper register"
              << std::endl;
    std::cout << "4) Enter 4 |  to translate word in lower register"
              << std::endl;
    std::cout << "5) Enter 5 |  to check for is digit\n" << std::endl;
    int key{};
    std::cin >> key;
    switch (key) {
    case REVERSE_WORD:
      reverse_array();
      break;
    case INSERT_ELEMENT:
      insert_element();
      break;
    case UPPER_WORD:
      UPorDOWNto(UpOrDown::UP);
      break;
    case DOWN_WORD:
      UPorDOWNto(UpOrDown::DOWN);
      break;
    case IS_DIGIT:
      is_digit();
      break;
    default:
      return 0;
    }
  } while (true);

  return 0;
}
