//
// Created by t1542 on 2020/3/6.
//
#include <iostream>
#include <vector>
#include "point_d.h"
#include "pd.h"

using namespace std;


class div_iter {
public:
    explicit div_iter(double left = 0, double right = 1, double precision = 0.0005, func_d f = nullptr):
        left(left), right(right), precision(precision),f(f) {
        left_val = f(left);
        right_val = f(right);
    }

    void solve();
    vector<point_d> results;
private:
    func_d f;

    double precision;
    double left;
    double right;
    double left_val;
    double right_val;
};
