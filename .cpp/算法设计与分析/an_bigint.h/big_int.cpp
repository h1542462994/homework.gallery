//
// Created by t1542 on 2020/3/22.
//

#include "big_int.h"

//static function
big_int big_int::parse(const string &v) {
    auto a = big_int();
    int start = 0;
    int end = v.size();
    if(v[0] == '-'){
        a.s = true;
        start = 1;
    } else if (v[1] == '+'){
        a.s = false;
        start = 1;
    }

    for(int i = end - 1; i >= start ; --i){
        a.buffer.emplace_back((int)(v[i] - '0'));
    }

    vector<short> zero = {'0'};
    if(abs_equal(a.buffer, zero)){
        a.s = false;
    }

    adjust(a.buffer);
    if(a.buffer == big_int::zero_store)
        a.s = false;
    return a;
}

big_int big_int::operator-() {
    adjust(buffer);
    if(buffer == big_int::zero_store)
        return *this;
    big_int r = *this;
    r.s = !r.s;
    return r;
}

big_int operator+(const big_int& left, const big_int& right) {
    if(left.s == right.s){
        big_int r = left;
        big_int::add(r.buffer, right.buffer);
        big_int::adjust(r.buffer);
        return r;
    } else {
        if(big_int::abs_equal(left.buffer, right.buffer)){
            return 0;
        } else if(big_int::abs_larger(left.buffer, right.buffer)){
            big_int r = left;
            big_int::sub(r.buffer, right.buffer);
            big_int::adjust(r.buffer);
            return r;
        } else {
            big_int r = right;
            big_int::sub(r.buffer, left.buffer);
            big_int::adjust(r.buffer);
            return r;
        }
    }
}

big_int operator-(const big_int& left, const big_int& right) {
    big_int r = right;
    r.s = !r.s;
    return left + r;
}

big_int operator*(const big_int &left, const big_int &right) {
    if(left.buffer == big_int::zero_store || right.buffer == big_int::zero_store)
        return 0;

    big_int r;
    r.s = left.s != right.s;
    r.buffer = big_int::divide_multiply(left.buffer, right.buffer);
    return r;
}

bool operator==(const big_int& left, const big_int& right) {
    if (left.s != right.s)
        return false;
    else
        return big_int::abs_equal(left.buffer, right.buffer);
}

bool operator!=(const big_int& left, const big_int& right) {
    return !(left == right);
}

bool operator<(const big_int& left, const big_int& right) {
    if(left == right){
        return false;
    } else {
        return !(left > right);
    }
}

bool operator>(const big_int& left, const big_int& right) {
    if(left.s == false && right.s == true){
        return true;
    } else if (left.s == true && right.s == false){
        return false;
    } else {
        return big_int::abs_larger(left.buffer, right.buffer);
    }
}

bool operator<=(const big_int& left, const big_int& right) {
    return !(left > right);
}

bool operator>=(const big_int& left, const big_int& right) {
    return (left == right) || (left > right);
}

big_int& big_int::operator = (const big_int& v) = default;

ostream &operator<<(ostream &o, const big_int &v) {
    o << v.to_string();
    return o;
}

string big_int::to_string() const {
    ostringstream o;
    if(s){
        o << '-';
    }
    int length = buffer.size();
    for(int i = length - 1; i >= 0; --i){
        o << (int)(buffer[i]);
    }
    return o.str();
}

template<typename T>
void big_int::convert(T v, bool &s, vector<short> &buffer) {
    if (v < 0){
        s = true;
        v = -v;
    }

    while (v > 0){
        T r = v % 10;
        buffer.emplace_back(r);
        v /= 10;
    }
    adjust(buffer);
}

void big_int::adjust(vector<short> &buffer) {
    int length = buffer.size();
    for(int i = 0; i < length - 1; ++i){
        if(buffer[i] >= 10){
            short a = buffer[i] / 10;
            buffer[i] = buffer[i] % 10;
            buffer[i+1] += a;
        } else if(buffer[i] < 0){
            short a = buffer[i] / 10 - 1;
            buffer[i] = buffer[i] % 10 + 10;
            buffer[i+1] += a;
        }
    }

    cut_zero(buffer);
}

void big_int::adjust_2(vector<short> &buffer1, vector<short> &buffer2) {
    big_int::cut_zero(buffer1);
    big_int::cut_zero(buffer2);
    auto l = &buffer1;
    auto r = &buffer2;
    if (l->size() == r->size()){
        return;
    } else if (l->size() < r->size()) {
        l = &buffer2;
        r = &buffer1;
    }

    int to_fill_length = l->size() - r->size();
    big_int::fill_zero(*r, l->size() );
}

vector<short> big_int::cut(const vector<short> &buffer, int start, int end) {
    vector<short> r;
    r.reserve(end - start);
    for (int i = start; i < end; ++i) {
        r.emplace_back(buffer[i]);
    }
    return r;
}

void big_int::fill_zero(vector<short> &buffer, int n) {
    int to_fill_length = n - buffer.size();
    for (int i = 0; i < to_fill_length; ++i) {
        buffer.emplace_back(0);
    }
}

