#include"Shape.h"
#include<iostream>
using namespace std;

class Trapezoid:public Shape
{
public:
    Trapezoid(double topLength = 10,double bottomLength = 20,double height = 5) :topLength(topLength),bottomLength(bottomLength),height(height){}
    virtual ~Trapezoid() override {}

    virtual void display() const override
    {
        cout << "This is a Trapezoid, topLength = " << topLength << ", bottomLength = " << bottomLength << ", height = " << height << ", area = " << area() << endl;
    }
    virtual double area() const override
    {
        return 0.5 * (topLength + bottomLength) * height;
    }

    double getTopLength()
    {
        return topLength;
    }
    void setTopLength(double topLength)
    {
        this->topLength = topLength;
    }
    double getBottomLength()
    {
        return bottomLength;
    }
    void setBottomLength()
    {
        this->bottomLength = bottomLength;
    }
    double getHeight()
    {
        return height;
    }
    void setHeight(double height)
    {
        this->height = height;
    }

protected:
    double topLength;
    double bottomLength;
    double height;
};