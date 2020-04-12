#include "Header.h"

int main() {
  std::cout
      << "This program realize one of classic data structures - Stack. \n";
  Stack st;
  std::cout << "Stack size: " << st.GetSizeStack() << std::endl;
  int value;
  {
    Pair pair{true, ""};
    while (pair.status == true) {
      std::cin >> value;
      pair = st.push(value, pair);
    }
    std::cout << pair.msg << std::endl;
  }
  std::cout << "top " << st.top() << std::endl;
  {
    Pair pair{true, ""};
    for (int i = 0; i != 6; i++) {
      pair = st.pop(pair);
    }
    std::cout << pair.msg << std::endl;
  }
  st.clear();
  std::cout << "new top after clear: " << st.top() << std::endl;

  {
    Pair pair{true, ""};
    for (int i = 0; i != 6; i++) {
      std::cin >> value;
      pair = st.push(value, pair);
    }
    std::cout << pair.msg << std::endl;
  }
  std::cout << "top after iter push: " << st.top() << std::endl;

  for (Pair pair{true, ""}; pair.status == true; pair = st.pop(pair)) {
  }

  std::cout << "new top after popping " << st.top() << std::endl;

  return 0;
}

