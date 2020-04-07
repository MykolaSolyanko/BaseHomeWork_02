#include "geometry_TS_HW8.hpp"
void FamilyTree() {
  std::cout << R"(

Inheritance of classes

 >ICoordinates
    +--Point
        +->IShape
            +--Line
            +--Square
            +--Rectangle
            +--Triangle
            +--Ellipse

  )" << std::endl;
};
int main(int argc, char const *argv[]) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  FamilyTree();
  sPoint point{22, 66};
  // ICoordinates Decard;  // here mast be error
  std::cout << "This is point" << std::endl;

  std::cout << "Point defPoint;" << std::endl;
  Point defPoint;
  defPoint.setLeft(22);
  defPoint.setTop(120);
  defPoint.draw();

  std::cout << "Point pointPoint(S);" << std::endl;
  Point pointPoint(point);
  pointPoint.draw();

  std::cout << "Point pointPoint(X,Y);" << std::endl;
  Point XYPoint(230, 586);
  XYPoint.draw();

  std::cout << "Point pointPoint(O);" << std::endl;
  Point CopyPoint(defPoint);
  CopyPoint.draw();

  std::cout << "Point don`t have calc_square()" << std::endl;

  // IShape s(45, 54);  // here mast be error

  std::cout << "This is line" << std::endl;
  Line defLine;
  defLine.setPos(point);
  defLine.setSize(point);
  defLine.draw();
  std::cout << "squre=" << defLine.calc_square() << std::endl;

  {
    std::cout << "This is rectangle" << std::endl;
    Rectangle RecPoint(point, sPoint{22, 16});
    RecPoint.draw();
    std::cout << "squre=" << RecPoint.calc_square() << std::endl;
  }

  {
    std::cout << "This is square" << std::endl;
    Square squareParm(22, 66, 88, 21);
    squareParm.draw();
    std::cout << "squre=" << squareParm.calc_square() << std::endl;
  }
  {
    std::cout << "This is triangle" << std::endl;
    Triangle CopyTriangle(defLine);
    CopyTriangle.draw();
    std::cout << "squre=" << CopyTriangle.calc_square() << std::endl;
  }
  {
    std::cout << "This is elipse" << std::endl;
    Ellipse el(33, 25, 89.3, 98.2);
    el.draw();
    std::cout << "squre=" << el.calc_square() << std::endl;
  }
  return 0;
}
