//
// Created by t1542 on 2020/3/6.
//

#include "simple_iter.h"

void simple_iter::solve() {
    while(true){
        double _sen = f(c);
        results.emplace_back(c, 0);
        if(l / (1-l) * abs(c - _sen) <= precision){
            break;
        }
        c = _sen;
    }
}
