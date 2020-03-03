// Working with pointers
#include <cstdio>
#include <iostream>
#include <random>

const size_t k_max_char_len{255};
//==============================================================
/*
const short k_item_len{50};
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

// The function returns a value if it is within the range.
// Executes until the correct value is entered
int64_t GetInInRange(const int64_t aMin, const int64_t aMax) {
  int64_t Input;
  do {
    std::cout << ">";
    std::cin >> Input;
  } while (aMin > Input || Input > aMax);
  return Input;
}

// Displays the menu and returns the selected item number
int Menu() {
  std::cout << R"(
    +-----------------+
    |   SELECT TASK   |
    +-----------------+)";
  std::cout << std::endl;
  for (size_t MenuItem{0}; MenuItem < Label::LABEL_COUNT; MenuItem++) {
    std::cout << "\t(" << MenuItem + 1 << ")  " << k_Items[MenuItem]
              << std::endl;
  }
  std::cout << "\tEnter the number and press [ENTER]" << std::endl;
  return GetInInRange(1, Label::LABEL_COUNT) - 1;
}
*/
//==============================================================

int SwapChar(char *const first_ptr, char *const second_ptr) {
  if (first_ptr == nullptr || second_ptr == nullptr ||
      first_ptr == second_ptr) {
    return 1;  // ERROR
  }
  char tmp_ptr = *first_ptr;
  *first_ptr = *second_ptr;
  *second_ptr = tmp_ptr;
  return 0;  // OK
}
bool IsDigit(const char *const Data) {
  /*
      Fragment of ASCI table
            for digits
      DEC OCT HEX CH     BIN
      48  60  30  0   0011'0000
      49  61  31  1   0011'0001
      50  62  32  2   0011'0010
      51  63  33  3   0011'0011
      52  64  34  4   0011'0100
      53  65  35  5   0011'0101
      54  66  36  6   0011'0110
      55  67  37  7   0011'0111
      56  70  38  8   0011'1000
      57  71  39  9   0011'1001
  */
  // '0' in ASCI dec(48) hex(0x30) oct(060) bin(0b0011'0000)
  const char k_ZERO_code{48};
  // '9' in ASCI dec(57) hex(0x39) oct(071) bin(0b0011'1001)
  const char k_NINE_code{57};
  return (k_ZERO_code <= *Data && *Data <= k_NINE_code) ? true : false;
}

/*
    An excerpt of the ASCI table for some letters
dec  oct  hex    BIN    ch    dec  oct  hex     BIN
              76543210                       76543210
65   101  41  100'0001  A     97   141   61  110'0001  a
66   102  42  100'0010  B     98   142   62  110'0010  b
67   103  43  100'0011  C     99   143   63  110'0011  c
...  ...  ...   ...    ...   ...   ...  ...    ...    ...
89   131  59  101'1001  Y    121   171   79  111'1001  y
90   132  5A  101'1010  Z    122   172   7A  111'1010  z
              [^]                            [^]
            5-bit                          5-bit
*/
// down
int DOWNto(char *const DOWN2) {
  if (DOWN2 == nullptr) {
    return 1;  // ERROR
  }
  const uint8_t k_letter_BIG_A{65};
  const uint8_t k_letter_BIG_Z{90};
  // uint8_t Mask = 1 << 5;
  u_int8_t Mask{0b00'100'000};
  *DOWN2 = (k_letter_BIG_A <= *DOWN2 && *DOWN2 <= k_letter_BIG_Z)
               ? *DOWN2 | Mask  // 5 bit set
               : *DOWN2;
  return 0;  // OK
}
// UP
int toUP(char *const toUP) {
  if (toUP == nullptr) {
    return 1;  // ERROR
  }
  const uint8_t k_letter_small_a = 97;
  const uint8_t k_letter_small_z = 122;

  // uint8_t Mask = ~(1 << 5);
  u_int8_t Mask{0b11'011'111};
  *toUP = (k_letter_small_a <= *toUP && *toUP <= k_letter_small_z)
              ? *toUP & Mask  // 5 bit reset
              : *toUP;
  return 0;  // OK
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
  const size_t k_len{k_max_char_len};
  std::cout << "Enter word" << std::endl;
  char text[k_len];
  std::cin.get(text, k_len);

  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  char *begin_ptr = text;
  char *end_ptr = begin_ptr;
  while (*(end_ptr + 1) != '\0') {
    ++end_ptr;
  }
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
  int NewData;
  unsigned int *arr_ptr = Array;
  do {
    arr_ptr = Array;
    std::cout << "New=";
    std::cin >> NewData;
    if (!(k_empti < NewData && NewData < k_max)) {
      std::cout << "The number must not be (" << k_empti << "," << k_max << "]"
                << std::endl;
      continue;
    }
    while (NewData > *arr_ptr && *arr_ptr != 0) {
      arr_ptr++;
    }
    unsigned int *arr_end_ptr = Array + k_array_size - 1;
    while (*arr_ptr != 0) {
      for (unsigned int *i_ptr = arr_end_ptr; i_ptr > arr_ptr; i_ptr--) {
        *i_ptr = *(i_ptr - 1);
      }
      *arr_ptr = k_empti;
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

  for (size_t index{0}; index < k_array_size; index++) {
    Array[index] = dist(mt);
  }
  std::cout << std::endl;

  int DeleteThis;
  int *array_ptr = Array;
  do {
    array_ptr = Array;
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
    do {
      if (*array_ptr == DeleteThis) {
        std::cout << "Found {" << DeleteThis << "}. Deleting" << std::endl;
        *(array_ptr) = k_empty;
      }
      array_ptr++;
    } while ((k_array_size - 1) >= *array_ptr);

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
  const size_t k_len{k_max_char_len};
  std::cout << "Enter word" << std::endl;
  char text[k_len];
  std::cin.get(text, k_len);
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
  const size_t k_len{k_max_char_len};
  std::cout << "Enter word" << std::endl;
  char text[k_len];
  std::cin.get(text, k_len);
  std::cout << "You  have  entered \"" << text << "\"" << std::endl;
  char *text_ptr = text;
  while (*text_ptr != '\0') {
    text_ptr++;
    std::cout << *text_ptr << " "
              << (IsDigit(text_ptr) ? "is digit" : "is not digit") << std::endl;
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
  const size_t k_len{k_max_char_len};
  std::cout << "Enter word" << std::endl;
  char text[k_len];
  std::cin.get(text, k_len);
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
  std::cout << R"(
    +-----------------+
    |      E N D      |
    +-----------------+)"
            << std::endl;
  return 0;
}