void big_int::cut_zero(vector<short> &buffer) {
    if(buffer.empty()){
        buffer.emplace_back(0);
        return;
    }
    while(buffer.back() == 0){
        buffer.pop_back();
    }
    if(buffer.empty()){
        buffer.emplace_back(0);
    }
}

void big_int::left_move(vector<short> &buffer1, int n) {
    vector<short> r;
    int length = buffer1.size();
    r.reserve(n + length);
    for (int i = 0; i < n; ++i) {
        r.emplace_back(0);
    }
    for (int i = 0; i < length; ++i) {
        r.emplace_back(buffer1[i]);
    }

    buffer1 = r;
}

bool big_int::abs_equal(const vector<short> &buffer1, const vector<short> &buffer2) {
    if(buffer1.size() != buffer2.size())
        return false;
    int length = buffer1.size();
    for(int i = 0; i < length; ++i){
        if(buffer1[i] != buffer2[i]){
            return false;
        }
    }
    return true;
}

bool big_int::abs_larger(const vector<short> &buffer1, const vector<short> &buffer2) {
    int length1 = buffer1.size();
    int length2 = buffer2.size();
    if(length1 < length2){
        return false;
    } else if(length1 > length2){
        return true;
    } else {
        for(int i = length1 - 1; i >= 1; --i ){
            if(buffer1[i] < buffer2[i])
                return false;
        }
        return buffer1[0] > buffer2[0];
    }
}

void big_int::add(vector<short> &buffer1, const vector<short> &buffer2) {
    if(buffer1 == big_int::zero_store){
        buffer1 = buffer2;
        return;
    } else if(buffer2 == big_int::zero_store){
        return;
    }
    int l_size = buffer1.size();
    int r_size = buffer2.size();
    for(int i = 0; i < min(l_size, r_size); ++i){
        buffer1[i]+= buffer2[i];
    }
    for(int i = 0; i < r_size - l_size; ++i){
        buffer1.emplace_back(buffer2[l_size + i]);
    }

    adjust(buffer1);
}

void big_int::sub(vector<short> &buffer1, const vector<short> &buffer2) {
    if(buffer2 == big_int::zero_store){
        return;
    }
    int l_size = buffer1.size();
    int r_size = buffer2.size();
    for(int i = 0; i < min(l_size, r_size); ++i){
        buffer1[i]-= buffer2[i];
    }

    adjust(buffer1);
}

void big_int::normal_multiply(vector<short> &buffer1, const vector<short> &buffer2) {

}

vector<short> big_int::divide_multiply(const vector<short> &buffer1, const vector<short> &buffer2) {
    auto l = buffer1;
    auto r = buffer2;

    if (l.size() == r.size()){
        return divide_multiply_same(buffer1, buffer2);
    } else {
        if(l.size() < r.size()){
            l = buffer2;
            r = buffer1;
        }
        int l_length = l.size();
        int r_length = r.size();

        int to_fill_length = l_length % r_length;
        if (to_fill_length != 0)
            to_fill_length = r_length - to_fill_length;
        l_length += to_fill_length;
        big_int::fill_zero(l, l_length);
        int n = l_length / r_length;
        vector<short> result = {0};

        for (int i = 0; i < n; ++i) {
            vector<short> cut = big_int::cut(l, i * r_length, (i+1)*r_length);
            vector<short> tr = big_int::divide_multiply_same(cut, r);
            big_int::left_move(tr, i * r_length);
            big_int::add(result, tr);
        }
        big_int::cut_zero(result);
        return result;
    }

}

vector<short> big_int::divide_multiply_same(const vector<short> &buffer1, const vector<short> &buffer2) {
    auto l = buffer1;
    auto r = buffer2;

    big_int::adjust_2(l, r);
    int length = buffer1.size();

    if(length == 1){
        vector<short> result;
        result.push_back(buffer1[0]*buffer2[0]);
        big_int::adjust(result);
        return result;
    } else {
        int left_length = length / 2;
        //int right_length = length - left_length;
        // lower -> higher
        // l = [...a...][...b...]
        // r = [...c...][...d...]
        vector<short> a = big_int::cut(buffer1, 0, left_length);
        vector<short> b = big_int::cut(buffer1, left_length, length);
        vector<short> c = big_int::cut(buffer2, 0, left_length);
        vector<short> d = big_int::cut(buffer2, left_length, length);
        vector<short> ac = divide_multiply_same(a, c);
        vector<short> bd = divide_multiply_same(b, d);

        big_int a_b = big_int(a) - big_int(b);
        big_int d_c = big_int(d) - big_int(c);

        vector<short> m = ac;
        big_int::add(m, bd);
        bool f = a_b.s != d_c.s;
        if(f){
            big_int::sub(m, big_int::divide_multiply_same(a_b.buffer, d_c.buffer));
        } else {
            big_int::add(m, big_int::divide_multiply_same(a_b.buffer, d_c.buffer));
        }

        big_int::left_move(m, left_length);
        big_int::left_move(bd, 2 * left_length);
        big_int::add(ac, bd);
        big_int::add(ac, m);
        big_int::cut_zero(ac);
        return ac;
    }


}

void big_int::ftx_multiply(vector<short> &buffer1, const vector<short> &buffer2) {

}

const vector<short> big_int::zero_store = {0};



















