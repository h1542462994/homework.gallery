#include"Square.h"
#include<iostream>
using namespace std;

class Rectangle :public Square 
{
public:
    Rectangle(double length =10, double width = 10):Square(length),width(width){}
    virtual ~Rectangle() override {}

    virtual void display() const override
    {
        cout << "This is a rectangle, length = " << length << ", width = " << width << ", area = " << area() << endl ;
    }

    virtual double area() const override
    {
        return length * width;
    }

    double getWidth()
    {
        return width;
    }
    void setWidth(double width)
    {
        this->width = width;
    }

protected:
    double width;
};