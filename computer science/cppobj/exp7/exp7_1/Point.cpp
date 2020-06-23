#include"Point.h"

//下面是定义Point类的成员函数
//Point 的构造函数	
Point::Point(float a, float b) {
    x = a;
    y = b;
}

//设置 x 和 y 的坐标值
void Point::setPoint(float a,float b)
{
    x = a;
    y = b;
}

ostream& operator << (ostream& output,const Point& p)
{
    output << "[" << p.x << "," << p.y << "]" << endl;
    return output;
}