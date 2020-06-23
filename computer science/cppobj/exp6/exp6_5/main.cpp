#include"declare.h"
#include<iostream>
using namespace std;

int main() 
{
    Motorcycle m(300, 0.25, 1.1, 2);
    m.show();
    m.Vehicle::show();

    return 0;
}