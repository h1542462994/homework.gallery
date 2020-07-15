//
// Created by t1542 on 2020/5/18.
//
#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;
int ** create_arr(int x_size, int y_size){
    int** a = new int*[x_size];
    for(int i = 0; i < x_size; ++i){
        int* b = new int[y_size];
        a[i] = b;
    }

    return a;
}

void remove_arr(int** arr, int x_size){
    for(int i = 0; i < x_size; ++i){
        delete[] arr[i];
    }
    delete [] arr;
}

int get_value(int** arr, int x, int y){
    if(x < 0 || y < 0){
        return 0;
    } else {
        return arr[x][y];
    }
}

void set_value(int **arr, int x, int y, int v){
    arr[x][y] = v;
}

void print_arr(int **arr, int x_size, int y_size){
    for (int i = 0; i < x_size; ++i) {
        for (int j = 0; j < y_size; ++j) {
            cout << setw(4) << get_value(arr, i, j);
        }
        cout << endl;
    }
}

int ** construct_arr(const string & a, const string & b){
    int len_a = a.length();
    int len_b = b.length();
    int** arr = create_arr(len_a, len_b);
    for (int i = 0; i < len_a; ++i) {
        for (int j = 0; j < len_b; ++j) {
            if(a[i] == b[j]){
                set_value(arr, i, j, get_value(arr, i-1, j-1) + 1);
            } else {
                set_value(arr, i, j, max(get_value(arr, i-1, j), get_value(arr, i, j-1)));
            }
        }
    }

    return arr;
}

string get_string(int** arr, const string& a, const string& b){
    string temp;
    int index_a = a.length() - 1;
    int index_b = b.length() - 1;
    while(index_a > 0 && index_b > 0){
        int current = get_value(arr, index_a, index_b);
        int left_top = get_value(arr, index_a - 1, index_b - 1);
        int left = get_value(arr, index_a - 1, index_b);
        int top = get_value(arr , index_a, index_b - 1);
        if(top == left_top + 1){
            temp = a[index_a] + temp;
            --index_a;
            --index_b;
        } else {
            if(left >= top){
                --index_a;
            } else {
                --index_b;
            }
        }
    }
    if(get_value(arr, index_a, index_b) > 0){
        temp = a[index_a] + temp;
    }

    return temp;
}