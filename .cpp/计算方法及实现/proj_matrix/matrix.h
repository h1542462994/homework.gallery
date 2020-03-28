//
// Created by t1542 on 2020/3/28.
//

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <sstream>
using namespace std;

class matrix {
public:
    matrix(initializer_list<initializer_list<double>> data){
        get_row_column(data, _row_count, _column_count);
        fill(data, fills, _row_count, _column_count);
    }
    matrix(const matrix& m){
        _is_error = m._is_error;
        _row_count = m._row_count;
        _column_count = m._column_count;
        fills = new double[_row_count * _column_count];
        for (int i = 0; i < _row_count * _column_count; ++i) {
            fills[i] = m.fills[i];
        }
    }
    int row_count() { return _row_count; }
    int column_count() { return _column_count; }
    void print(int w = 8);
    void print_with_title(const string& title, int w = 8);
    double vector_norm2();

    matrix t();
    matrix get_dialog();

    ~matrix(){
        if(fills != nullptr){
            delete[] fills;
        }
    }

    friend matrix operator + (const matrix& m1, const matrix& m2);
    friend matrix operator - (const matrix& m1, const matrix& m2);
    friend matrix operator * (const matrix& m1, const matrix& m2);
    friend matrix operator ^ (const matrix& m1, int p);

    matrix& operator = (const matrix& m);

    matrix& operator -();

    static matrix error_instance(){
        matrix m(0,0);
        m._is_error = true;
        return m;
    }
    static matrix e(int row);
    static matrix dialog(initializer_list<double> data);


private:
    matrix(int _row_count, int _column_count): _row_count(_row_count), _column_count(_column_count){}
    static void get_row_column(initializer_list<initializer_list<double>>& data, int& row_count, int& column_count);
    static void fill(initializer_list<initializer_list<double>>& data, double*& fills, int& row_count, int& column_count);
    static void fill(double*& data, int length);
    matrix inverse() const;
    bool is_dialog() const;

    //void resize(int _rows, int _columns);

    bool _is_error = false;
    // 行数
    int _row_count;
    // 列数
    int _column_count;
    //填充
    double* fills = nullptr;
};
