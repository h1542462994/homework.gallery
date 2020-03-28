//
// Created by t1542 on 2020/3/16.
//
#pragma once
#include <random>
#include <ctime>
#include "msort.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
enum class sort_type{
    bubble,
    insert,
    select,
    quick,
    rx,
    heap,
    merge,
    count
};

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

    long test_sort(int* a ,int length, sort_type type){
        clock_t start = clock();
        if(type == sort_type::bubble){
            m_bubble_sort(a, a + length);
        } else if(type == sort_type::select){
            m_select_sort(a, a + length);
        } else if(type == sort_type::insert){
            m_insert_sort(a, a + length);
        } else if(type == sort_type::quick){
            m_quick_sort(a, a + length);
        } else if(type == sort_type::rx){
            m_rx_sort(a, a + length, bits);
        } else if(type == sort_type::heap) {
            m_heap_sort(a, a + length);
        } else if(type == sort_type::merge) {
            m_merge_sort(a, a + length);
        } else if(type == sort_type::count){
            m_count_sort(a, a + length, max_n);
        }
        clock_t end = clock();
        return end-start;
    }

    void test_a_size(int size){
        int column_size = 6;
        int type_length = 8;
        cout << "test size:" << size << endl;

        cout << setw(column_size) << "*" << setw(column_size) << "random"
             << setw(column_size) << "asc" << setw(column_size) << "desc" << endl;

        sort_type st[] = {sort_type::bubble, sort_type::select,
                          sort_type::quick, sort_type::rx, sort_type::heap, sort_type::insert, sort_type::merge, sort_type::count};
        string sn[] = {"bubble","select","quick","rx","heap","insert","merge","count"};

        for(int i = 0; i < type_length; i++){
            int* random_data = new int[size];
            int* asc_data = new int[size];
            int* des_data = new int[size];
            build_data(random_data, size, 0);
            build_data(asc_data, size, 1);
            build_data(des_data, size, 2);

            cout << setw(column_size) << sn[i];
            cout << setw(column_size) << test_sort(random_data, size, st[i]);
            cout << setw(column_size) << test_sort(asc_data, size, st[i]);
            cout << setw(column_size) << test_sort(des_data, size, st[i]);
            cout << endl;

            delete[] random_data;
            delete[] asc_data;
            delete[] des_data;
        }

    }
    void test_select(int size, int index){
        int column_size = 6;
        int type_length = 8;
        cout << "test size:" << size << endl;
        cout << setw(column_size) << "*" << setw(column_size) << "time" << endl;
        int *random_data = new int[size];
        int *random_data2 = new int[size];
        build_data(random_data, size, 0);
        build_data(random_data2, size, 0);
        cout << setw(column_size) << "sort" << setw(column_size) << test_sort(random_data, size, sort_type::quick) << endl;
        cout << setw(column_size) << "select";
        clock_t t = clock();
        int result = m_line_select(random_data2, random_data2 + size, index, 0);
        clock_t t2 = clock();
        cout << setw(column_size) << t2 - t << endl;
        cout << "element = " << result << endl;

        delete[] random_data;
        delete[] random_data2;
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


