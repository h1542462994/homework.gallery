//
// Created by t1542 on 2020/3/16.
//
#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

class ubigint{
public:
    explicit ubigint(const string& value){
        int length = value.length();
        for(int i = length - 1; i >= 0; --i){
            data.emplace_back(value[i] - '0');
        }
    }
    ubigint(int value){
        while(value > 0){
            data.emplace_back(value % 10);
            value /= 10;
        }
    }
    ubigint(const ubigint& value){
        data = value.data;
    }
    friend ostream&operator << (ostream& o, const ubigint& v){
        int length = v.data.size();
        for(int i = length -1; i >= 0; --i){
            o << v.data[i];
        }
        return o;
    }
    friend bool operator == (const ubigint& left, const ubigint& right){
        if(left.data.size() != right.data.size()){
            return false;
        }
        int length = left.data.size();
        for(int i = 0; i < length; ++i ){
            if(left.data[i] != right.data[i]){
                return false;
            }
        }

        return true;
    }
    friend bool operator != (const ubigint& left, const ubigint& right){
        return !(left == right);
    }
    friend bool operator < (const ubigint& left, const ubigint& right) {
        int l_length = left.data.size();
        int r_length = right.data.size();

        if(l_length < r_length){
            return true;
        } else if(l_length > r_length){
            return false;
        } else {
            for(int i = l_length - 1; i >= 0; --i ){
                if(left.data[i] > right.data[i]){
                    return false;
                }
            }
            return left.data[0] < right.data[0];
        }
    }
    friend bool operator > (const ubigint& left, const ubigint& right) {
        return right < left;
    }
    friend bool operator <= (const ubigint& left, const ubigint& right){
        return left == right || left < right  ;
    }
    friend bool operator >= (const ubigint& left, const ubigint& right){
        return left == right || left > right;
    }

    void add(ubigint v){
        int v_size = v.data.size();
        int size = data.size();
        for(int i = 0; i < min(v_size, size); ++i){
            data[i]+=v.data[i];
        }
        for(int i = 0; i < v_size - size; ++i){
            data.emplace_back(v.data[size + i]);
        }
        adjust();
    }
private:
    void adjust(){
        int size = data.size();
        for(int i = 0; i < size - 1; ++i){
            int a = data[i] / 10;
            data[i]= data[i] % 10;
            data[i+1]+= a;
        }

        int p = size - 1;
        int c = data[p];
        while(c >= 10){
            c = data[p] / 10;
            data[p] = data[p] % 10;
            data.emplace_back(c);
        }
    }
    static short to_digit(char value){
        if (value >= '0' && value <= '9'){
            return (short)(value - '0');
        } else {
            return -1;
        }
    }
    //数据，从低位到高位
    vector<short> data;
};