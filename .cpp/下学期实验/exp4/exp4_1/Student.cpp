#include"Student.h"
#include<iostream>
using namespace std;

void Student::change(int n,float s)
{
    num = s;
    score = s;
}

void Student::display() const
{
    cout << num << " " << score << endl;
}