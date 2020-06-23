#include<iostream>
#include<cstdlib>
#include"Date.h"
using namespace std;



int main() 
{
	Date d1(10, 14, 2005);
	Date d2(12, 30);
	Date d3(10);
	Date d4;
	d1.display();
	d2.display();
	d3.display();
	d4.display();
	system("pause");
	return 0;
}