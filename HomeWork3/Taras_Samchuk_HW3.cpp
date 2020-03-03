// Working with pointers
#include <cstdio>
#include <iostream>

const size_t k_max_char_len{255};
//==============================================================
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
    "REVERSE  WORD",
    "INSERT TO ARRAY",
    "DELETE FROM ARRAY",
    "small letter",
    "DETECT DIGITS",
    "CAPITAL LETTERS"};

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
  const uint8_t k_letter_BIG_A = 65;
  const uint8_t k_letter_BIG_Z = 90;
  uint8_t Mask = 1 << 5;
  // u_int8_t Mask = 0b00'100'000;
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

  uint8_t Mask = ~(1 << 5);
  // u_int8_t Mask = 0b11'011'111;
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
  size_t len{0};
  while (*(text + len) != '\0') len++;
  for (size_t i = 0; i < len / 2; i++) {
    SwapChar((text + i), (text + len - i - 1));
  }
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
  short Array[k_array_size]{0};
  std::cout << "Stating programm";
  for (auto show : Array) {
    std::cout << "[" << show << "]";
  }
  std::cout << std::endl;
  int NewElem{3};
  size_t NewPos{0};
  do {
    if (Array[NewPos] < NewElem) {
      NewPos++;
      continue;
    }
    //треба свап робити у форі мабуть
    for (size_t from_teils{5}; from_teils > 3; from_teils--) {
      std::cout << '[' << from_teils << ',' << NewPos << ']';
    }

    //записуємо
    Array[NewPos] = NewElem;

    //тут тільки лог виводиться
    for (auto show : Array) {
      std::cout << "[" << show << "]";
    }
    std::cout << std::endl;
  } while (Array[k_array_size - 1] == 0);
}
void DeleteFromArray() {
  std::cout << R"(
    +-----------------+
    |DELETE FROM ARRAY|
    +-----------------+
    +--------------------------------+
    ||
    +--------------------------------+
  )";
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
  size_t len{0};
  while (*(text + len) != '\0') {
    DOWNto(text + len);
    len++;
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
  size_t len{0};
  while (*(text + len) != '\0') {
    len++;
    std::cout << *(text + len) << " "
              << (IsDigit(text + len) ? "is digit" : "is not digit")
              << std::endl;
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
  size_t len{0};
  while (*(text + len) != '\0') {
    toUP(text + len);
    len++;
  }
  std::cout << "IN CAPITAL LETTERS \"" << text << "\"" << std::endl;
}

int main() {
  std::cout << R"(
    +-----------------+
    |   HOME WORK 3   |
    +-----------------+)";
 // do  // forever loop
  {
    Label Sel{LABEL_REVERSE_WORD};
    switch (6)/* (Menu()) */ {
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
  }// while (true);
    /*
  ReverseLine();
  //InsertToArray();
  //DeleteFromArray();
  ToUpper();
  IsDigit();
  ToLower();*/
  std::cout << R"(
    +-----------------+
    |      E N D      |
    +-----------------+)"
            << std::endl;
  return 0;
}