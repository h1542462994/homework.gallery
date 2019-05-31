#include<iostream>
#include"Point.h"
#include"Circle.h"
#include"Cylinder.h"
using namespace std;

int main()
{
    Point p(3.5, 6.4);
    cout << "x = " << p.getX() << ",y = " << p.getY() << endl;
    p.setPoint(8.5, 6.8);
    cout << "p(new):" << p << endl;

    Circle c(3.5, 6.4, 5.2);
    cout << "original circle:" << endl << "x = " << c.getX() << ",y = " << c.getY() << ",r = " << c.getRadius() << ",area = " << c.area() << endl;
    c.setRadius(7.5);
    c.setPoint(5,5);
    cout << "new circle:" << endl << c;
    Point& pRef = c;
    cout << "pRef:" << pRef;

    Cylinder cy1(3.5, 6.4, 5.2, 10);
    cout << "original cylinder:" << endl << cy1.getX() << ",y = " << cy1.getY() << ",r = " << cy1.getRadius() << ",h = " << cy1.getHeight() << endl << "area = " << cy1.area() << ",volume = " << cy1.volume() << endl;
    cy1.setHeight(15);
    cy1.setRadius(7.5);
    cy1.setPoint(5, 5);
    cout << endl << "new cylinder:" << endl << cy1;
    Point& pRef1 = cy1;
    cout << endl << "pRef as a point:" << pRef1;
    Circle& cRef = cy1;
    cout << endl << "cRef as a Circle:" << cRef;

    return 0;
}