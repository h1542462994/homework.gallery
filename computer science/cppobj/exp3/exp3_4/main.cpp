#include<iostream>
#include<string>
#include<cstdlib>
#include"complex.h"
using namespace std;

void test() 
{
	complex c1(3, -4.5), c2(c1), c3;
	cout << "c1复数为:";
	c1.display();
	cout << "c2复数为:";
	c2.display();
	cout << "c3复数为:";
	c3.display();
}


int main() 
{
	test();

	system("pause");
	return 0;
}