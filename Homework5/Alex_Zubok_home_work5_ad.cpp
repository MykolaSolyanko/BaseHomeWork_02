#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

void revrot(std::string str, const size_t size) {
  if (size < 1 || str.empty() || size > str.size()) {
    std::cout << "revrot(\"" << str << "\", " << size << ") --> \"";
    str = "";
    std::cout << str << "\"" << std::endl;
    return;
  }
  std::string str_copy = str;
  size_t pos{};
  size_t size_str = str.size();
  while (size_str >= size) {
    std::string sub_str = str.substr(pos, size);
    size_t index{};
    double summ_cubic{};
    const size_t kSumbol = 1;
    while (index < size) {
      summ_cubic += pow(std::stoi(sub_str.substr(index, kSumbol)), 3);
      ++index;
    }
    const size_t kZeroSymbol = 0;
    if ((summ_cubic / 2 - static_cast<int>(summ_cubic / 2)) > 0) {
      sub_str += sub_str.substr(kZeroSymbol, kSumbol);
      sub_str.erase(kZeroSymbol, kSumbol);
      str.replace(pos, size, sub_str);
    } else {
      std::reverse(sub_str.begin(), sub_str.end());
      str.replace(pos, size, sub_str);
    }
    pos += size;
    size_str -= size;
  }
  str.resize(str.size() - size_str);
  std::cout << "revrot(\"" << str_copy << "\", " << size << ") --> \"" << str
            << "\"" << std::endl;
}

int main() {
  revrot("123456987654", 6);
  revrot("123456987653", 6);
  revrot("66443875", 4);
  revrot("66443875", 8);
  revrot("664438769", 8);
  revrot("123456779", 8);
  revrot("", 8);
  revrot("123456779", 0);
  revrot("563000655734469485", 4);
  return 0;
}
