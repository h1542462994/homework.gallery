//
// Created by t1542 on 2020/5/14.
//
#pragma once
#include "bnode.h"
#include "calculable.h"
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

typedef priority_queue<calculable, vector<calculable>, greater<> > p_greater;

class HuffmanTree {
public:
    /**
     * 构造对象。
     * @param value
     * @return
     */
    static HuffmanTree build(const string& value);
    void print();
private:
    /**
     * 存储Huffman节点集
     */
    p_greater _data;
    map<char, int> _raw;
    map<char, string> encoding;
    string str;

    /**
     * 从string计算Huffman节点集
     * @param value
     * @return
     */
    static void calc(const string& value,p_greater& _data_out, map<char,int> & _raw_out);

    /**
     * 聚合节点
     */
    void combine();

    /**
     * 是否需要继续聚合节点
     * @return
     */
    bool continue_combine() const;

    void encoding_iter(bnode<char>* node, const string& prefix ="");

};
