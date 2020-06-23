#include"Shape.h"
#include<iostream>
#include<cmath>
using namespace std;

class Triangle:public Shape
{
public:
    Triangle(double a = 10,double b = 10,double c = 10):a(a),b(b),c(c)
    {

    }
    virtual ~Triangle() override {}

    virtual void display() const override
    {
        cout << "This is a Triangle, a = " << a << ", b = " << b << ", c = " << c << ", area = " << area() << endl;
    }
    virtual double area() const override 
    {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double getA()
    {
        return a;
    }
    void setA(double value)
    {
        a = value;
    }
    double getB()
    {
        return b;
    }
    void setB(double value)
    {
        b = value;
    }
    double getC()
    {
        return c;
    }
    void setC(double value)
    {
        c = value;
    }


protected:
    double a, b, c;
};