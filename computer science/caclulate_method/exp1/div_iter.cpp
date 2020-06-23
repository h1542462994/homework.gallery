//
// Created by t1542 on 2020/3/6.
//

#include "div_iter.h"

void div_iter::solve() {
    while (true) {
        double _mid = (left + right) / 2.0;
        double _mid_val = f(_mid);
        results.emplace_back(_mid, _mid_val);
        if (abs(right - left) < 2 * precision) {
            break;
        }
        if ((left_val < 0 && _mid_val < 0) || (right_val < 0 && _mid_val > 0)) {
            left = _mid;
            left_val = _mid_val;
        } else if((left_val < 0 && _mid_val > 0) || (right_val < 0 && _mid_val < 0)) {
            right = _mid;
            right_val = _mid_val;
        } else if(_mid_val == 0){
            break;
        }
    }
}


