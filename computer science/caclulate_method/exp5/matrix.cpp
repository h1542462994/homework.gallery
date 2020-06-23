//
// Created by t1542 on 2020/3/28.
//

#include <cmath>
#include "matrix.h"

void matrix::get_row_column(initializer_list<initializer_list<double>>& data, int &row_count, int &column_count) {
    row_count = data.size();
    int max_column = data.begin()->size();
    for(auto p: data){
        if(p.size() > max_column){
            max_column = p.size();
        }
    }
    column_count = max_column;
}

void matrix::fill(initializer_list<initializer_list<double>> &data, double*& fills, int &row_count, int &column_count) {
    fills = new double[row_count * column_count];
    int i = 0;
    for(auto p1: data){
        int j = 0;
        for(auto p2: p1){
            fills[i * column_count + j++] = p2;
        }
        while(j < column_count){
            fills[i * column_count + j++] = 0;
        }
        ++i;
    }
}

void matrix::print(int w) {
    int fill1 = 2;
    if(_is_error){
        cout << "error!matrix" << endl;
    } else {
        for (int i = 0; i < _row_count; ++i) {
            for (int j = 0; j < _column_count; ++j) {
                cout << setw(w) << fills[i * _column_count + j];
            }
            cout << endl;
        }
    }
}

void matrix::print_with_title(const string& title, int w) {
    int title_fill = title.size();
    int n_fill = 4;
    if(_is_error){
        cout << title << " = error!matrix" << endl;
    } else {
        for (int i = 0; i < _row_count; ++i) {
            cout << setw(title_fill);
            if (i == 0) {
                cout << title;
            } else {
                cout << " ";
            }
            cout << setw(n_fill);
            if (i == 0) {
                cout << " = [";
            } else {
                cout << " ";
            }
            for (int j = 0; j < _column_count; ++j) {
                cout << setw(w) << fills[i * _column_count + j];

            }
            if (i == _row_count - 1){
                cout << " ]";
            }
            cout << endl;
        }
    }
}

matrix matrix::t() {
    matrix m(_column_count, _row_count);
    m.fills = new double[_row_count * _column_count];
    for (int i = 0; i < _row_count; ++i) {
        for (int j = 0; j < _column_count; ++j) {
            m.fills[j * _row_count + i] = fills[i * _column_count + j];
        }
    }
    return m;
}

matrix operator+(const matrix &m1, const matrix &m2) {
    if(m1._row_count == m2._row_count && m1._column_count == m2._column_count){
        int row = m1._row_count;
        int column = m1._column_count;

        matrix m(row, column);
        m.fills = new double[row * column];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                m.fills[i * column + j] = m1.fills[i * column + j] + m2.fills[i * column +j];
            }
        }
        return m;
    } else {
        return matrix::error_instance();
    }
}

matrix &matrix::operator-() {
    for (int i = 0; i < _row_count * _column_count; ++i) {
        fills[i] = - fills[i];
    }
    return *this;
}

matrix operator-(const matrix &m1, const matrix &m2) {
    matrix right = m2;
    return m1 + (-right);
}

matrix operator*(const matrix &m1, const matrix &m2) {
    if (m1._column_count == m2._row_count) {
        int row = m1._row_count;
        int column = m2._column_count;
        matrix m(row, column);
        m.fills = new double[row * column];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                double v = 0;
                for (int k = 0; k < m1._row_count; ++k) {
                    v += m1.fills[i * m1._column_count + k] * m2.fills[k * m2._column_count + j];
                }
                m.fills[i * column + j] = v;
            }
        }
        return m;
    } else {
        return matrix::error_instance();
    }
}

matrix matrix::e(int row) {
    matrix m(row, row);
    m.fills = new double[row * row];
    fill(m.fills, row*row);

    for (int i = 0; i < row; ++i) {
        m.fills[i] = 1;
    }

    return m;
}

matrix matrix::dialog(initializer_list<double> data) {
    int row = data.size();
    matrix m(row, row);
    m.fills = new double[row * row];
    fill(m.fills, row*row);

    int i = 0;
    for(auto p: data){
        m.fills[i * row + i] = p;
        ++i;
    }

    return m;
}

void matrix::fill(double*& data, int length) {
    for (int i = 0; i < length; ++i) {
        data[i] = 0;
    }
}

matrix matrix::get_dialog() {
    if(_row_count == _column_count){
        int row = _row_count;
        matrix m(row, row);
        m.fills = new double [row * row];
        fill(m.fills, row * row);

        for (int i = 0; i < row; ++i) {
            m.fills[i * row + i] = fills[i * row + i];
        }
        return m;
    } else {
        return matrix::error_instance();
    }
}

matrix matrix::inverse() const {
    if(_row_count != _column_count){
        return matrix::error_instance();
    }

    int row = _row_count;
    if(is_dialog()){
        matrix m(row, row);
        m.fills = new double[row * row];
        fill(m.fills, row * row);
        for (int i = 0; i < row; ++i) {
            m.fills[i * row + i] = 1.0 / fills[i * row + i];
        }
        return m;
    } else {
        //need to update
        return *this;
    }
}

bool matrix::is_dialog() const {
    if(_row_count != _column_count){
        return false;
    }
    for (int i = 0; i < _row_count; ++i) {
        for (int j = 0; j < _column_count; ++j) {
            if(i != j && fills[i * _column_count + j] != 0){
                return false;
            }
        }
    }
    return true;
}

matrix operator^(const matrix& m, int p) {
    if(m._row_count != m._column_count){
        return matrix::error_instance();
    }

    if(p == 0){
        return matrix::e(m._row_count);
    } else if(p > 0){
        matrix a = m;
        for (int i = 2; i <= p; ++i) {
            a = a * m;
        }
        return a;
    } else {
        matrix l = m.inverse();
        matrix a = l;
        for (int i = 2; i <= -p; ++i){
            a = a * l;
        }
        return a;
    }
}

matrix &matrix::operator=(const matrix &m) {
    _is_error = m._is_error;
    _row_count = m._row_count;
    _column_count = m._column_count;
    if(fills != nullptr){
        delete[] fills;
        fills = nullptr;
    }
    fills = new double[_row_count * _column_count];
    for (int i = 0; i < _row_count * _column_count; ++i) {
        fills[i] = m.fills[i];
    }
    return *this;
}

double matrix::vector_norm2() {
    if(_row_count == 1 || _column_count == 1){
        int length = _row_count * _column_count;
        double v = 0;
        for (int i = 0; i < length; ++i) {
            v += fills[i] * fills[i];
        }
        return sqrt(v);
    }
    return -1;
}



