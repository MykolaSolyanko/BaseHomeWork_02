#include "geometry_TS_HW8.hpp"

static const double k_PI{3.14159265358979323846};
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

ICoordinates::ICoordinates() { pos = new sPoint{}; }
void ICoordinates::setTop(double Top) { pos->y = Top; };
void ICoordinates::setLeft(double Left) { pos->x = Left; };
void ICoordinates::setPos(double x, double y) {
  pos->x = x;
  pos->y = y;
};
void ICoordinates::setPos(sPoint Pos) { *pos = Pos; };
ICoordinates::~ICoordinates() { delete pos; };

Point ::Point(sPoint Pos) : Point(Pos.x, Pos.y){};
Point ::Point(double X, double Y) : Point() {
  pos->x = X;
  pos->y = Y;
};
void Point ::draw() {
  printf(k_point_printf, k_this_is_point, pos->x, pos->y);
};
Point ::~Point(){};

IShape::IShape() : Point() { size = new sPoint{}; };
IShape::IShape(sPoint Pos, sPoint Size)
    : IShape(Pos.x, Pos.y, Size.x, Size.y){};
IShape::IShape(double X1, double Y1, double X2, double Y2) : IShape() {
  pos->x = X1;
  pos->y = Y1;
  size->x = X2;
  size->y = Y2;
};
IShape::IShape(IShape &Src) : IShape() {
  pos = Src.pos;
  size = Src.size;
}
void IShape::setHeihgt(double Height) { size->y = Height; };
void IShape::setWidth(double Width) { size->x = Width; };
void IShape::setSize(sPoint Size) { *size = Size; };
IShape::~IShape() { delete size; };

Line::Line(sPoint Pos, sPoint Size) : IShape(Pos, Size){};
Line::Line(double X1, double Y1, double X2, double Y2)
    : IShape(X1, Y1, X2, Y2){};
Line::Line(IShape &Src) : IShape(Src) {}
double Line::calc_square() { return 0; };
void Line::draw() {
  printf(k_shape_printf, k_this_is_line, pos->x, pos->y, pos->x + size->x,
         pos->y + size->y);
}
Line::~Line(){};

Square::Square(sPoint Pos, sPoint Size) : IShape(Pos, Size){};
Square::Square(double X1, double Y1, double X2, double Y2)
    : IShape(X1, Y1, X2, Y2){};
Square::Square(IShape &Src) : IShape(Src){};
double Square::calc_square() { return size->x * size->x; };
void Square::draw() {
  printf(k_shape_printf, k_this_is_square, pos->x, pos->y, pos->x + size->x,
         pos->y + size->x);
}
Square::~Square(){};

Rectangle::Rectangle(sPoint Pos, sPoint Size) : IShape(Pos, Size){};
Rectangle::Rectangle(double X1, double Y1, double X2, double Y2)
    : IShape(X1, Y1, X2, Y2){};
Rectangle::Rectangle(IShape &Src) : IShape(Src) {}
double Rectangle::calc_square() { return size->x * size->y; };
void Rectangle::draw() {
  printf(k_shape_printf, k_this_is_rectangle, pos->x, pos->y, pos->x + size->x,
         pos->y + size->y);
}
Rectangle::~Rectangle(){};

Triangle::Triangle(sPoint Pos, sPoint Size) : IShape(Pos, Size){};
Triangle::Triangle(double X1, double Y1, double X2, double Y2)
    : IShape(X1, Y1, X2, Y2){};
Triangle::Triangle(IShape &Src) : IShape(Src) {}
double Triangle::calc_square() {
  // for rectangular triangle
  return (size->x * size->y) / 2;
};
void Triangle::draw() {
  printf(k_shape_printf, k_this_is_triangle, pos->x, pos->y, pos->x + size->x,
         pos->y + size->y);
}
Triangle::~Triangle(){};

Ellipse::Ellipse(sPoint Pos, sPoint Size) : IShape(Pos, Size){};
Ellipse::Ellipse(double X1, double Y1, double X2, double Y2)
    : IShape(X1, Y1, X2, Y2){};
Ellipse::Ellipse(IShape &Src) : IShape(Src) {}
double Ellipse::calc_square() { return (size->x / 2) * (size->y / 2) * k_PI; };
void Ellipse::draw() {
  printf(k_shape_printf, k_this_is_elipse, pos->x, pos->y, pos->x + size->x,
         pos->y + size->y);
}
Ellipse::~Ellipse(){};