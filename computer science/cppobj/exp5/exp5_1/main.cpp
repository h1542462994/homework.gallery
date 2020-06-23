#include<iostream>
#include"complex.h"
using namespace std;
int main()
{
    complex c1(1,2),c2(2),c3(c1),c4(1,3),c5(4,1);
    c1 = c1 + c2 + c3;
    cout << c1 << endl;
    c2 = -c3;
    cout << c2 << endl;
    c3 = c2 - c1;
    cout << c3 << endl;
    c4 = c4 - c1;
    cout << c4 << endl;
    c5 = c5 + (c4 + 4);
    cout << c5 << endl;

    return 0;
}