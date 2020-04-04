#pragma once

class Shape {
public:
  Shape() { std::cout << __FUNCSIG__ << std::endl; };
  virtual ~Shape() { std::cout << __FUNCSIG__ << std::endl; };
  virtual void draw() = 0;
  virtual int calc_square() = 0;

private:
};

class Square : public Shape {
public:
  Square() : Square(1) { std::cout << __FUNCSIG__ << std::endl; };
  Square(int a) : side{a} { std::cout << __FUNCSIG__ << std::endl; };
  virtual ~Square() { std::cout << __FUNCSIG__ << std::endl; };
  ;
  void draw() override;
  int calc_square() override;
  int get_side();
  void set_side(int side);

private:
  int side;
};

class RightTriangle : public Shape {
public:
  RightTriangle() : RightTriangle(1, 1) {
    std::cout << __FUNCSIG__ << std::endl;
  };
  RightTriangle(int a, int h) : side{a}, height{h} {
    std::cout << __FUNCSIG__ << std::endl;
  };
  virtual ~RightTriangle() { std::cout << __FUNCSIG__ << std::endl; };
  ;
  void draw() override;
  int calc_square() override;
  int get_side();
  int get_height();
  void set_side(int side);
  void set_height(int height);

private:
  int side;
  int height;
};

class Rectangle : public Shape {
public:
  Rectangle() : Rectangle(1, 1) { std::cout << __FUNCSIG__ << std::endl; };
  Rectangle(int a, int h) : width{a}, height{h} {
    std::cout << __FUNCSIG__ << std::endl;
  };
  virtual ~Rectangle() { std::cout << __FUNCSIG__ << std::endl; };
  ;
  void draw() override;
  int calc_square() override;
  int get_width();
  int get_height();
  void set_width(int width);
  void set_height(int height);

private:
  int width;
  int height;
};

Square CreateSquare();
RightTriangle CreateTriangle();
Rectangle CreateRectangle();
