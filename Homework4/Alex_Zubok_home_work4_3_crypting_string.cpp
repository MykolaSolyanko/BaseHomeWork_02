#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

void reverse_string(char *string) {
  if (string == nullptr || string + std::strlen(string) == nullptr ||
      std::strlen(string) == 0)
    return;
  char *tmp_string = new char[std::strlen(string)];
  std::strncpy(tmp_string, string, std::strlen(string));
  for (size_t index = std::strlen(tmp_string) - 1, i = 0;
       i < std::strlen(tmp_string); index--, i++)
    *(string + i) = *(tmp_string + index);
  *(string + (std::strlen(tmp_string) - 1)) = *tmp_string;
  delete[] tmp_string;
}

void encrypt_string(char *encrypt_string) {
  size_t key{};
  for (char *c = encrypt_string;
       c != encrypt_string + std::strlen(encrypt_string); c++) {
    if (*c == '*')
      ++key;
  }
  std::cout << "Your key for encrypt string is: " << key << std::endl;
  const size_t kStep = sqrt(std::strlen(encrypt_string));
  char *tmp_string = new char[std::strlen(encrypt_string)];
  std::strncpy(tmp_string, encrypt_string, std::strlen(encrypt_string));
  size_t i{};
  for (char *c_l1 = tmp_string; c_l1 < tmp_string + kStep; c_l1++) {
    for (char *c_l2 = c_l1; c_l2 < tmp_string + std::strlen(tmp_string);
         c_l2 += kStep) {
      *(encrypt_string + i) = *c_l2;
      ++i;
    }
  }
  reverse_string(encrypt_string);
  delete[] tmp_string;
  std::cout << "Do you want save your encrypted string to file[y/n]?: ";
  char file_save = 'n';
  std::cin >> file_save;
  if (file_save == 'y' || file_save == 'Y') {
    std::cout << "Please enter full path and filename: ";
    char *file_name = new char;
    std::cin >> file_name;
    std::ofstream File;
    File.open(file_name, std::ios_base::out);
    if (File.is_open()) {
      File << encrypt_string;

      std::cout << "File successfully saved!" << std::endl;
    } else
      std::cout << "Problem with opening file!" << std::endl;
    File.close();
  }
}

void decrypt_string(char *decrypt_string, const size_t key = 0) {
  reverse_string(decrypt_string);
  const size_t kStep = sqrt(std::strlen(decrypt_string));
  char *tmp_string = new char[std::strlen(decrypt_string)];
  std::strncpy(tmp_string, decrypt_string, std::strlen(decrypt_string));
  size_t i{};
  for (char *c_l1 = tmp_string; c_l1 < tmp_string + kStep; c_l1++) {
    for (char *c_l2 = c_l1; c_l2 < tmp_string + std::strlen(tmp_string);
         c_l2 += kStep) {
      *(decrypt_string + i) = *c_l2;
      ++i;
    }
  }
  for (size_t i = std::strlen(decrypt_string) - 1;
       i > std::strlen(decrypt_string) - key; i--) {
    if (*(decrypt_string + i) == '*')
      *(decrypt_string + i) = '\0';
  }
  delete[] tmp_string;
}
