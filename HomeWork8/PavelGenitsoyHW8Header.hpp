#pragma once

class IShape {
public:
  virtual void draw() = 0;
  virtual double calc_square() = 0;
};

class Square : public IShape {
public:
  Square() = default;
  Square(size_t a) : side{a} {};
  void draw() override;
  double calc_square() override;

private:
  size_t side{0};
};

class Triangle : public IShape {
public:
  Triangle() = default;
  Triangle(size_t a, size_t b) : side{a}, height{b} {};
  void draw() override;
  double calc_square() override;

private:
  size_t side{0};
  size_t height{0};
};

class Rectangle : public IShape {
public:
  Rectangle() = default;
  Rectangle(size_t a, size_t b) : smaller_side{a}, bigger_side{b} {};
  void draw() override;
  double calc_square() override;

private:
  size_t smaller_side{0};
  size_t bigger_side{0};
};
