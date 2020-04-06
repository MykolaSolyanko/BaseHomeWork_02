#include <iostream>

template <typename T> class smart_ptr {
public:
  smart_ptr(T *ptr) : data{ptr} { std::cout << __FUNCSIG__ << std::endl; }
  ~smart_ptr() {
    delete data;
    std::cout << __FUNCSIG__ << std::endl;
  }
  T *get() { return data; }

private:
  T *data;
};
template <typename T> class smart_ptr<T[]> {
public:
  smart_ptr(T *ptr) : data{ptr} {
    set_size(ptr);
    std::cout << __FUNCSIG__ << std::endl;
  }
  ~smart_ptr() {
    delete[] data;
    std::cout << __FUNCSIG__ << std::endl;
  }
  T *get() { return data; }
  int get_size() { return size; }
  int set_size(T *data) { return size = _msize(data) / sizeof(T); }

private:
  T *data;
  int size;
};

int main() {
  {
    std::cout << "Smart-pointer default template demonstration " << std::endl;
    smart_ptr<int> sptr1{new int{10}};
  }
  {
    std::cout
        << "\nSmart-pointer specialization template demonstration for int array"
        << std::endl;
    smart_ptr<int[]> sptr2{new int[4]{0, 1, 2, 3}};
    std::cout << sptr2.get_size() << std::endl;
    for (int i = 0; i < sptr2.get_size(); ++i) {
      std::cout << *(sptr2.get() + i) << std::endl;
    }
  }
  {
    std::cout << "\nsSmart-pointer specialization template demonstration for "
                 "double array"
              << std::endl;
    smart_ptr<double[]> sptr3{new double[5]{6.1, 0.1}};
    std::cout << sptr3.get_size() << std::endl;
    for (int i = 0; i < sptr3.get_size(); ++i) {
      std::cout << *(sptr3.get() + i) << std::endl;
    }
  }
  return 0;
}
