#include <iostream>

//Дополнить реализованный на лекции шаблоный класс smart_pointer,
//реализовав для него частичную специализацию для динамического массива
//(т.е.вызывать delete[] вместо delete).
//Задание опциональное

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
  smart_ptr(T *ptr) : data{ptr} { std::cout << __FUNCSIG__ << std::endl; }
  ~smart_ptr() {
    delete[] data;
    std::cout << __FUNCSIG__ << std::endl;
  }
  T *get() { return data; }

private:
  T *data;
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
  }
  {
    std::cout << "\nsSmart-pointer specialization template demonstration for "
                 "double array"
              << std::endl;
    smart_ptr<double[]> sptr3{new double[5]{6.1, 0.1}};
  }
  return 0;
}
