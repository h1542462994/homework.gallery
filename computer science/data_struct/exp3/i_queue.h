// ---- 上级题目3 ----
// Created by cht.
// 题目1: 使用数组实现双端栈
// 题目2: 使用deque实现双端栈
// 题目3: 使用链表实现双端栈
// #relates
// i_queue: 队列容器
// list_queue: 链表队列
// #endrelates
#include "node.h"
#include <stdexcept>

#pragma once

template <typename T>
class i_queue{
public:
    virtual ~i_queue()= default;
    virtual void push(T value) = 0;
    virtual T front() const = 0;
    virtual void pop() = 0;
    virtual bool empty() const = 0;
};

template <typename T>
class list_queue: public i_queue<T>{
public:
    list_queue(): head(nullptr), tail(nullptr){

    }

    ~list_queue(){
        node_fac::destroy(head);
    }

    void push(T value) override {
        if(head == nullptr){
            head = new node<T>(value);
            tail = head;
        } else {
            tail = node_fac::append(tail,value);
        }
    }

    T front() const override {
        if(empty()){
            throw range_error("the queue is empty");
        } else {
            return head->value;
        }
    }

    void pop() override {
        if(empty()){
            throw range_error("the queue is empty");
        } else {
            head = node_fac::remove_where(head,head);
        }
    }

    bool empty() const override {
        return head == nullptr;
    }
private:
    node<T>* head = nullptr;
    node<T>* tail = nullptr;
};

