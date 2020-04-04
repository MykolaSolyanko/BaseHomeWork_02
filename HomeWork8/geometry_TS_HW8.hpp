#include <iostream>
struct sPoint {
  double x{};
  double y{};
};
class ICoordinates {
 public:
  ICoordinates();
  ICoordinates(const sPoint Pos);
  ICoordinates(const double X, const double Y);
  ICoordinates(const ICoordinates &Src);
  virtual void draw() = 0;
  virtual void setTop(double Top) final;
  virtual void setLeft(double Left) final;
  virtual void setPos(double x, double y) final;
  virtual void setPos(sPoint Pos) final;
  virtual ~ICoordinates();
  friend class IShape;

 protected:
  sPoint *pos;
};

class Point : public ICoordinates {
 public:
  Point();
  Point(sPoint Pos);
  Point(double X, double Y);
  Point(Point &Src);
  Point(ICoordinates &Src);
  virtual void draw() override;
  virtual ~Point();
};

class IShape : public Point {
 public:
  IShape();
  IShape(sPoint Pos, sPoint Size);
  IShape(double X1, double Y1, double X2, double Y2);
  IShape(IShape &Src);
  IShape(ICoordinates &Pos, ICoordinates &Size);
  virtual void setHeihgt(double Height) final;
  virtual void setWidth(double Width) final;
  virtual void setSize(sPoint Size) final;
  virtual double calc_square() = 0;
  virtual void draw() override;
  virtual ~IShape() override;

 protected:
  sPoint *size;
};

class Line : public IShape {
 public:
  Line();
  Line(sPoint Pos, sPoint Size);
  Line(double X1, double Y1, double X2, double Y2);
  Line(IShape &Src);
  Line(ICoordinates &Pos, ICoordinates &Size);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Line() override;
};

class Square : public IShape {
 public:
  Square();
  Square(sPoint Pos, sPoint Size);
  Square(double X1, double Y1, double X2, double Y2);
  Square(IShape &Src);
  Square(ICoordinates &Pos, ICoordinates &Size);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Square() override;
};

class Rectangle : public IShape {
 public:
  Rectangle();
  Rectangle(sPoint Pos, sPoint Size);
  Rectangle(double X1, double Y1, double X2, double Y2);
  Rectangle(IShape &Src);
  Rectangle(ICoordinates &Pos, ICoordinates &Size);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Rectangle() override;
};

class Triangle : public IShape {
 public:
  Triangle();
  Triangle(sPoint Pos, sPoint Size);
  Triangle(double X1, double Y1, double X2, double Y2);
  Triangle(IShape &Src);
  Triangle(ICoordinates &Pos, ICoordinates &Size);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Triangle() override;
};

class Ellipse : public IShape {
 public:
  Ellipse();
  Ellipse(sPoint Pos, sPoint Size);
  Ellipse(double X1, double Y1, double X2, double Y2);
  Ellipse(IShape &Src);
  Ellipse(ICoordinates &Pos, ICoordinates &Size);
  virtual double calc_square() override;
  virtual void draw() override;
  virtual ~Ellipse() override;
};