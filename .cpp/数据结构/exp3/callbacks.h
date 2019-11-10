// -- Foundation ---
// 回调表达式
// created be cht
// #relate
// #endrelate

#pragma once
#include <iostream>
#include "flags.h"
using namespace std;

typedef void (*action)();

class callback {
};

template <typename T>
class action_callback: virtual public callback{
public:
    virtual void call(T arg) = 0;
};

template <typename T, typename Tout>
class func1_callback:virtual  public callback{
public:
    virtual Tout call(T arg) = 0;
};

template <typename T1, typename T2,typename Tout>
class func2_callback:virtual public callback{
public:
    virtual Tout call(T1 arg1, T2 arg2) = 0;
};


//frequent usages.
template <typename T>
class comparer_callback:virtual public func2_callback<T,T,bool>{

};

template <typename T>
class filter_callback:virtual public func1_callback<T,bool>{

};

//defaults.
template <typename T>
class print_callback:virtual public action_callback<T>{
public:
    void call(T arg) override {
        cout << arg << endl;
    }
};

template <typename T>
class print_space_callback:virtual public action_callback<T>{
public:
    void call(T arg) override {
        cout << arg << " ";
    }
};

