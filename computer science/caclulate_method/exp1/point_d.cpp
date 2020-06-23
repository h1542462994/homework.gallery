//
// Created by t1542 on 2020/3/6.
//

#include "point_d.h"

ostream &operator<<(ostream &o, const point_d& p) {
    o << "(" << p.x << ", " << p.y << ")";
    return o;
}

