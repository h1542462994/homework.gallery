//
// Created by t1542 on 2020/3/16.
//

#pragma once
#include "ubigint.h"

ubigint fibonacci_stack(int x){
    if(x <= 0){
        return -1;
    } else if(x == 1 || x == 2){
        return 1;
    } else {
        ubigint a = fibonacci_stack(x-1);
        a.add(fibonacci_stack(x-2));
        return a;
    }
}

ubigint fibonacci_loop(int x){
    if(x <= 0){
        return -1;
    } else if(x == 1 || x == 2){
        return 1;
    } else {
        ubigint x1 = 1;
        ubigint x2 = 1;
        ubigint x3 = 1;
        for(int i = 3; i <= x; ++i){
            x3.add(x1);
            x1 = x2;
            x2 = x3;
        }
        return x3;
    }
}