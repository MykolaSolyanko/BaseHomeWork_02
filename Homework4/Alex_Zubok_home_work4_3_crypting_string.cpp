#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse_string(char *string) {
  if (string == nullptr || string + strlen(string) == nullptr ||
      strlen(string) == 0)
    return;
  for (char *c_start = string, *c_end = string + strlen(string) - 1;
       c_start != string + strlen(string) / 2; c_start++, c_end--) {
    swap(c_start, c_end);
  }
}

void encrypt_string(char *encrypt_string) {
  size_t key{};
  for (char *c = encrypt_string; c != encrypt_string + strlen(encrypt_string);
       c++) {
    if (*c == '*')
      ++key;
  }
  std::cout << "Your key for encrypt string is: " << key << std::endl;
  const size_t kStep = sqrt(strlen(encrypt_string));
  char *tmp_string = new char[strlen(encrypt_string)];
  strncpy(tmp_string, encrypt_string, strlen(encrypt_string));
  size_t i{};
  for (char *c_l1 = tmp_string; c_l1 < tmp_string + kStep; c_l1++) {
    for (char *c_l2 = c_l1; c_l2 < tmp_string + strlen(tmp_string);
         c_l2 += kStep) {
      *(encrypt_string + i) = *c_l2;
      ++i;
    }
  }
  delete[] tmp_string;
  reverse_string(encrypt_string);
  std::cout << "Do you want save your encrypted string to file[y/n]?: ";
  char file_save = 'n';
  std::cin >> file_save;
  if (file_save == 'y' || file_save == 'Y') {
    std::cout << "Please enter full path and filename: ";
    const size_t kMaxSizeString = 1000;
    const char kEnter = '\n';
    char *file_name = new char[kMaxSizeString]{};
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), kEnter);
    std::cin.get(file_name, kMaxSizeString, kEnter);
    std::ofstream File(file_name);
    if (File.is_open()) {
      File << encrypt_string;
      std::cout << "File successfully saved!" << std::endl;
    } else
      std::cout << "Problem with opening file!" << std::endl;
    delete[] file_name;
  }
}

void decrypt_string(char *decrypt_string, const size_t key = 0) {
  reverse_string(decrypt_string);
  const size_t kStep = sqrt(strlen(decrypt_string));
  char *tmp_string = new char[strlen(decrypt_string)];
  strncpy(tmp_string, decrypt_string, strlen(decrypt_string));
  size_t i{};
  for (char *c_l1 = tmp_string; c_l1 < tmp_string + kStep; c_l1++) {
    for (char *c_l2 = c_l1; c_l2 < tmp_string + strlen(tmp_string);
         c_l2 += kStep) {
      *(decrypt_string + i) = *c_l2;
      ++i;
    }
  }
  delete[] tmp_string;
  for (size_t i = strlen(decrypt_string); i > strlen(decrypt_string) - key;
       i--) {
    if (*(decrypt_string + i) == '*')
      *(decrypt_string + i) = '\0';
  }
}
