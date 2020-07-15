//
// Created by t1542 on 2020/5/18.
//
#pragma once
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "max_number.h"

using namespace std;


class sorthelper{
public:
    explicit sorthelper(int max_n = 10000){
        //初始化随机数生成器
        random_device rd;
        e.seed(time(nullptr));
        this->max_n = max_n;
        bits = ceil(log10(max_n - 1));
        //cout << max_n << " " << bits;
    }
    void build_data(int* a,int length,int way = 0){
        //int length = 200;
        //int max_n = 10000;
        if(way == 0){ //random generate
            for(int i = 0; i < length; ++i){
                a[i] = rand_int(0,max_n);
            }
        } else {
            double step = max_n / (double)length;
            if(way == 1){
                for(int i = 0; i < length; ++i){
                    a[i] = (int)( i * step);
                }
            } else {
                for(int i = 0; i < length; ++i){
                    a[i] = (int)( (length - 1 - i) * step);
                }
            }
//        int swap_count = length / 20;
//        for(int i = 0; i< swap_count; ++i){
//            int swap_i = rand_int(0, length);
//            int swap_j = rand_int(0, length);
//            swap(a[swap_i], a[swap_j]);
//        }
        }
    }
    void build_data_vector(vector<int>& a, int length){
        for(int i = 0; i < length; ++i){
            a.push_back(rand_int(0,max_n));
        }
    }

    long test_a_case(int size, int of = 0){
        clock_t start = clock();
        vector<int> a;
        int start_index = 0;
        int end_index = size;

        build_data_vector(a, size);
        if(of == 0)
            max_number_loop(a, start_index, end_index);
        else if(of == 1)
            max_number_division(a, start_index, end_index);
        else if(of == 2)
            max_number_dy(a, start_index, end_index);
        clock_t end = clock();
        return end - start;
    }

    long test(int size_max){
        for (int i = 100; i < size_max; i+=100) {
            cout << setw(6) << i << ": "
            << setw(6) << test_a_case(i, 0)
            << setw(6) << test_a_case(i, 1)
            << setw(6) << test_a_case(i, 2)
            << endl;
        }
    }

private:
    default_random_engine  e;
    int max_n;
    int bits;

    int rand_int(int start, int end){
        uniform_int_distribution<unsigned> u(start, end -1);
        return u(e);
    }
};