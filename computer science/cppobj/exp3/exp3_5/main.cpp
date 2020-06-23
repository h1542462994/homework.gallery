#include<iostream>
#include"triangle.h"
using namespace std;



int main()
{
	double a, b, c;
	cout << "请输入三角形的三边长：";
	cin >> a >> b >> c;
	triangle tra(a, b, c);
	cout << "该三角形的周长为" << tra.length() << endl;
	cout << "该三角形的面积为" << tra.area() << endl;

	system("pause");

	return 0;
}