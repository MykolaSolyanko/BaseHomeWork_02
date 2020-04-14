#include <iostream>
class Singleton {
public:
  static Singleton &getInstance() {
    std::cout << __FUNCSIG__ << std::endl;
    static Singleton _instance_;
    return _instance_;
  }
  Singleton(Singleton const &) = delete;
  Singleton &operator=(Singleton const &) = delete;
  ~Singleton() { std::cout << __FUNCSIG__ << std::endl; }

private:
  Singleton() { std::cout << __FUNCSIG__ << std::endl; };
};

int main() {
  Singleton::getInstance();
  Singleton::getInstance();
  return 0;
}
