#pragma once

class Shape {
public:
  Shape() { std::cout << __FUNCSIG__ << std::endl; };
  virtual ~Shape() { std::cout << __FUNCSIG__ << std::endl; };
  virtual const void draw() = 0;
  virtual double calc_square() = 0;

private:
};

class Square : public Shape {
public:
  Square() = default;
  Square(int a) : side{a} { std::cout << __FUNCSIG__ << std::endl; };
  virtual ~Square() { std::cout << __FUNCSIG__ << std::endl; };
  ;
  const void draw() override;
  double calc_square() override;
  const int get_side();
  void set_side(int side);

private:
  int side{1};
};

class RightTriangle : public Shape {
public:
  RightTriangle() = default;
  RightTriangle(int a, int h) : side{a}, height{h} {
    std::cout << __FUNCSIG__ << std::endl;
  };
  virtual ~RightTriangle() { std::cout << __FUNCSIG__ << std::endl; };
  ;
  const void draw() override;
  double calc_square() override;
  const int get_side();
  const int get_height();
  void set_side(int side);
  void set_height(int height);

private:
  int side{1};
  int height{1};
};

class Rectangle : public Shape {
public:
  Rectangle() = default;
  Rectangle(int a, int h) : width{a}, height{h} {
    std::cout << __FUNCSIG__ << std::endl;
  };
  virtual ~Rectangle() { std::cout << __FUNCSIG__ << std::endl; };
  ;
  const void draw() override;
  double calc_square() override;
  const int get_width();
  const int get_height();
  void set_width(int width);
  void set_height(int height);

private:
  int width{1};
  int height{1};
};

Square CreateSquare();
RightTriangle CreateTriangle();
Rectangle CreateRectangle();
