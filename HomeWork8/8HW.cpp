#include <iostream>
#include <cmath>
#include <stdio.h>

class Shape{
  public:  
    virtual void draw()const{
        std::cout<<"Base class"<<std::endl;
    }
    virtual double calc_square(){
        return 0;
    }
};

class Square : public Shape{
  public:
    Square();
    Square(double a):aSide{a}{};
    void draw()const{
        //std::cout<<"SQUARE"<<std::endl;
        for(size_t i=0;i<round(aSide);i++){
            std::cout<<" ";
            for(size_t j=0;j<round(aSide);j++)   
                std::cout<<"= ";
            std::cout<<std::endl;
        }
    }
    double calc_square(){//enter a side
        return pow(aSide, 2);
    }
    void changeparametrs(double a){
        aSide=a;
    }
  private:
    double aSide;
};

class Triangle : public Shape{
  public:
    Triangle();
    Triangle(double a, double h):aBase{a},heigh{h}{};
    void draw(){
        double Base=aBase*2;
        for (int y = 0; y < Base; y += 2) {
            for (int x = 0; x < Base; x++) {
                printf((x * 2 <= Base && (Base - y) / 2 <= x) || (x * 2 >= Base && y >= x * 2 - Base) ? "*" : " ");
            }
        printf("\n");  
        }
    }
    double calc_square(){//enter triangle base and heigh 
        return (aBase*heigh)/2;
    }
    void changeparametrs(double a, double h){
        aBase=a;
        heigh=h;
    }
  private:
    double aBase, heigh;
};

class Rectangle : public Shape{
  public:
    Rectangle();
    Rectangle(double a, double b):aSide{a},bSide{b}{};
    void draw()const{
        //std::cout<<"RECTANGLE"<<std::endl;
        for(size_t i=0;i<round(aSide);i++){
            std::cout<<" ";
            for(size_t j=0;j<round(bSide);j++)   
                std::cout<<"= ";
            std::cout<<std::endl;
        }
    }
    double calc_square(){//enter a and b side
        return aSide*bSide;
    }
    void changeparametrs(double a, double b){
        aSide=a;
        bSide=b;
    }
    double aSide, bSide;
};

int main(int argc, char const *argv[]){
    Square sqr(10.2);
    std::cout<<sqr.calc_square()<<std::endl;
    sqr.draw();
    sqr.changeparametrs(5.1);
    std::cout<<sqr.calc_square()<<std::endl;
    sqr.draw();
    std::cout<<std::endl;

    Triangle trg(7.3, 10);
    std::cout<<trg.calc_square()<<std::endl;
    trg.draw();
    trg.changeparametrs(4.6, 5);
    std::cout<<trg.calc_square()<<std::endl;
    trg.draw();
    std::cout<<std::endl;

    Rectangle rct(5.3, 7.8);
    std::cout<<rct.calc_square()<<std::endl;
    rct.draw();
    rct.changeparametrs(2.6, 3.9);
    std::cout<<rct.calc_square()<<std::endl;
    rct.draw();
    std::cout<<std::endl;
}