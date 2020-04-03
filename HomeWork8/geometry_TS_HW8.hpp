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
  Coordinates() { pos = new sPoint{}; }
  Coordinates(const sPoint Pos) { pos = new sPoint{Pos}; }
  Coordinates(const double X, const double Y) { pos = new sPoint{X, Y}; }
  Coordinates(const Coordinates &Src) {
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
  virtual void setPos(sPoint Pos) final { *pos = Pos; };
  virtual ~Coordinates() { delete pos; };
  friend class Shape;

 protected:
  sPoint *pos;
};

class Point : public Coordinates {
 public:
  Point() : Coordinates(){};
  Point(sPoint Pos) : Coordinates(Pos){};
  Point(double X, double Y) : Coordinates(X, Y){};
  Point(Point &Src) : Coordinates(Src){};
  Point(Coordinates &Src) : Coordinates(Src){};
  virtual void draw() override {
    printf(k_point_printf, k_this_is_point, pos->x, pos->y);
  };
  virtual ~Point() override{};
};

class Shape : public Point {
 public:
  Shape() : Point() { size = new sPoint{}; };
  Shape(sPoint Pos, sPoint Size) : Point(Pos) { size = new sPoint{Size}; };
  Shape(double X1, double Y1, double X2, double Y2) : Point(X1, X2) {
    size = new sPoint{X2, Y2};
  };
  Shape(Shape &Src) : Point(Src) {
    size = new sPoint;
    size = Src.size;
  }
  Shape(Coordinates &Pos, Coordinates &Size) : Point(Pos) {
    size = new sPoint;
    size = Size.pos;
  };
  virtual void setHeihgt(double Height) final { size->y = Height; };
  virtual void setWidth(double Width) final { size->x = Width; };
  virtual void setSize(sPoint Size) final { *size = Size; };
  virtual double calc_square() = 0;
  virtual void draw() override{};
  virtual ~Shape() override { delete size; };

 protected:
  sPoint *size;
};

class Line : public Shape {
 public:
  Line() : Shape(){};
  Line(sPoint Pos, sPoint Size) : Shape(Pos, Size){};
  Line(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2){};
  Line(Shape &Src) : Shape(Src) {}
  Line(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size){};
  virtual double calc_square() override { return 0; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_line, pos->x, pos->y, pos->x + size->x,
           pos->y + size->y);
  }
  virtual ~Line() override{};
};

class Square : public Shape {
 public:
  Square() : Shape(){};
  Square(sPoint Pos, sPoint Size) : Shape(Pos, Size){};
  Square(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2){};
  Square(Shape &Src) : Shape(Src){};
  Square(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size){};
  virtual double calc_square() override { return size->x * size->x; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_square, pos->x, pos->y, pos->x + size->x,
           pos->y + size->x);
  }
  virtual ~Square() override{};
};

class Rectangle : public Shape {
 public:
  Rectangle() : Shape(){};
  Rectangle(sPoint Pos, sPoint Size) : Shape(Pos, Size){};
  Rectangle(double X1, double Y1, double X2, double Y2)
      : Shape(X1, Y1, X2, Y2){};
  Rectangle(Shape &Src) : Shape(Src) {}
  Rectangle(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size){};
  virtual double calc_square() override { return size->x * size->y; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_rectangle, pos->x, pos->y,
           pos->x + size->x, pos->y + size->y);
  }
  virtual ~Rectangle() override{};
};

class Triangle : public Shape {
 public:
  Triangle() : Shape(){};
  Triangle(sPoint Pos, sPoint Size) : Shape(Pos, Size){};
  Triangle(double X1, double Y1, double X2, double Y2)
      : Shape(X1, Y1, X2, Y2){};
  Triangle(Shape &Src) : Shape(Src) {}
  Triangle(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size){};
  virtual double calc_square() override { return (size->x * size->y) / 2; };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_triangle, pos->x, pos->y, pos->x + size->x,
           pos->y + size->y);
  }
  virtual ~Triangle() override{};
};

class Ellipse : public Shape {
 public:
  Ellipse() : Shape(){};
  Ellipse(sPoint Pos, sPoint Size) : Shape(Pos, Size){};
  Ellipse(double X1, double Y1, double X2, double Y2) : Shape(X1, Y1, X2, Y2){};
  Ellipse(Shape &Src) : Shape(Src) {}
  Ellipse(Coordinates &Pos, Coordinates &Size) : Shape(Pos, Size){};
  virtual double calc_square() override {
    return (size->x / 2) * (size->y / 2) * k_PI;
  };
  virtual void draw() override {
    printf(k_shape_printf, k_this_is_elipse, pos->x, pos->y, pos->x + size->x,
           pos->y + size->y);
  }
  virtual ~Ellipse() override{};
};