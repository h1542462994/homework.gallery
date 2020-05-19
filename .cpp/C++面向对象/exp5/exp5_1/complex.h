#pragma once
#include<iostream>
#include<math.h>
using namespace std;

//simple data class
class complex
{
public:
	complex() :_real(0), _image(0) {}
	complex(double real) :_real(real),_image(0) {}//单参数构造函数兼类型转换构造器。
	complex(double real, double image) :_real(real), _image(image) {}

	//重载流输出运算符.
	friend ostream& operator<< (ostream& out, complex arg);

	friend istream& operator>> (istream& istr, complex& arg);

	friend complex operator + (complex left, complex right);

	friend complex operator - (complex left, complex right);

	friend complex operator * (complex left, complex right);

	friend complex operator / (complex left, complex right);

	complex operator ++();

	complex operator ++(int);

	complex operator -();

	//取复数的共轭复数
	complex getconjugate();

	//取复数的模
	double getmodulus();

	//取复数的模的平方
	double getsqrmodulus();

	double& real() { return _real; };

	double& image() { return _image; };
private:
	double _real;
	double _image;
};