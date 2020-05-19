#include"declare.h"
#include<iostream>
using namespace std;

int main()
{
    B b1, b2(1), b3(1, 3), b4(1, 3, 5);
    b1.display1();
    b2.display1();
    b3.display1();
    b4.display1();

    return 0;
}