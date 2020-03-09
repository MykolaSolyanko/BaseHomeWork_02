// Working with pointers
#include <cstdio>
#include <iostream>
#include <random>
#include <cstring>

const short k_item_len{25};
enum Label {
  LABEL_EXIT = 0,
  LABEL_REVERSE_WORD,
  LABEL_INSET_TO_ARRAY,
  LABEL_DELETE_FROM_ARRAY,
  LABEL_SMALL_LETTERS,
  LABEL_DETECT_DIGITS,
  LABEL_CAPITAL_LETTERS,
  LABEL_COUNT
};
const char k_Items[Label::LABEL_COUNT][k_item_len]{
    "EXIT",  //
    "REVERSE  WORD", "INSERT TO ARRAY", "DELETE FROM ARRAY",
    "small letter",  "DETECT DIGITS",   "CAPITAL LETTERS"};
const char k_letter_BIG_A{'A'};
const char k_letter_BIG_Z{'Z'};
const char k_letter_small_a{'a'};
const char k_letter_small_z{'z'};
const char k_letters_count = k_letter_BIG_Z - k_letter_BIG_A;
const size_t k_max_char_len{255};
const char k_letter_diff{32};

bool SwapChar(char *const first_ptr, char *const second_ptr) {
  if (first_ptr == nullptr || second_ptr == nullptr ||
      first_ptr == second_ptr) {
    return false;  // ERROR
  }
  char tmp_ptr = *first_ptr;
  *first_ptr = *second_ptr;
  *second_ptr = tmp_ptr;
  return true;  // OK
}

bool IsDigit(const char Data) {
  const char k_ZERO_code{'0'};
  const char k_NINE_code{'9'};
  return (k_ZERO_code <= Data && Data <= k_NINE_code);
}

//Used only for displaying menus
char AlphabetLetterByIndex(const char letter_index) {
  return (0 < letter_index && letter_index < k_letters_count + 1) ? k_letter_BIG_A + letter_index - 1
                                                : '\0';
}

// down
bool DOWNto(char *const DOWN2) {
  if (DOWN2 == nullptr) {
    return false;  // ERROR
  }
  *DOWN2 = (k_letter_BIG_A <= *DOWN2 && *DOWN2 <= k_letter_BIG_Z)
               ? *DOWN2 + k_letter_diff
               : *DOWN2;
  return true;  // OK
}

// UP
bool toUP(char *const toUP) {
  if (toUP == nullptr) {
    return false;  // ERROR
  }
  *toUP = (k_letter_small_a <= *toUP && *toUP <= k_letter_small_z)
              ? *toUP - k_letter_diff
              : *toUP;
  return true;  // OK
}

// Displays the menu 
int Menu() {
  std::cout << R"(
    +-----------------+
    |   SELECT TASK   |
    +-----------------+)";
  std::cout << std::endl;
  char S[Label::LABEL_COUNT + 1];
  for (size_t MenuItem{0}; MenuItem < Label::LABEL_COUNT; MenuItem++) {
    S[MenuItem] = AlphabetLetterByIndex(MenuItem + 1);
    std::cout << "\t(" << S[MenuItem] << ")  " << k_Items[MenuItem]
              << std::endl;
  }
  S[Label::LABEL_COUNT] = AlphabetLetterByIndex(0);
  char choice{};
  bool not_ok{false};
  do {
    if (not_ok) std::cout << "\tWrong choice " << std::endl;
    std::cout << "\tMake a choice [ENTER]" << std::endl;
    std::cin >> choice;
    // std::cin.get(choice, 1);
    std::cin.clear();
    not_ok = true;
    toUP(&choice);
  } while (!strchr(S, choice));
  return (choice - k_letter_BIG_A);
}

void ReverseLine() {
  std::cout << R"(
    +-----------------+
    |  REVERSE  WORD  |
    +-----------------+
    +--------------------------------+
    |   We   reflect   the   line    |
    +--------------------------------+
  )";
  std::cout << "Enter line" << std::endl;
  char text[k_max_char_len]{};
  std::cin.ignore();
  std::cin.get(text, k_max_char_len);
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  char *begin_ptr = text;
  char *end_ptr = begin_ptr;
  while (*end_ptr != '\0') {
    end_ptr++;
  }
  end_ptr--;
  do {
    SwapChar(begin_ptr++, end_ptr--);
  } while (begin_ptr < end_ptr);
  std::cout << "The reflected line \"" << text << "\"" << std::endl;
}

