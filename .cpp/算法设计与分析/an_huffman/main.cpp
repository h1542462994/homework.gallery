#include <iostream>
#include <algorithm>
#include "HuffmanTree.h"
using namespace std;

int main() {
    cout << "input the raw_string:" << endl;
    string str;
    getline(cin, str);
    HuffmanTree tree = HuffmanTree::build(str);
    tree.print();
    return 0;

//    int num;
//    cin >> num;
//    int* data = new int[num];
//    for(int i = 0; i < num; ++i){
//        cin >> data[i];
//    }
//    //排序
//    sort(data, data+num);
//
//    int* data_replace = new int[num];
//    //放到合适的位置
//    for (int i = 0; i < num; ++i) {
//        if(i % 2 == 0){ //是偶数
//            data_replace[i / 2] = data[i];
//        } else {
//            data_replace[num - i/2 - 1] = data[i];
//        }
//    }
//
//    //计算大小
//    int sum = 0;
//    for (int i = 0; i < num; ++i) {
//        sum+= data[i];
//    }
//
//    double value = 0;
//    for (int i = 0; i < num - 1; ++i) {
//        for (int j = i + 1; j < num; ++j) {
//            value += (j - i)* data_replace[i] * data_replace[j];
//        }
//    }
//    value = value / (sum * sum);
//
//    cout << value << endl;
//    delete[] data_replace;
//    delete[] data;

}
