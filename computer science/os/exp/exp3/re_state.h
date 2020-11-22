//
// Created by cht on 2020/11/22.
//

#pragma once
#include <iostream>
#include <iomanip>
#include "simple_io.h"



using namespace std;
//
class re_state {
private:

    // process count
    int p_count = 0;
    // resource count
    int r_count = 0;
    // resource vector
    int* r = nullptr;
    // claim matrix
    int* c = nullptr;
    // allocated matrix
    int* a = nullptr;
    int* n = nullptr;

public:
    // 拥有充足的资源
    const string FLEXIBLE = "flexible";
    const string CLAIM_ERROR = "claim error";
    const string UNSAFE = "unsafe";
    const string REQUEST_OVERFLOW = "request_overflow";
    const string FINISH = "finish";

    re_state(int p_count, int r_count, int* r, int* c): p_count(p_count), r_count(r_count){
        a_copy(this->r, r, p_count);
        a_copy(this->c, c, p_count * r_count);
        a_fill(this->a, 0, p_count * r_count);
        a_sub(this->n, this->c, this->a, p_count * r_count);
    }
    re_state(int p_count, int r_count, int* r, int* c, int* a): p_count(p_count), r_count(r_count) {
        a_copy(this->r, r, p_count);
        a_copy(this->c, c, p_count * r_count);
        a_copy(this->a, a, p_count * r_count);
        a_sub(this->n, this->c, this->a, p_count * r_count);
    }
    re_state(const re_state& other): p_count(other.p_count), r_count(other.r_count) {
        a_copy(this->r, other.r, other.p_count);
        a_copy(this->c, other.c, other.p_count * other.r_count);
        a_copy(this->a, other.a, other.p_count * other.r_count);
        a_sub(this->n, other.c, other.a, other.p_count * other.r_count);
    }
    re_state& operator = (re_state other){
        this->p_count = other.p_count;
        this->r_count = other.r_count;
        a_copy(this->r, other.r, other.p_count);
        a_copy(this->c, other.c, other.p_count * other.r_count);
        a_copy(this->a, other.a, other.p_count * other.r_count);
        a_sub(this->n, other.c, other.a, other.p_count * other.r_count);
        return *this;
    }
    virtual ~re_state() {
        delete[] r;
        delete[] c;
    }

    int resource_at(int index) const {
        return r[index];
    }
    int claim_at(int row, int column) const {
        return c[row * r_count + column];
    }
    int allocated_at(int row, int column) const {
        return a[row * r_count + column];
    }
    int need_at(int row, int column) const {
        return n[row * r_count + column];
    }
    bool is_finish(int p_index) const {
        int* start_i = n + p_index * r_count;
        if (a_eq_a(start_i, 0, r_count)) {
            return true;
        }
        return false;
    }
    int* remain() const {
        int *v2 = nullptr;
        a_copy(v2, r, r_count);
        for (int i = 0; i < p_count; ++i) {
            int* n_start_i = n + i * r_count;
            int* a_start_i = a + i * r_count;
            if (!a_eq_a(n_start_i, 0, r_count)){
                a_sub(v2, v2, a_start_i, r_count);
            }
        }

        return v2;
    }

    static void print_letters(ostream& o_str, int length, int c_width) {
        char start = 'A';
        for (int i = 0; i < length; ++i) {
            o_str << setw(c_width) << start++;
        }
    }
    // 获取当前的状态
    string get_state() const {
        bool next = true;
        // 判断资源是不是充足
        int* c_all = nullptr;
        a_fold(c_all, c, p_count, r_count);
        if (a_le(c_all, r, r_count)){
            next = false;
        }
        delete[] c_all;
        if (!next) {
            return FLEXIBLE;
        }

        // 判断声明是否错误
        bool c_error = false;
        for (int i = 0; i < p_count * r_count; i+= r_count) {
            if(!a_le(c+i, r, r_count)){
                c_error = true;
                break;
            }
        }
        if (c_error){
            return CLAIM_ERROR;
        }

        string result;
        next = true;
        int* re = remain();
        int path_index = 0;
        int* path = new int[p_count];
        for (int i = 0; i < p_count; ++i) {
            int* start_i = n + i * r_count;
            if (a_eq_a(start_i, 0, r_count)){ // 判断是否是结束的进程
                path[path_index++] = i;
            }
        }
        if (path_index == p_count) {
            result = FINISH;
            next = false;
        }
        int i = 0;
        while(i < p_count) {
            int* start_i = n + i * r_count;
            if (a_min(start_i, r_count) < 0) { // 表示申请了超量的资源
                result = REQUEST_OVERFLOW;
                next = false;
                break;
            }

            if(!a_contains(path, i, path_index) && a_le(start_i, re, r_count)) {
                path[path_index++] = i;
                i = 0;
                a_add(re, re, start_i, r_count);
            } else {
                i++;
            }
        }
        delete[] re;
        if(!next){
            return result;
        }

        if (path_index == p_count) {
            result = "safe, path=" + a_join(path, path_index, "->") ;
        } else {
            result = UNSAFE;
        }
        delete[] path;
        return result;
    }
    // 对进行a申请资源，返回新状态
    re_state move(int p_index, const int* alloc){
        int *new_r = nullptr;
        int *new_c = nullptr;
        int *new_a = nullptr;
        a_copy(new_r, r, r_count);
        a_copy(new_c, c, p_count * r_count);
        a_copy(new_a, a, p_count * r_count);
        int* start_i = new_a + r_count * p_index;
        for (int i = 0; i < r_count; ++i) {
            start_i[i] += alloc[i];
        }
        re_state re_state(p_count, r_count, new_r, new_c, new_a);
        delete[] new_r;
        delete[] new_c;
        delete[] new_a;
        return re_state;
    }

    friend ostream& operator << (ostream& o_str, const re_state& v){
        int* re = v.remain();
        o_str << "state:" << v.get_state() << endl;
        o_str << "info_data:" << endl;
        int i_width = 4;
        int c_width = 6;
        int t_width = 6 * v.r_count;
        // print first line
        o_str
            << setw(i_width) << "p" << " |"
            << setw(t_width) << "resources" << "|"
            << setw(t_width) << "claims" << "|"
            << setw(t_width) << "allocated" << "|"
            << setw(t_width) << "needs" << "|";
        o_str << endl;
        // print second line
        o_str
            << setw(i_width) << " " << " |";
        for (int i = 0; i < 4; ++i) {
            print_letters(o_str, v.r_count, c_width);
            o_str << "|";
        }
        o_str << endl;
        // print follow lines
        for (int i = 0; i < v.p_count; ++i) {
            o_str << setw(i_width) << i;
            if (v.is_finish(i)) {
                cout << "*|";
            } else {
                cout << " |";
            }
            for (int j = 0; j < v.r_count; ++j) {
                if (i == 0) {
                    o_str << setw(c_width) << v.resource_at(j);
                } else if(i == 1) {
                    o_str << setw(c_width) << re[j];
                } else {
                    o_str << setw(c_width) << " ";
                }
            }
            o_str << "|";
            for (int j = 0; j < v.r_count; ++j) {
                o_str << setw(c_width) << v.claim_at(i,j);
            }
            o_str << "|";
            for (int j = 0; j < v.r_count; ++j) {
                o_str << setw(c_width) << v.allocated_at(i,j);
            }
            o_str << "|";
            for (int j = 0; j < v.r_count; ++j) {
                o_str << setw(c_width) << v.need_at(i,j);
            }
            o_str << "|";
            o_str << endl;
        }

        delete[] re;
        return o_str;
    }


};



