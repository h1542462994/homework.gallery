//
// Created by t1542 on 2020/3/6.
//
#pragma once
#include <iostream>
#include <vector>
#include "point_d.h"
#include "pd.h"

using namespace std;

class simple_iter {
public:
    simple_iter(double start, double l, double precision, func_d f):
        c(start), l(l), precision(precision), f(f) {
    }

    void solve();
    vector<point_d> results;
private:

    double c;
    double l;
    double precision;
    func_d f;

};

