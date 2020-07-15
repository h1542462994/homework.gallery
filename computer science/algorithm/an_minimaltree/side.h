//
// Created by t1542 on 2020/5/14.
//
#pragma once
template <typename T>
class side{
public:
    side(int start, int end, T length = T()): start(start), end(end), length(length) {

    }
    int start;
    int end;
    T length;

    friend bool operator > (side left, side right){
        return left.length > right.length;
    }
};
