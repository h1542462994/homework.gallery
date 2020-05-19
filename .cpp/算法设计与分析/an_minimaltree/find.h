//
// Created by t1542 on 2020/5/14.
//
#include <vector>
using namespace std;

template <typename T>
bool contains(vector<T> v,T key){
    for(auto item:v){
        if(item == key){
            return true;
        }
    }
    return false;
}