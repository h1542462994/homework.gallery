//
// Created by t1542 on 2020/3/22.
//
#pragma once
#include<vector>
#include<string>
#include<sstream>

using namespace std;

class big_int {
public:
    big_int(){
        s = false;
    }
    big_int(int v){
        convert(v, s, buffer);
    }
    big_int(long v){
        convert(v, s, buffer);
    }
    big_int(long long v){
        convert(v, s, buffer);
    }
    big_int(const char* v){
        big_int r = big_int::parse(v);
        this->buffer = r.buffer;
        this->s = r.s;
    }

    explicit big_int(const vector<short>& v){
        s = false;
        buffer = v;
        adjust(buffer);
    }
    static big_int parse(const string& v);
    big_int operator -();
    friend big_int operator + (const big_int& left, const big_int& right);
    friend big_int operator - (const big_int& left, const big_int& right);
    friend big_int operator * (const big_int& left, const big_int& right);
    friend bool operator == (const big_int& left, const big_int& right);
    friend bool operator != (const big_int& left, const big_int& right);
    friend bool operator < (const big_int& left, const big_int& right);
    friend bool operator > (const big_int& left, const big_int& right);
    friend bool operator <= (const big_int& left, const big_int& right);
    friend bool operator >= (const big_int& left, const big_int& right);
    big_int& operator = (const big_int& v);
    friend ostream& operator << (ostream& o, const big_int& v);
    string to_string() const;
private:
    //store the numbers.
    vector<short> buffer;
    //store the flag.
    bool s{};
    const static vector<short> zero_store;
    //转换数值到大数
    template <typename T>
    static void convert(T v, bool& s, vector<short>& buffer);
    static void adjust(vector<short>& buffer);
    static void adjust_2(vector<short>& buffer1, vector<short>& buffer2);
    static vector<short> cut(const vector<short>& buffer, int start, int end);
    static void fill_zero(vector<short>& buffer, int n);
    static void cut_zero(vector<short>& buffer);
    static void left_move(vector<short>& buffer1, int n);

    static bool abs_larger(const vector<short>& buffer1,const vector<short>& buffer2);
    static bool abs_equal(const vector<short>& buffer1,const vector<short>& buffer2);
    static void add(vector<short>& buffer1,const vector<short>& buffer2);
    static void sub(vector<short>& buffer1,const vector<short>& buffer2);
    static void normal_multiply(vector<short>& buffer1, const vector<short>& buffer2);
    //传说中的分治乘法
    static vector<short> divide_multiply(const vector<short>& buffer1, const vector<short>& buffer2);
    //在相等情况下的操作
    static vector<short> divide_multiply_same(const vector<short>& buffer1, const vector<short>& buffer2);
    static void ftx_multiply(vector<short>& buffer1, const vector<short>& buffer2);
};

