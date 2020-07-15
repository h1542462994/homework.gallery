//
// Created by t1542 on 2020/5/14.
//
#pragma once
template<typename T>
class bnode{
public:
    explicit bnode(T value, bnode<T>* left = nullptr, bnode<T>* right = nullptr):value(value),left(left),right(right){

    }
    T value;
    bnode<T>* left;
    bnode<T>* right;

    bool has_children(){
        return !(left == nullptr && right == nullptr);
    }

};