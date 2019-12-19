//
// Created by cht on 2019/12/18.
//
#pragma once
#include <random>
#include <ctime>
#include "msort.h"
#include <iostream>
#include <iomanip>

using namespace std;
enum class sort_type{
    bubble,
    insert,
    select,
    quick,
    rx,
    heap
};

using namespace std;

default_random_engine  e;

int rand_int(int start, int end){
    uniform_int_distribution<unsigned> u(start, end -1);
    return u(e);
}

void build_data(int* a,int length, int way){
    //int length = 200;
    int max_n = 10000;
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
        int swap_count = length / 20;
        for(int i = 0; i< swap_count; ++i){
            int swap_i = rand_int(0, length);
            int swap_j = rand_int(0, length);
            swap(a[swap_i], a[swap_j]);
        }
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
        m_rx_sort(a, a + length, 4);
    } else {
        m_heap_sort(a, a + length);
    }
    clock_t end = clock();
    return end-start;
}

void test_a_size(int size){
    int column_size = 6;
    cout << "test size:" << size << endl;

    cout << setw(column_size) << "*" << setw(column_size) << "random"
        << setw(column_size) << "asc" << setw(column_size) << "desc" << endl;

    sort_type st[] = {sort_type::bubble, sort_type::insert, sort_type::select,
                      sort_type::quick, sort_type::rx, sort_type::heap};
    string sn[] = {"bubble","insert","select","quick","rx","heap"};

    for(int i = 0; i < 6; i++){
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
