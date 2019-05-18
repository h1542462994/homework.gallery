#pragma once
#include<iostream>

using namespace std;

class A
{
public:
    A() 
    {
        cout << "call A()" << endl;
        a = 0; b = 0; 
    }
    A(int i) 
    {
        cout << "call A(int)" << endl;
        a = i; b = 0;
    }
    A(int i, int j) 
    {
        cout << "call A(int,int)" << endl;
        a = i; b = j;
    }
    void display() { cout << "a=" << a << " b=" << b; }
private:
    int a;
    int b;
};

class B :public A
{
public:
    B()
    { 
        cout << "call B()" << endl;
        c = 0; 
    }
    B(int i) :A(i) 
    {
        cout << "call B(int)" << endl;
        c = 0;
    }
    B(int i, int j) :A(i, j)
    {
        cout << "call B(int,int)" << endl;
        c = 0;
    }
    B(int i, int j, int k) :A(i, j) 
    {
        cout << "call B(int,int,int)" << endl;
        c = k;
    }
    void display1()
    {
        display();
        cout << " c=" << c << endl;
    }
private:
    int c;
};