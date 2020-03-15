//
// Created by t1542 on 2020/3/6.
//

#include "tools.h"


void tools::print_a(const vector<point_d>& results) {
    for(point_d p: results){
        cout << p << endl;
    }
}

void tools::print_script(const vector<point_d>& results) {
    cout << "> print scripts" << endl;
    cout << "x = [";
    int _size = results.size();
    for(int i = 0; i < _size; ++i){
        cout << i+1 << " ";
    }
    cout << "];" << endl << "y = [";
    for(point_d p: results){
        cout << p.x << " ";
    }
    cout << "];" << endl;
}