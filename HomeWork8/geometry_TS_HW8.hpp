#include <iostream>
struct sPoint {
  double x{};
  double y{};
};
class ICoordinates {
 public:
  ICoordinates();
  virtual void draw() = 0;
  virtual void setTop(double Top) final;
  virtual void setLeft(double Left) final;
  virtual void setPos(double x, double y) final;
  virtual void setPos(sPoint Pos) final;
  virtual ~ICoordinates();

 protected:
  sPoint *pos;
};

class Point : public ICoordinates {
 public:
  Point() = default;
  Point(sPoint Pos);
  Point(double X, double Y);
  virtual void draw() override;
  virtual ~Point();
};

class IShape : public Point {
 public:
  IShape();
  IShape(sPoint Pos, sPoint Size);
  IShape(double X1, double Y1, double X2, double Y2);
  IShape(IShape &Src);
  virtual void setHeihgt(double Height) final;
  virtual void setWidth(double Width) final;
  virtual void setSize(sPoint Size) final;
  virtual double calc_square() = 0;
  virtual ~IShape() override;

 protected:
  sPoint *size;
};

class Line : public IShape {
 public:
  Line() = default;
  Line(sPoint Pos, sPoint Size);
  Line(double X1, double Y1, double X2, double Y2);
  Line(IShape &Src);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Line() override;
};

class Square : public IShape {
 public:
  Square() = default;
  Square(sPoint Pos, sPoint Size);
  Square(double X1, double Y1, double X2, double Y2);
  Square(IShape &Src);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Square() override;
};

class Rectangle : public IShape {
 public:
  Rectangle() = default;
  Rectangle(sPoint Pos, sPoint Size);
  Rectangle(double X1, double Y1, double X2, double Y2);
  Rectangle(IShape &Src);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Rectangle() override;
};

// for rectangular triangle
class Triangle : public IShape {
 public:
  Triangle() = default;
  Triangle(sPoint Pos, sPoint Size);
  Triangle(double X1, double Y1, double X2, double Y2);
  Triangle(IShape &Src);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Triangle() override;
};

class Ellipse : public IShape {
 public:
  Ellipse() = default;
  Ellipse(sPoint Pos, sPoint Size);
  Ellipse(double X1, double Y1, double X2, double Y2);
  Ellipse(IShape &Src);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Ellipse() override;
};