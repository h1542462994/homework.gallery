//
// Created by t1542 on 2020/5/14.
//
#pragma once
class calculable{
public:
    explicit calculable(bnode<char>* value, int number = 1): value(value), number(number){

    }

    bnode<char>* value;
    int number;

    void add(){
       this->number = this->number + 1;
    }
    static calculable combine(calculable first, calculable second){
        auto* node = new bnode<char>('*', first.value, second.value);
        return calculable(node, first.number + second.number);
    }

    friend bool operator > (calculable left, calculable right){
        return left.number > right.number;
    }
};
