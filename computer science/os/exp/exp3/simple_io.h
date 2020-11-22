//
// Created by cht on 2020/11/22.
//
#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
void read(T* array, int length){
    for (int i = 0; i < length; ++i) {
        cin >> array[i];
    }
}

void a_copy(int* &target, const int* source, int length){
    delete[] target;
    target = new int[length];
    for (int i = 0; i < length; ++i) {
        target[i] = source[i];
    }
}

void a_fill(int* &target, int value, int length){
    delete[] target;
    target = new int[length];
    for (int i = 0; i < length; ++i) {
        target[i] = value;
    }
}

void a_sub(int* &target, const int* a, const int* b, int length){
    int* v = new int[length];
    for (int i = 0; i < length; ++i) {
        v[i] = a[i] - b[i];
    }
    delete[] target;
    target = v;
}

void a_add(int* &target, const int* a, const int* b, int length){

    int* v = new int[length];
    for (int i = 0; i < length; ++i) {
        v[i] = a[i] + b[i];
    }
    delete[] target;
    target = v;
}

void a_fold(int* &target, const int* source, int row_count, int column_count){
    delete[] target;
    target = new int[column_count];
    for (int i = 0; i < column_count; ++i) {
        target[i] = 0;
    }
    for (int i = 0; i < column_count; ++i) {
        for (int j = 0; j < row_count; ++j) {
            target[i] += source[j * column_count + i];
        }
    }
}

bool a_le(const int* a, const int* b, int length){
    for (int i = 0; i < length; ++i) {
        if (a[i] > b[i]){
            return false;
        }
    }
    return true;
}

bool a_eq_a(const int* a, int value, int length){
    for (int i = 0; i < length; ++i) {
        if (a[i] != value) {
            return false;
        }
    }
    return true;
}

int a_max(const int* a, int length){
    int max = a[0];
    for (int i = 0; i < length; ++i) {
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int a_min(const int* a, int length){
    int min = a[0];
    for (int i = 0; i < length; ++i) {
        if (a[i] < min){
            min = a[i];
        }
    }
    return min;
}

bool a_contains(const int* a, int value, int length){
    for (int i = 0; i < length; ++i) {
        if (a[i] == value){
            return true;
        }
    }
    return false;
}

string a_join(const int* a, int length,const string& split = ","){
    ostringstream i_str;
    for (int i = 0; i < length; ++i) {
        i_str << a[i];
        if (i < length - 1){
            i_str << split;
        }
    }
    return i_str.str();
}