// ---- 上级题目3 ----
// Created by cht.
// 题目1: 使用数组实现双端栈
// 题目2: 使用deque实现双端栈
// 题目3: 使用链表实现双端栈
// #relates
// dstack_direct: 表明调用的是哪一个栈
// i_dstack: 双端栈
// array_stack: 数组双端栈
// deque_stack: 队列双端栈
// list_stack: 双向链表栈
// #endrelates

#pragma once
#include <stdexcept>
#include <deque>
#include "callbacks.h"
#include "dnode.h"

using namespace std;

/**
 * 标识是第一个栈还是第二个栈。
 */
enum class dstack_direct{
    first = 1,
    second = 2
};


template <typename T>
class i_dstack{
public:
    virtual ~i_dstack()= default;

    bool empty(dstack_direct direct = dstack_direct::first){
        if(direct == dstack_direct::first){
            return empty_first();
        } else {
            return empty_second();
        }
    }
    void push(T value, dstack_direct direct = dstack_direct::first){
        if(direct == dstack_direct::first){
            push_first(value);
        } else {
            push_second(value);
        }
    }
    void pop(dstack_direct direct = dstack_direct::first){
        if(direct == dstack_direct::first)  {
            pop_first();
        } else {
            pop_second();
        }
    }

    T top(dstack_direct direct = dstack_direct::first){
        if(direct == dstack_direct::first) {
            return peak_first();
        } else {
            return peak_second();
        }
    }

    virtual bool empty_first() const = 0;
    virtual bool empty_second() const = 0;
    virtual void push_first(T value) = 0;
    virtual void push_second(T value) = 0;
    virtual void pop_first() = 0;
    virtual void pop_second() = 0;
    virtual T peak_first() const = 0;
    virtual T peak_second() const = 0;

    //apply functions
    void show_front(action_callback<T>& callback){
        while(!empty_first()){
            callback.call(peak_first());
            pop_first();
        }
    }

    void show_back(action_callback<T>& callback){
        while(!empty_second()){
            callback.call(peak_second());
            pop_second();
        }
    }

};

class limit_container{
public:
    virtual bool is_full() const = 0;
};

template <typename T>
class array_stack:  public limit_container,public i_dstack<T>{
public:
    ~array_stack() override {
        delete container;
    }

    explicit array_stack(int capacity = 100){
        if(capacity <= 0){
            throw logic_error("capacity is too small");
        }
        container = new T[capacity];
        this->capacity = capacity;
        this->p_front = 0;
        this->p_end = capacity - 1;
    }

    bool is_full() const override {
        return p_front > p_end;
    }

    bool empty_first() const override {
        return p_front <= 0;
    }

    bool empty_second() const override  {
        return p_end >= capacity -1;
    }

    void push_first(T value) override {
        if(is_full()){
            throw logic_error("array is full!");
        }
        container[p_front++] = value;
    }

    void push_second(T value) override {
        if(is_full()){
            throw logic_error("array is full!");
        }
        container[p_end--] = value;
    }

    void pop_first() override {
        if(empty_first()){
            throw logic_error("stack first is empty!");
        }
        --p_front;
    }

    void pop_second() override {
        if(empty_second()){
            throw logic_error("stack second is empty!");
        }
        ++p_end;
    }

    T peak_first() const override {
        if(empty_first()){
            throw logic_error("stack first is empty!");
        }
        return container[p_front-1];
    }

    T peak_second() const override {
        if (empty_second()) {
            throw logic_error("stack second is empty");
        }
        return container[p_end + 1];
    }

private:
    T* container = nullptr;
    int capacity = 0;
    int p_front = 0;
    int p_end = 0;
};

template <typename T>
class deque_stack: public i_dstack<T> {
public:
    ~deque_stack() override = default;

    bool empty_first() const override {
        return size_first == 0;
    }

    bool empty_second() const override {
        return size_second == 0;
    }

    void push_first(T value) override {
        container.push_front(value);
        ++size_first;
    }

    void push_second(T value) override {
        container.push_back(value);
        ++size_second;
    }

    void pop_first() override {
        if(empty_first()){
            throw logic_error("stack first is empty! on pop");
        }
        container.pop_front();
        --size_first;
    }

    void pop_second() override {
        if(empty_second()){
            throw logic_error("stack second is empty! on pop");
        }
        container.pop_back();
        --size_second;
    }

    T peak_first() const override {
        if(empty_first()){
            throw logic_error("stack first is empty! on peak");
        }
        return *container.begin();
    }

    T peak_second() const override  {
        if(empty_second()){
            throw logic_error("stack second is empty! on peak");
        }
        return *container.end();
    }

private:
    deque<T> container;
    int size_first = 0;
    int size_second = 0;
};

template <typename T>
class list_stack: public i_dstack<T>{
public:
    ~list_stack() override {
        dnode_fac::destroy(first);
    }

    bool empty_first() const override {
        return first_bottom == nullptr;
    }

    bool empty_second() const override {
        return second_bottom == nullptr;
    }

    void push_first(T value) override {
        if (first_bottom == nullptr) {
            if (second_bottom != nullptr) {
                first_bottom = dnode_fac::append_pre(second_bottom,value);
            } else {
                first_bottom = new dnode<T>(value);
            }
            first = first_bottom;
        } else {
            first = dnode_fac::append_pre(first,value);
        }
    }

    void push_second(T value) override {
        if (second_bottom == nullptr) {
            if (first_bottom != nullptr) {
                second_bottom = dnode_fac::append_back(first_bottom, value);
            } else {
                second_bottom = new dnode<T>(value);
            }
            second = second_bottom;
        } else {
            second = dnode_fac::append_back(second,value);
        }
    }

    T peak_first() const override {
        if (first == nullptr) {
            throw range_error("stack first is empty! on peak");
        }
        return first->value;
    }

    T peak_second() const override {
        if (second == nullptr) {
            throw range_error("stack second is empty! on peak");
        }
        return second->value;
    }

    void pop_first() override {
        if (first == nullptr) {
            throw range_error("stack first is empty! on pop");
        }
        auto c = first;
        first = dnode_fac::remove_front(first);
        if(first == nullptr){
            first_bottom = nullptr;
        }
    }

    void pop_second() override {
        if (second == nullptr) {
            throw range_error("stack first is empty on pop");
        }
        auto c = second;
        second = dnode_fac::remove_back(second);
        if(second == nullptr){
            second_bottom = nullptr;
        }
    }

private:
    dnode<T>* first = nullptr;
    dnode<T>* second = nullptr;
    dnode<T>* first_bottom = nullptr;
    dnode<T>* second_bottom = nullptr;
};