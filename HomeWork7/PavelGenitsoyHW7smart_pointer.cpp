#include <iostream>

template <typename T> class Smart_Pointer {
public:
  Smart_Pointer(T *tmp) : data{tmp} {
    std::cout << "Alloc for 1 obj" << std::endl;
  }
  ~Smart_Pointer() {
    delete data;
    std::cout << "Dealloc for 1 obj" << std::endl;
  }

private:
  T *data{};
};

template <typename T> class Smart_Pointer<T[]> {
public:
  Smart_Pointer(T *tmp) : data{tmp} {
    std::cout << "Alloc for array of obj" << std::endl;
  }
  ~Smart_Pointer() {
    delete[] data;
    std::cout << "Dealloc for array of obj" << std::endl;
  }

private:
  T *data{};
};

int main() {
  { Smart_Pointer<int> s{new int{10}}; }

  { Smart_Pointer<int[]> s{new int[2]{10, 2}}; }

  system("pause");
  return 0;
}
