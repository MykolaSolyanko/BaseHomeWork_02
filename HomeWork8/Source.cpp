#include "Header.hpp"
#include <iostream>
const void Square::draw() {
  for (int i = 0; i < side; ++i) {
    for (int j = 0; j < side; ++j) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }
}
double Square::calc_square() {
  std::cout << __FUNCSIG__ << std::endl;
  return side * side;
}
const int Square::get_side() { return side; }
void Square::set_side(int side) { this->side = side; }

const void RightTriangle::draw() {
  if (height < side) {
    std::swap(height, side);
  }
  for (int i = 0; i < height; ++i) {
    if (i <= side) {
      for (int j = 0; j < i; ++j) {
        std::cout << '*';
      }
    } else {
      for (int j = 0; j < side; ++j) {
        std::cout << '*';
      }
    }
    std::cout << std::endl;
  }
}
double RightTriangle::calc_square() {
  std::cout << __FUNCSIG__ << std::endl;
  return static_cast<double>(side * height) / 2;
}
const int RightTriangle::get_side() { return side; }
const int RightTriangle::get_height() { return height; }
void RightTriangle::set_side(int side) { this->side = side; }
void RightTriangle::set_height(int height) { this->height = height; }

const void Rectangle::draw() {
  for (int i = 0; i <= height; ++i) {
    for (int j = 0; j <= width; ++j) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }
}
double Rectangle::calc_square() {
  std::cout << __FUNCSIG__ << std::endl;
  return width * height;
}
const int Rectangle::get_width() { return width; }
const int Rectangle::get_height() { return height; }
void Rectangle::set_width(int width) { this->width = width; }
void Rectangle::set_height(int height) { this->height = height; }

Square CreateSquare() {
  std::cout << "Enter the side of square (integer)" << std::endl;
  int side;
  std::cin >> side;
  Square s{side};
  return s;
}
RightTriangle CreateTriangle() {
  std::cout << "Enter the side and height of triangle (integer)" << std::endl;
  int side, height;
  std::cin >> side;
  std::cin >> height;
  RightTriangle t{side, height};
  return t;
}

Rectangle CreateRectangle() {
  std::cout << "Enter the width and height of rectangle (integer)" << std::endl;
  int width, height;
  std::cin >> width;
  std::cin >> height;
  Rectangle r{width, height};
  return r;
}
