//
// Created by t1542 on 2020/5/14.
//
#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
class mat {
public:
    mat(vector<vector<T>> _data){
        init(_data, _row_count, _column_count, this->_data);
    }
    mat(int row_count, int column_count) :_row_count(row_count), _column_count(column_count){
        _data = new T[_row_count * _column_count];
    }

    void to_default(){
        for (int i = 0; i < _row_count * _column_count; ++i) {
            _data[i] = T();
        }
    }

    T& at(int i, int j){
        return _data[i * _column_count + j];
    }
    void print(int space = 4) {
        int start_space = 2;
        for(int i = 0; i < _row_count; ++i){
            if(i == 0)
                cout << "[";
            else
                cout << " ";
            for(int j = 0; j < _column_count; ++j){
                cout << setw(space) << this->at(i,j) << ",";
            }
            if(i < _row_count -1 )
                cout << endl;
            else
                cout << "]";
        }
    }
    static mat scan_square(){
        vector<vector<int>> inputs;

        int lines = 0;
        for(int j = 0;;++j){
            string line;
            getline(cin, line);
            vector<int> data;
            istringstream istr_stream(line);
            int temp;
            while(istr_stream >> temp){
                data.push_back(temp);
            }

            inputs.push_back(data);

            // first_line
            if(j == 0)
                lines = data.size();
            if(j == lines - 1)
                break;
        }

        return mat(inputs);
    }
    int row_count() { return _row_count; }
    int column_count() { return _column_count; }
private:
    int _row_count{};
    int _column_count{};
    T* _data;
    static void init(vector<vector<T>>& _data, int& _rows, int& _columns, T*& _data_out) {
        get_size(_data, _rows, _columns);
        _data_out = new T[_rows * _columns];
        int i = 0;
        for(const vector<T>& p1: _data){
            int j = 0;
            for(int p2: p1){
                _data_out[i * _columns + j++] = p2;
            }
            for(;j < _columns; ++j ){
                _data_out[i * _columns + j] = T();
            }
            ++i;
        }
    }
    static void get_size(vector<vector<T>>& _data, int& _rows, int& _columns){
        _rows = _data.size();
        _columns = _data.at(0).size();
        for(const vector<int>& item: _data) {
            if (_data.size() > _columns) {
                _columns = _data.size();
            }
        }
    }
};


