#include"Shape.h"
#include"Circle.h"
#include"Square.h"
#include"Rectangle.h"
#include"Trapezoid.h"
#include"Traingle.h"
#include<iostream>
#include<vcruntime.h>

using namespace std;

int main()
{
    double area = 0;
    Shape* pShape = NULL;

    pShape = new Circle(7);
    pShape->display();
    area += pShape->area();

    pShape = new Square(8.2);
    pShape->display();
    area += pShape->area();

    pShape = new Rectangle(4, 8.5);
    pShape->display();
    area += pShape->area();

    pShape = new Trapezoid(7, 18.4, 6);
    pShape->display();
    area += pShape->area();

    pShape = new Triangle(6, 8, 10);
    pShape->display();
    area += pShape->area();

    cout << "The total area is " << area << endl;

    return 0;
}