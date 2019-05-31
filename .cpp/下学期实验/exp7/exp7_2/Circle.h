#include"Shape.h"
#include<iostream>
using namespace std;

class Circle:public Shape
{
public:
    Circle(int radius = 10):radius(radius){}
    virtual ~Circle() override {}

    virtual void display() const override
    {
        cout << "This is a circle, radius = " << radius << ", area = " << area() <<  endl;
    }
    virtual double area() const override 
    {
        return 3.141 * radius * radius;
    }

    double getRadius() const 
    {
        return radius;
    }
    void setRadius(int radius)
    {
        this->radius = radius;
    }

protected:
    double radius;
};