#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace util {
    // 存储数字的集合，以小到大的排序
    template <typename T>
    class SortedSet {
    private:

    public:
        vector<T> data {};
        explicit SortedSet(vector<T> data = {}) {
            this->data = std::move(data);
            sort(this->data.begin(), this->data.end());
            cleanRedundant();
        }
        int add(T value) {
            data.emplace_back(value);
            sort(this->data.begin(), this->data.end());
            cleanRedundant();
            return indexAt(value);
        }
        void remove(T value) {
            if (!data.empty()) {
                int proceedIndex = 0;
                while (proceedIndex < data.size()) {
                    T current = data[proceedIndex];
                    if (current == value) {
                        data.erase(data.begin() + proceedIndex);
                    } else {
                        proceedIndex++;
                    }
                }
            }
        }
        int size() const {
            return data.size();
        }
        void addAnother(SortedSet<int> other){
            addRange(other.data);
        }
        void addRange(vector<int> other){
            for (auto v: other) {
                data.emplace_back(v);
            }
            sort(data.begin(), data.end());
            cleanRedundant();
        }
        bool contains(T value) const {
            for (auto v: data) {
                if (v == value) {
                    return true;
                }
            }
            return false;
        }
        int indexAt(T value) const {
            for (int i = 0; i < data.size(); ++i) {
                if (data[i] == value) {
                    return i;
                }
            }
            return -1;
        }
        void cleanRedundant(){
            if (!data.empty()) {
                T preValue = data[0];
                int proceedIndex = 1;
                while (proceedIndex < data.size()) {
                    T current = data[proceedIndex];
                    if (current == preValue) {
                        data.erase(data.begin() + proceedIndex);
                    } else {
                        proceedIndex++;
                        preValue = current;
                    }
                }
            }
        }
        friend ostream & operator << (ostream& o_str, const SortedSet& v) {
            ostringstream o;


            o << "{";
            int count = v.data.size();
            for (int i = 0; i < count; ++i) {
                o << v.data[i];
                if (i < count - 1) {
                    o << ",";
                }
            }
            o << "}";
            o_str << o.str();
            return o_str;
        }
        friend bool operator == (const SortedSet& left, const SortedSet& right)  {
            int count = left.data.size();
            if (count != right.data.size()) {
                return false;
            } else {
                for (int i = 0; i < count; ++i) {
                    if (left.data[i] != right.data[i]) {
                        return false;
                    }
                }
            }
            return true;
        }
        T operator [](int index) const {
            return data[index];
        }
    };

}
