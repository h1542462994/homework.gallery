#include <iostream>
#include <queue>
#include <cmath>
#include "point_d.h"
#include "div_iter.h"
#include "tools.h"
#include "simple_iter.h"

double f(double x){
    return exp(x) + 10.0 * x - 2.0;
}

double g(double x){
    return (2.0 - exp(x)) / 10.0;
}

using namespace std;
int main() {
    div_iter iter = div_iter(0,1,0.0005,f);
    iter.solve();
    //tools::print_a(iter.results);
    tools::print_script(iter.results);

    simple_iter iter1 = simple_iter(0, exp(1)/ 10.0, 0.0005, g);
    iter1.solve();
    //tools::print_a(iter1.results);
    tools::print_script(iter1.results);

    return 0;
}

