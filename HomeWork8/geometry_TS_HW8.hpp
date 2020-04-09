#include <iostream>

class ICoordinates {
 public:
  virtual void setTop(double Top) = 0;
  virtual void setLeft(double Left) = 0;
  virtual void setPos(double Left, double Top) = 0;
  virtual ~ICoordinates() = default;
};

class Point : public virtual ICoordinates {
 public:
  Point() = default;
  Point(double Left, double Top);
  void setTop(double Top) final;
  void setLeft(double Left) final;
  void setPos(double Left, double Top) final;
  virtual void draw();
  virtual ~Point() = default;

 protected:
  double left{};
  double top{};
};

class IShape : public virtual ICoordinates {
 public:
  virtual void setHeihgt(double Height) = 0;
  virtual void setWidth(double Width) = 0;
  virtual void setSize(double Width, double Height) = 0;
  virtual ~IShape() = default;
};
/*  */
class Shape : public IShape, public Point {
 public:
  void setHeihgt(double Height) final;
  void setWidth(double Width) final;
  void setSize(double Width, double Height) final;
  virtual double calc_square() = 0;
  ~Shape() = default;

 protected:
  double width{};
  double heght{};
};

class Line : public Shape {
 public:
  Line() = default;
  Line(double Left, double Top, double Width, double Height);
  double calc_square() override;
  void draw() override;
  virtual ~Line() = default;
};

class Square : public Shape {
 public:
  Square() = default;
  Square(double Left, double Top, double Width, double Height /*ignoring*/);
  double calc_square() override;
  void draw() override;
  virtual ~Square() = default;
};

class Rectangle : public Shape {
 public:
  Rectangle() = default;
  Rectangle(double Left, double Top, double Width, double Height);
  double calc_square() override;
  void draw() override;
  virtual ~Rectangle() = default;
};

// for rectangular triangle
class Triangle : public Shape {
 public:
  Triangle() = default;
  Triangle(double Left, double Top, double Width, double Height);
  double calc_square() override;
  void draw() override;
  virtual ~Triangle() = default;
};

class Ellipse : public Shape {
 public:
  Ellipse() = default;
  Ellipse(double Left, double Top, double Width, double Height);
  double calc_square() override;
  void draw() override;
  virtual ~Ellipse() = default;
};