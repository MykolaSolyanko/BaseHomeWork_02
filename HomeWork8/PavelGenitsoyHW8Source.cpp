#include "Header.hpp"
#include <iostream>

static const auto kForSquareTrangle{0.5};

void Square::draw() {
  std::cout << "Its a Square.\n" << std::endl;
  for (int i = 0; i < side; i++) {
    std::cout << "\t";
    for (int j = 0; j < side; j++) {
      std::cout << "*"
                << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

double Square::calc_square() { return side * side; }

void Triangle::draw() {
  std::cout << "Its a Triangle.\n" << std::endl;
  for (int i = 0; i < side; i++) {
    std::cout << "\t";
    for (int j = 0; j != i + 1; j++) {
      std::cout << "*"
                << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

double Triangle::calc_square() { return kForSquareTrangle * (side * height); }

void Rectangle::draw() {
  std::cout << "Its a Rectangle.\n" << std::endl;
  for (int i = 0; i < smaller_side; i++) {
    std::cout << "\t";
    for (int j = 0; j < bigger_side; j++) {
      std::cout << "*"
                << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

double Rectangle::calc_square() { return smaller_side * bigger_side; }
