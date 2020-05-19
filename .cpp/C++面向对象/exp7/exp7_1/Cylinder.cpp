#include"Cylinder.h"

Cylinder::Cylinder(float x,float y, float r,float h):Circle(x,y,r),height(h)
{

}

void Cylinder::setHeight(float h)
{
    height = h;
}

float Cylinder::getHeight() const
{
    return height;
}

float Cylinder::area() const
{
    return 2 * Circle::area() + 2 * 3.14159 * radius * height;
}
float Cylinder::volume() const
{
    return Circle::area() * height;
}

ostream& operator << (ostream& output,const Cylinder& cy)
{
    output << "Center = [" << cy.x << "," << cy.y << "],r = " << cy.radius << ",h = " << cy.height << endl << "area = " << cy.area() << "volume = " << cy.volume() << endl;
    return output;
}