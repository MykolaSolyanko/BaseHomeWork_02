#include "Header.hpp"
#include <iostream>

enum { SQUARE = 1, TRIANGLE, RECTANGLE };

Square CreateS() {
  std::cout << "\nInput the size of side of square: ";
  size_t side{};
  std::cin >> side;
  Square exemp{side};
  return exemp;
}

Triangle CreateT() {
  std::cout << "\nInput the size of side of triangle: ";
  size_t side{}, height{};
  std::cin >> side;
  std::cout << "\nInput the size of height of triangle: ";
  std::cin >> height;
  Triangle exemp{side, height};
  return exemp;
}

Rectangle CreateR() {
  std::cout << "\nInput the size of smaller_side of rectangle: ";
  size_t smaller_side{}, bigger_side{};
  std::cin >> smaller_side;
  std::cout << "\nInput the size of bigger_side of rectangle: ";
  std::cin >> bigger_side;
  Rectangle exemp{smaller_side, bigger_side};
  return exemp;
}

void fact_method(IShape &sh) {
  std::cout << "\nThe square is " << sh.calc_square() << std::endl;
  sh.draw();
}

int main() {
  do {
    std::cout << "Enter 1 | to work with square" << std::endl;
    std::cout << "Enter 2 | to work with triangle" << std::endl;
    std::cout << "Enter 3 | to work with rectangle" << std::endl;
    size_t choice{};
    std::cin >> choice;
    switch (choice) {
    case SQUARE: {
      Square s = CreateS();
      fact_method(s);
      break;
    }
    case TRIANGLE: {
      Triangle s = CreateT();
      fact_method(s);
      break;
    }
    case RECTANGLE: {
      Rectangle s = CreateR();
      fact_method(s);
      break;
    }
    default:
      return 0;
    }
  } while (true);

  system("pause");
  return 0;
}
