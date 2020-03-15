//
// Created by t1542 on 2020/3/14.
//
#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<initializer_list>
using namespace std;

template <typename T>
class matrix {
public:
    matrix(int rows, int columns):  rows(rows), columns(columns){

    }
    matrix(const matrix& o){
        this->rows = o.rows;
        this->columns = o.columns;
        this->data = o.data;
        this->xs = o.xs;
    }

    void set(initializer_list<initializer_list<T>> d){
        int i = 0, j = 0;
        for(initializer_list<T> d1: d){
            data.emplace_back(vector<T>());
            for(T d2: d1){
                this->data[i].emplace_back(d2);
                j++;
            }
            i++;
        }
    }
    void set_x(initializer_list<string> x){
        for(const string& p: x){
            xs.emplace_back(p);
        }
    }

    void print_matrix(){
        cout << "matrix<" << rows << "x" << columns << ">" << endl;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                cout << setw(16) << data[i][j];
            }
            cout << endl;
        }
    };

    void print_m_with(){
        cout << "matrix<" << rows << "x" << columns << ">with x" << endl;
        for(int i = 0; i < rows; ++i){
            cout << setw(4) << xs[i];
            for(int j = 0; j < columns; ++j){
                cout << setw(16) << data[i][j];
            }
            cout << endl;
        }
    }

    //顺序高斯消元法。
    void gs(){
        for(int i = 0; i < columns - 1; ++i){
            for(int j = i+1; j < rows; ++j){
                T a = data[i][i];
                T b = data[j][i];
                T p = -b/a;
                row_apply(j, i, p);
            }
        }
    }

    //主元高斯消元法
    void main_gs(){
        for(int i = 0; i < columns - 1; ++i){
            //讲绝对值最大的列设为主元。
            int max_index = i;
            for(int j = i+1; j < rows; ++ j){
                if(abs(data[j][i]) > abs(data[max_index][i])){
                    max_index = j;
                }
            }
            if(i != max_index){
                swap_rows(i, max_index);
            }
            //print_m_with();
            // 高斯消元法
            for(int j = i+1; j < rows; ++j){
                T a = data[i][i];
                T b = data[j][i];
                T p = -b/a;
                row_apply(j, i, p);
            }

            //print_m_with();
        }
    }

    void p_solve(){
        cout << "solves" << endl;
        auto* x = new T[rows];

        for(int i = rows - 1; i >= 0; --i){
            T r = data[i][rows];
            for(int j = i+1; j < rows; ++j){
                r-= data[i][j] * x[j];
            }
            x[i] = r / data[i][i];
        }

        for(int i = 0; i < rows; ++i){
            cout << xs[i] << " = " << x[i] << endl;
        }

        delete[] x;
    }

    void row_apply(int line1, int line2, T p){
        for(int i = 0; i < columns; ++i){
            data[line1][i] += data[line2][i] * p;
        }
    }

    void swap_rows(int line1, int line2){
        for(int i = 0; i < columns; ++i){
            T temp = data[line1][i];
            data[line1][i] = data[line2][i];
            data[line2][i] = temp;
        }
        string x = xs[line1];
        xs[line1] = xs[line2];
        xs[line2] = x;
    }


private:
    vector<vector<T>> data;
    vector<string> xs;
    int columns = 0;
    int rows = 0;
};

