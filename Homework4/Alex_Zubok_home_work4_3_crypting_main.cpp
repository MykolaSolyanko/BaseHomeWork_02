#include "crypting_string.hpp"

int main() {
  const size_t kMaxSizeString = 1000;
  const char kEnter = '\n';
  std::cout << "Please enter your string for crypt to " << kMaxSizeString
            << " symbols, and press 'enter': ";

  char *tmp_string = new char[kMaxSizeString]{};
  std::cin.clear();
  std::cin.get(tmp_string, kMaxSizeString, kEnter);

  // align a string to quadratic number
  const int kSize_string =
      pow(((sqrt(strlen(tmp_string)) -
            static_cast<int>(sqrt(strlen(tmp_string)))) > 0)
              ? static_cast<int>(sqrt(strlen(tmp_string))) + 1
              : static_cast<int>(sqrt(strlen(tmp_string))),
          2);
  char *string = new char[kSize_string]{};
  strncpy(string, tmp_string, strlen(tmp_string));
  delete[] tmp_string;

  std::cout << "Your string before encrypt is :" << string << std::endl;
  // add symbol '*' to end of string
  char *tmp = new char[kSize_string - strlen(string)]{};
  for (size_t i = 0; i < kSize_string - strlen(string); i++)
    *(tmp + i) = '*';
  strncat(string, tmp, kSize_string - strlen(string));
  delete[] tmp;
  // encrypt string
  encrypt_string(string);
  std::cout << "Your encrypted string is: " << string << std::endl;
  delete[] string;

  // decrypt string
  std::cout << "Please enter your key for decrypt string: ";
  size_t decrypt_key{};
  std::cin >> decrypt_key;
  std::cout << "Please enter method of reading string: 1) from file; 2) from "
               "output: ";
  size_t method{};
  std::cin >> method;

  // decrypt from file
  if (method == file) {
    std::cout << "Please enter your file path and filename: ";
    char *file_name = new char[kMaxSizeString];
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), kEnter);
    std::cin.get(file_name, kMaxSizeString, kEnter);
    std::ifstream File(file_name);
    if (File.is_open()) {
      char *output_decrypt_str = new char[kMaxSizeString]{};
      File.get(output_decrypt_str, kMaxSizeString, kEnter);
      decrypt_string(output_decrypt_str, decrypt_key);
      std::cout << "Your decrypted string is: " << output_decrypt_str
                << std::endl;
      delete[] output_decrypt_str;
    } else
      std::cout << "Couln't open file " << file_name << std::endl;
    delete[] file_name;
  }
  // from output
  else if (method == output) {
    std::cout << "Please enter your string for decrypt to 1000 symbols:";
    char *output_decrypt_str = new char[kMaxSizeString]{};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), kEnter);
    std::cin.get(output_decrypt_str, kMaxSizeString, kEnter);
    decrypt_string(output_decrypt_str, decrypt_key);
    std::cout << "Your decrypted string is: " << output_decrypt_str
              << std::endl;
    delete[] output_decrypt_str;
  } else
    std::cout << "You enter not right's method!\n";

  return 0;
}
