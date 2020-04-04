#include "crypting_string.hpp"

int main() {
  std::cout
      << "Please enter your string for crypt to 1000 symbols without 'enter': ";
  char *tmp_string = new char;
  std::cin.get(tmp_string, 1000, '\n');
  const int kSize_string =
      pow(((sqrt(std::strlen(tmp_string)) -
            static_cast<int>(sqrt(std::strlen(tmp_string)))) > 0)
              ? static_cast<int>(sqrt(std::strlen(tmp_string))) + 1
              : static_cast<int>(sqrt(std::strlen(tmp_string))),
          2);
  char *string = new char[kSize_string]{};
  std::strncpy(string, tmp_string, std::strlen(tmp_string));
  std::cout << "Your string before encrypt is :" << string << std::endl;
  delete tmp_string;
  char *tmp = new char[kSize_string - std::strlen(string)];
  for (size_t i = 0; i < kSize_string - std::strlen(string); i++)
    *(tmp + i) = '*';
  std::strncat(string, tmp, kSize_string - std::strlen(string));
  encrypt_string(string);
  std::cout << "Your encrypted string is: " << string << std::endl;
  delete[] string;
  std::cout << "Please enter your key for decrypt string: ";
  size_t key{};
  std::cin >> key;
  std::cout << "Please enter method of reading string: 1) from file; 2) from "
               "output: ";
  size_t method{};
  std::cin >> method;
  if (method == 1) {
    std::cout << "Please enter your file path and filename: ";
    char *file_str = new char;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(file_str, 1000, '\n');
    std::ifstream File;
    File.open(file_str, std::ios_base::in);
    char *detmp_str = new char;
    if (File.is_open()) {
      File.get(detmp_str, 1000, '\n');
      char *de_string = new char[std::strlen(detmp_str)]{};
      std::strncat(de_string, detmp_str, std::strlen(detmp_str));
      decrypt_string(de_string, key);
      std::cout << "Your decrypted string is: " << de_string << std::endl;
      File.close();
      delete detmp_str;
      delete[] de_string;
    } else
      std::cout << "Couln't open file " << file_str << std::endl;
    File.close();
    delete file_str;
  } else if (method == 2) {
    std::cout << "Please enter your string for decrypt to 1000 symbols:";
    char *entmp_str = new char;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(entmp_str, 1000, '\n');
    char *en_string = new char[std::strlen(entmp_str)]{};
    std::strncat(en_string, entmp_str, std::strlen(entmp_str));
    delete entmp_str;
    decrypt_string(en_string, key);
    std::cout << "Your decrypted string is: " << en_string << std::endl;
    delete[] en_string;
  } else
    std::cout << "You enter not right's method!\n";

  return 0;
}
