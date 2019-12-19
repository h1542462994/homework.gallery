//
// Created by cht on 2019/12/18.
//
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;

template <typename T>
class bnode{
public:
    explicit bnode(T value):value(value), left(nullptr), right(nullptr){}
    explicit bnode(T value, bnode<T>* left, bnode<T>* right):value(value),left(left),right(right){}
    T value;
    bnode<T>* left;
    bnode<T>* right;
};

class bnode_fac{
public:
    /**
     * special method.
     * 使用后缀表达式构造一棵二叉树
     * @param expression
     * @return
     */
    static bnode<char>* build_with_suffix(const string& expression){

        //cout << expression;
        string operators = "+-*/";
        stack<bnode<char>*> w;
        for (char c: expression){
            if(operators.find(c)!=string::npos){
                auto first = w.top();
                w.pop();
                auto second = w.top();
                w.pop();
                w.push(new bnode<char>(c,second,first));
            } else {
                w.push(new bnode<char>(c));
            }
        }
        return w.top();
    }

    /**
     * special method
     * 打印友好的中缀表达式，满足符号的有限顺序和结合律。
     * @param node
     */
    static void print_mid_expression(bnode<char>* node){
        string ops = "+-*/";
        map<char,int> opa = {{'+',1},{'-',1},{'*',2},{'/',2}};
        if(node == nullptr)
            return;
        if(ops.find(node->value)!= string::npos){
            char c = node->value;
            char left = node->left->value;
            char right = node->right->value;

            if(ops.find(left)!=string::npos && opa[left] < opa[c]){
                cout << "(";
                print_mid_expression(node->left);
                cout << ")";
            } else {
                print_mid_expression(node->left);
            }

            cout << c;

            if(ops.find(right)!=string::npos && opa[right] <= opa[c]){ //相同符号左结合，所以也要加括号
                cout << "(";
                print_mid_expression(node->right);
                cout << ")";
            } else {
                print_mid_expression(node->right);
            }
        } else {
            cout << node->value;
        }
    }

    /**
     * 打印清晰的中缀表达式，全部加括号。
     * @param node
     */
    static void print_full_mid_expression(bnode<char>* node){
        string ops = "+-*/";
        if(node == nullptr)
            return;
        if(ops.find(node->value)!= string::npos){
            char c = node->value;
            char left = node->left->value;
            char right = node->right->value;

            if(ops.find(left)!=string::npos){
                cout << "(";
                print_full_mid_expression(node->left);
                cout << ")";
            } else {
                print_full_mid_expression(node->left);
            }

            cout << c;

            if(ops.find(right)!=string::npos){
                cout << "(";
                print_full_mid_expression(node->right);
                cout << ")";
            } else {
                print_full_mid_expression(node->right);
            }
        } else {
            cout << node->value;
        }
    }

    template <typename T>
    static void print_pre_order(bnode<T>* node, const string& separator = ""){
        if(node == nullptr)
            return;
        cout << node->value << separator;
        print_pre_order(node->left, separator);
        print_pre_order(node->right, separator);
    }

    template <typename T>
    static void print_mid_order(bnode<T>* node, const string& separator = ""){
        if(node == nullptr)
            return;
        print_mid_order(node->left, separator);
        cout << node->value << separator;
        print_mid_order(node->right, separator);
    }

    template <typename T>
    static void print_post_order(bnode<T>* node, const string& separator = ""){
        if(node == nullptr)
            return;
        print_post_order(node->left, separator);
        print_post_order(node->right, separator);
        cout << node->value << separator;
    }

    /**
     * 横向打印
     * @tparam T
     * @param node
     * @param start
     * @param spacing
     */
    template <typename T>
    static void l_print(bnode<T>* node, int start = 0, int spacing = 4){
        if(node == nullptr){
            return;
        }

        l_print(node->right, start + spacing, spacing);

        cout << setw(start) << " ";
        cout << node->value << endl;
        l_print(node->left,start + spacing, spacing);
    }

    /**
    * 内部函数:删除所有的节点
    * @param node
    */
    template <typename T>
    static void clear(bnode<T>*& node){
        if(node == nullptr){
            return;
        }
        clear(node->left);
        clear(node->right);

        delete node;
        node = nullptr;
    }
};