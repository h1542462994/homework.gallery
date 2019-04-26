#include"vec.h"
#include<iostream>
using namespace std;

vec::vec(int n = 0)
{
    this->a = new int[n];
    this->size = n;
}

vec::vec(const vec& x)
{
    this->size = x.size;
    this->a = new int[x.size];
    for (int i = 0; i < this->size; i++)
    {
        a[i] = x.a[i];
    }
}

void vec::operator= (const vec& x)
{
    this->size = x.size;
    delete[] this->a;
    this->a = new int[x.size];
    for (int i = 0; i < this->size; i++)
    {
        a[i] = x.a[i];
    }
}

vec::~vec()
{
    delete[] a;
}

vec vec::operator+(const vec& x)
{
    const vec* smaller, * bigger;
    if (this->size < x.size)
    {
        smaller = this;
        bigger = &x;
    }
    else
    {
        smaller = &x;
        bigger = this;
    }

    vec v(bigger->size);
    for (int i = 0; i < smaller->size; i++)
    {
        v.a[i] = smaller->a[i] + bigger->a[i];
    }
    for (int i = smaller->size; i < bigger->size; i++)
    {
        v.a[i] = bigger->a[i];
    }

    return v;
}

vec vec::operator-(const vec& x)
{
    const vec* smaller, * bigger;
    if (this->size < x.size)
    {
        smaller = this;
        bigger = &x;
    }
    else
    {
        smaller = &x;
        bigger = this;
    }

    vec v(bigger->size);
    //vec v(4);
    for (int i = 0; i < smaller->size; i++)
    {
        if (smaller == this)
            v.a[i] = smaller->a[i] - bigger->a[i];
        else
            v.a[i] = bigger->a[i] - smaller->a[i];
    }
    for (int i = smaller->size; i < bigger->size; i++)
    {
        if (smaller == this)
            v.a[i] = -(bigger->a[i]);
        else
            v.a[i] = bigger->a[i];
    }

    return v;
}

int& vec::operator[](int idx)
{
    return a[idx];
}

void vec::print()
{
    cout << "(";
    for (int i = 0; i < size; i++)
    {
        cout << a[i];
        if (i < size - 1)
            cout << ",";
    }
    cout << ")" << endl;
}