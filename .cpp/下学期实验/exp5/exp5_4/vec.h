#include<iostream>
using namespace std;

class vec 
{
public:
    vec(int n = 0);
    vec(const vec& x);
    ~vec();

    void operator=(const vec& x) ;
    vec operator+(const vec& x);
    vec operator-(const vec& x);

    int& operator[](int idx) ;

    void print();
private:
    int* a;
    int size;
};