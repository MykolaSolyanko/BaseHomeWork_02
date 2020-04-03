#include <iostream>
struct sPoint {
  double x{};
  double y{};
};

static const unsigned k_sh{255};
static const double k_PI{3.14};
// printf
static const char k_point_printf[]{"Draw \n%s\n x=%f;y=%f\n"};
static const char k_shape_printf[]{"Draw \n%s\n x1=%f;y1=%f to x2=%f y2=%f\n"};

// SHAPES
//  .
static const char k_this_is_point[]{"\n.\n"};
//  -----------
static const char k_this_is_line[]{"\n-----------\n"};
/*
 -------
|       |
|       |
 -------
*/
static const char k_this_is_square[]{
    "\n ------- \n|       |\n|       |\n -------\n"};
/*
-------
|       |
|       |
|       |
|       |
|       |
 -------
*/
static const char k_this_is_rectangle[]{
    "\n ------- \n|       |\n|       |\n|       |\n|       |\n|       |\n "
    "-------\n"};
/*
|\
| \
|  \
|   \
|____\
*/
static const char k_this_is_triangle[]{"\n|\\\n| \\\n|  \\\n|   \\\n|____\\\n"};
/*
   ______
  /      \
 (        )
  \______/
*/
static const char k_this_is_elipse[]{
    "\n  ______\n /      \\\n(        )\n \\______/\n"};

class Coordinates {
 public:
  Coordinates() {
    pos = new sPoint{};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Coordinates(const sPoint Pos) {
    pos = new sPoint{Pos};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Coordinates(const double X, const double Y) {
    pos = new sPoint{X, Y};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Coordinates(const Coordinates &Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    pos = new sPoint;
    pos = Src.pos;
  }
  virtual void draw() = 0;
  virtual void setTop(double Top) final { pos->y = Top; };
  virtual void setLeft(double Left) final { pos->x = Left; };
  virtual void setPos(double x, double y) final {
    pos->x = x;
    pos->y = y;
  };
  virtual void setPosition(sPoint Pos) final { *pos = Pos; };
  virtual ~Coordinates() {
    delete pos;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  friend class Shape;

 protected:
  sPoint *pos;
};

class Point : public Coordinates {
 public:
  Point() : Coordinates() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
  Point(sPoint Pos) : Coordinates(Pos) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Point(double X, double Y) : Coordinates(X, Y) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Point(Point &Src) : Coordinates(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Point(Coordinates &Src) : Coordinates(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual void draw() override {
    printf(k_point_printf, k_this_is_point, pos->x, pos->y);
  };
  virtual ~Point() override { std::cout << __PRETTY_FUNCTION__ << std::endl; };
};

class Shape : public Point {
 public:
  Shape() : Point() {
    size = new sPoint{};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Shape(sPoint Pos, sPoint Size) : Point(Pos) {
    size = new sPoint{Size};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Shape(double X1, double Y1, double X2, double Y2) : Point(X1, X2) {
    size = new sPoint{X2, Y2};
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Shape(Shape &Src) : Point(Src) {
    size = new sPoint;
    size = Src.size;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Shape(Coordinates &Pos, Coordinates &Size) : Point(Pos) {
    size = new sPoint;
    size = Size.pos;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual void setHeihgt(double Height) final { size->y = Height; };
  virtual void setWidth(double Width) final { size->x = Width; };
  virtual void setSize(sPoint Size) final { *size = Size; };
  virtual double calc_square() = 0;
  virtual void draw() override{};
  virtual ~Shape() override {
    delete size;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };

 protected:
  sPoint *size;
};

class Line : public Shape {
 public:
  Line() : Shape() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
  Line(sPoint Pos, sPoint Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Line(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Line(Shape &Src) : Shape(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Line(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual double calc_square() override { return 0; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_line, pos->x, pos->y, pos->x + size->x,
           pos->y + size->y);
  }
  virtual ~Line() override { std::cout << __PRETTY_FUNCTION__ << std::endl; };
};

class Square : public Shape {
 public:
  Square() : Shape() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
  Square(sPoint Pos, sPoint Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Square(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Square(Shape &Src) : Shape(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Square(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual double calc_square() override { return size->x * size->x; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_square, pos->x, pos->y, pos->x + size->x,
           pos->y + size->x);
  }

  virtual ~Square() override { std::cout << __PRETTY_FUNCTION__ << std::endl; };
};

class Rectangle : public Shape {
 public:
  Rectangle() : Shape() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
  Rectangle(sPoint Pos, sPoint Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Rectangle(double X1, double Y1, double X2, double Y2)
      : Shape(X1, Y1, X2, Y2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Rectangle(Shape &Src) : Shape(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Rectangle(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual double calc_square() override { return size->x * size->y; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_rectangle, pos->x, pos->y,
           pos->x + size->x, pos->y + size->y);
  }
  virtual ~Rectangle() override{};
};

class Triangle : public Shape {
 public:
  Triangle() : Shape() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
  Triangle(sPoint Pos, sPoint Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Triangle(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Triangle(Shape &Src) : Shape(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Triangle(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual double calc_square() override { return (size->x * size->y) / 2; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_triangle, pos->x, pos->y, pos->x + size->x,
           pos->y + size->y);
  }
  virtual ~Triangle() override {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
};

class Ellipse : public Shape {
 public:
  Ellipse() : Shape() { std::cout << __PRETTY_FUNCTION__ << std::endl; };
  Ellipse(sPoint Pos, sPoint Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Ellipse(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  Ellipse(Shape &Src) : Shape(Src) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }
  Ellipse(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
  virtual double calc_square() override {
    return (size->x / 2) * (size->y / 2) * k_PI;
  };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_elipse, pos->x, pos->y, pos->x + size->x,
           pos->y + size->y);
  }
  virtual ~Ellipse() override {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  };
};