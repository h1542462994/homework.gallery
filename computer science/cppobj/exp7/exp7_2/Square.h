#include"Shape.h"
#include<iostream>
using namespace std;

class Square:public Shape
{
public:
    virtual ~Square() override {}
    Square(double length = 10):length(length){}

    virtual void display() const override
    {
        cout << "This is a square, length = "  << length << ", area = " << area() << endl;
    }

    virtual double area() const override
    {
        return length * length;
    }

    double getLength() const
    {
        return length;
    }
    void setLength(double length)
    {
        this->length = length;
    }

protected:
    double length;
};