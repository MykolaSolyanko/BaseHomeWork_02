#include "geometry_TS_HW8.hpp"

// printf
static const char k_shape_printf[]{"Draw \n%s\n x1=%f;y1=%f to x2=%f y2=%f\n"};
/*Point*/
Point ::Point(double Left, double Top) : left{Left}, top{Top} {};
void Point::setTop(double Top) { top = Top; };
void Point::setLeft(double Left) { left = Left; };
void Point::setPos(double Left, double Top) {
  setTop(Left);
  setLeft(Top);
};
void Point ::draw() {
  // .
  const char k_point_printf[]{"Draw \n%s\n x=%f;y=%f\n"};
  const char k_this_is_point[]{"\n.\n"};
  printf(k_point_printf, k_this_is_point, left, top);
};

/*Shape*/
void Shape::setHeihgt(double Height) { heght = Height; };
void Shape::setWidth(double Width) { width = Width; };
void Shape::setSize(double Width, double Height) {
  setWidth(Width);
  setHeihgt(Height);
};
/*Line*/
Line::Line(double Left, double Top, double Width, double Height) : Line() {
  setPos(Left, Top);
  setSize(Width, Height);
}
double Line::calc_square() { return 0; };
void Line::draw() {
  //  -----------
  const char k_this_is_line[]{"\n-----------\n"};
  printf(k_shape_printf, k_this_is_line, left, top, left + width, top + heght);
}
/*Squre*/
Square::Square(double Left, double Top, double Width,
               double Height /*this valus is ignoring*/)
    : Square() {
  setPos(Left, Top);
  setSize(Width, 0 /*this valus is ignoring*/);
};
double Square::calc_square() { return width * width; };
void Square::draw() {
  /*
   -------
  |       |
  |       |
   -------
  */
  const char k_this_is_square[]{
      "\n ------- \n|       |\n|       |\n -------\n"};
  printf(k_shape_printf, k_this_is_square, left, top, left + width,
         top + width);
}
/* Rectangle */
Rectangle::Rectangle(double Left, double Top, double Width, double Height)
    : Rectangle() {
  setPos(Left, Top);
  setSize(Width, Height);
};
double Rectangle::calc_square() { return heght * width; };
void Rectangle::draw() {
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
  printf(k_shape_printf, k_this_is_rectangle, left, top, left + width,
         top + heght);
}
/*rectangular Triangle*/
Triangle::Triangle(double Left, double Top, double Width, double Height)
    : Triangle() {
  setPos(Left, Top);
  setSize(Width, Height);
};
double Triangle::calc_square() { return (heght * width) / 2; };
void Triangle::draw() {
  /*
  |\
  | \
  |  \
  |   \
  |____\
  */
  const char k_this_is_triangle[]{"\n|\\\n| \\\n|  \\\n|   \\\n|____\\\n"};
  printf(k_shape_printf, k_this_is_triangle, left, top, left + width,
         top + heght);
}
/*Ellipse*/
Ellipse::Ellipse(double Left, double Top, double Width, double Height)
    : Ellipse() {
  setPos(Left, Top);
  setSize(Width, Height);
};
double Ellipse::calc_square() {
  const double k_PI{3.14159265358979323846};
  return (width / 2) * (heght / 2) * k_PI;
};
void Ellipse::draw() {
  /*
     ______
    /      \
   (        )
    \______/
  */
  const char k_this_is_elipse[]{
      "\n  ______\n /      \\\n(        )\n \\______/\n"};
  printf(k_shape_printf, k_this_is_elipse, left, top, left + width,
         top + heght);
}