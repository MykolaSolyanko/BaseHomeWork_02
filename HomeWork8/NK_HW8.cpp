#include "Header.hpp"
#include <iostream>

enum { SQUARE = 1, TRIANGLE, RECTANGLE, EXIT };
void func(Shape &sh) {
  sh.calc_square();
  sh.draw();
}
int main() {
  while (true) {
    std::cout << "Please choose the shape:" << std::endl;
    std::cout << "1 Square " << std::endl;
    std::cout << "2 Triangle " << std::endl;
    std::cout << "3 Rectangle " << std::endl;
    std::cout << "4 Exit" << std::endl;
    int choise;
    std::cin >> choise;

    switch (choise) {
    case SQUARE: {
      Square s = CreateSquare();
      func(s);
      break;
    }
    case TRIANGLE: {
      RightTriangle t = CreateTriangle();
      func(t);
      break;
    }
    case RECTANGLE: {
      Rectangle r = CreateRectangle();
      func(r);
      break;
    }
    case EXIT:
      return 0;
    default:
      break;
    }
  }

  return 0;
}
