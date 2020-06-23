#include"Date.h"
#include<iostream>

using namespace std;

Date::Date(int m , int d, int y ) :month(m), day(d), year(y)
{
}

void Date::display()
{
	cout << month << "/" << day << "/" << year << endl;
}
