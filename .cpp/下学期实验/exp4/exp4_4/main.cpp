#include"Template.h"
#include<iostream>
using namespace std;
int main()
{
    int int_array[]{ 7,11,4,6,9 };
    double double_array[]{ 15.67,144.12,13,98.4,32.0 };
    string string_array[]{ "hello","hello world","apple","xiaomi 5s" };

    print(int_array, 5);
    print(double_array, 5);
    print(string_array, 4);

    sort(int_array, 5);
    sort(double_array, 5);
    sort(string_array, 4);

    print(int_array, 5);
    print(double_array, 5);
    print(string_array, 4);

    return 0;    
}