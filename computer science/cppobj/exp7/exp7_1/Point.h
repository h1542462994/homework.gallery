#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
    Point(float x = 0, float y = 0);
    void setPoint(float, float);
    float getX() const { return x; }
    float getY() const { return y; }
    friend ostream& operator << (ostream&, const Point&);
protected:
    float x, y;
};