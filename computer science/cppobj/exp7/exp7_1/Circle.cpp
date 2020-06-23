#include"Circle.h"

Circle::Circle(float a,float b,float r):Point(a,b),radius(r)
{

}
void Circle::setRadius(float r)
{
    radius = r;
}
float Circle::getRadius() const
{
    return radius;
}
float Circle::area() const
{
    return 3.14159 * radius * radius;
}
ostream& operator << (ostream& output, const Circle& c)
{
    output << "Center = [" << c.x << "," << c.y << "],r = " << c.radius << ",area = " << c.area() << endl;
    return output;
}
