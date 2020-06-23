//
// Created by t1542 on 2020/3/6.
//
#pragma once
#include <iostream>
using namespace std;

class point_d {
public:
    point_d(double x, double y): x(x), y(y) {}
    double x;
    double y;
    friend ostream& operator << (ostream& o, const point_d& p);
};

