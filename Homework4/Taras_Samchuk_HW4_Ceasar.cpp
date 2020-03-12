#include <chrono>
#include <cstring>
#include <functional>
#include <iostream>
#include <random>

const size_t message_max_lenght{255};
const char k_letter_BIG_A{'A'};
const char k_letter_BIG_Z{'Z'};
const char k_letter_small_a{'a'};
const char k_letter_small_z{'z'};
const char k_letters_count = k_letter_BIG_Z - k_letter_BIG_A + 1;

enum Code { OK, TO_BIG_KEY, TO_SMALL_KEY };

Code CaesarCode(char *Letter, int Key) {
  if (Key == 0) return Code::TO_SMALL_KEY;
  if (Key > k_letters_count || Key < (-k_letters_count)) return TO_BIG_KEY;
  // is letter
  if ((*Letter >= k_letter_BIG_A && *Letter <= k_letter_BIG_Z) ||
      (*Letter >= k_letter_small_a && *Letter <= k_letter_small_z)) {
    if (*Letter >= k_letter_BIG_A && *Letter <= k_letter_BIG_Z) {
      *Letter += Key;
      *Letter =
          (*Letter >= k_letter_BIG_Z) ? *Letter - k_letters_count : *Letter;
      *Letter =
          (*Letter < k_letter_BIG_A) ? *Letter + k_letters_count : *Letter;
    } else {
      *Letter += Key;
      *Letter =
          (*Letter >= k_letter_small_z) ? *Letter - k_letters_count : *Letter;
      *Letter =
          (*Letter < k_letter_small_a) ? *Letter + k_letters_count : *Letter;
    }
  };

  return Code::OK;
}


int main(int argc, char const *argv[]) {
  std::cout << R"(
   The program encodes messages by Caesar's method.
   The encoding can be done by direct code (key value
   is positive) or reverse (key value is negative).
   For decoding, use the key with the opposite sign.
        Example.
      If the encoding key is 15, then the 
        decoding key is -15.
      If the encoding key is -7 then the 
        decoding key is 7.
   The encoding key cannot be 0 (zero))"
            << std::endl;
  short Key{0};
  do {
    if (!Key) {
      std::cout << "Enter Key [1.." << (int)(k_letters_count) << "]>";
    }
    std::cin >> Key;
  } while (!Key);
  std::cout
      << "Enter a message to encrypt. Complete the entry with a dot \".\"\n>";
  char Message[message_max_lenght]{};
  std::cin.getline(Message, message_max_lenght, '.');
  std::cout << "Key" << Key << "\nMessage\n===\n"
            << Message << "\n===" << std::endl;
  char *MesPtr = Message;
  do {
    Code GetError = CaesarCode(MesPtr++, Key);
    if (GetError == TO_BIG_KEY) {
      std::cout << "TO_BIG_KEY";
      break;
    }
    if (GetError == TO_SMALL_KEY) {
      std::cout << "TO_SMALL_KEY";
      break;
    }
  } while (*MesPtr != '\0');
  // Encrypted message
  std::cout << "Encrypted message\n===\n" << Message << "\n===" << std::endl;
  return 0;
}