void InsertToArray() {
  std::cout << R"(
    +-----------------+
    | INSERT TO ARRAY |
    +-----------------+
    +--------------------------------+
    |We insert a value into an array |
    +--------------------------------+
  )";
  const size_t k_array_size{10};
  const unsigned int k_empti{0};
  const unsigned int k_max{255};
  unsigned int Array[k_array_size]{0};
  for (auto show : Array) {
    std::cout << '{' << show << '}';
  }
  std::cout << std::endl;

  do {
    std::cout << "Enter a integer number to place in the array=";
    int NewData;
    std::cin >> NewData;
    if (!(k_empti < NewData && NewData < k_max)) {
      std::cout << "The number must not be (" << k_empti << "," << k_max << "]"
                << std::endl;
      std::cin.ignore();
      continue;
    }
    unsigned int *arr_ptr = Array;
    while (NewData > *arr_ptr && *arr_ptr != 0) {
      arr_ptr++;
    }
    unsigned int *arr_end_ptr = Array + k_array_size - 1;
    if (*arr_ptr != 0) {
      for (unsigned int *i_ptr = arr_end_ptr; i_ptr > arr_ptr; i_ptr--) {
        *i_ptr = *(i_ptr - 1);
      }
    }
    *arr_ptr = NewData;
    for (auto show : Array) {
      std::cout << '{' << show << '}';
    }
    std::cout << std::endl;
  } while (!Array[k_array_size - 1]);
}
void DeleteFromArray() {
  std::cout << R"(
    +-----------------+
    |DELETE FROM ARRAY|
    +-----------------+
    +--------------------------------+
    |   Delete   item   by   value   |
    +--------------------------------+
  )";
  const size_t k_array_size{20};
  const int k_empty{0};
  const int k_min_find{1};
  const int k_max_find{10};

  int Array[k_array_size];
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(k_min_find, k_max_find);

  for (auto &value : Array) {
    value = dist(mt);
  }

  int DeleteThis;

  do {
    for (auto show : Array) {
      std::cout << '{' << show << '}';
    }
    std::cout << std::endl;

    std::cout
        << "What we delete?\nIf you do not delete anything, write a number "
        << k_empty << ". We can look for numbers from " << k_min_find << " to "
        << k_max_find << ".\nYour choice " << std::endl;
    std::cin >> DeleteThis;
    if (DeleteThis == k_empty) {
      std::cout << "We are not looking for anything.\n We finish the program"
                << std::endl;
      break;
    }
    int *array_ptr = Array;
    const int *const end = Array + k_array_size;
    do {
      if (*array_ptr == DeleteThis) {
        std::cout << "Found {" << DeleteThis << "}. Deleting" << std::endl;
        *(array_ptr) = k_empty;
      }
      array_ptr++;
    } while (end != array_ptr);

  } while (DeleteThis != k_empty);
}

void ToLower() {
  std::cout << R"(
    +-----------------+
    |   small letter  |
    +-----------------+
    +--------------------------------+
    |   rewrite word small letters   |
    +--------------------------------+
  )";
  std::cout << "Enter word" << std::endl;
  char text[k_max_char_len]{};
  std::cin.ignore();
  std::cin.get(text, k_max_char_len);
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  char *text_ptr = text;
  while (*text_ptr != '\0') {
    DOWNto(text_ptr++);
  }
  std::cout << " lowercase letters \"" << text << "\"" << std::endl;
}

void IsDigit() {
  std::cout << R"(
    +-----------------+
    |  DETECT DIGITS  |
    +-----------------+
    +--------------------------------+
    |the number detector in the word |
    +--------------------------------+
  )";
  std::cout << "Enter word" << std::endl;
  char text[k_max_char_len]{};
  std::cin.ignore();
  std::cin.get(text, k_max_char_len);
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  char *text_ptr = text;
  while (*text_ptr != '\0') {
    std::cout << *text_ptr << " "
              << (IsDigit(*text_ptr) ? "is digit" : "is not digit")
              << std::endl;
    text_ptr++;
  }
}

void ToUpper() {
  std::cout << R"(
    +-----------------+
    | CAPITAL LETTERS |
    +-----------------+
    +--------------------------------+
    |  REWRITE WORD CAPITAL LETTERS  |
    +--------------------------------+
  )";

  std::cout << "Enter word" << std::endl;
  char text[k_max_char_len]{};
  std::cin.ignore();
  std::cin.get(text, k_max_char_len);
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  char *text_ptr = text;
  while (*text_ptr != '\0') {
    toUP(text_ptr++);
  }
  std::cout << "IN CAPITAL LETTERS \"" << text << "\"" << std::endl;
}

int main() {
  std::cout << R"(
    +-----------------+
    |   HOME WORK 3   |
    +-----------------+)";
  do {
    switch (Menu()) {
      case LABEL_EXIT:
        return 0;
        break;
      case LABEL_REVERSE_WORD:
        ReverseLine();
        break;
      case LABEL_INSET_TO_ARRAY:
        InsertToArray();
        break;
      case LABEL_DELETE_FROM_ARRAY:
        DeleteFromArray();
        break;
      case LABEL_SMALL_LETTERS:
        ToLower();
        break;
      case LABEL_DETECT_DIGITS:
        IsDigit();
        break;
      case LABEL_CAPITAL_LETTERS:
        ToUpper();
        break;
      default:
        break;
    }
  } while (true);
  std::cout << R"(
    +-----------------+
    |      E N D      |
    +-----------------+)"
            << std::endl;
  return 0;
}
