#include<iostream>
#include"complex.h"
using namespace std;

ostream& operator<< (ostream& out,complex arg)
{
	if (arg._image == 0) {
		out << arg._real;
	}
	else if (arg._image > 0)
	{
		if (arg._image == 1) {
			out << arg._real << "+i";
		}
		else
		{
			out << arg._real << "+" << arg._image << "i";
		}
	}
	else
	{
		if (arg._image == -1) {
			out << arg._real << "-i";
		}
		else
		{
			out << arg._real << arg._image << "i";
		}
	}

	return out;
}

istream& operator>> (istream& istr, complex& arg)
{
	//TODO("待完成的部分.")
	return istr;
}

complex operator + (complex left, complex right)
{
	return complex(left._real + right._real, left._image + right._image);
}

complex operator - (complex left, complex right)
{
	return complex(left._real - right._real, left._image - right._image);
}

complex operator * (complex left, complex right)
{
	return complex(left._real * right._real - left._image * right._image,
		left._real * right._image + left._image * right._real);
}

complex operator / (complex left, complex right)
{
	return complex((left._real * right._real + left._image * right._image) / right.getsqrmodulus(),
		(left._image * right._real - left._real * right._image) / right.getsqrmodulus());
}

complex complex::operator ++()
{
	this->_real++;
	return *this;
}

complex complex::operator ++(int)
{
	complex temp = *this;
	this->_real++;
	return temp;
}

complex complex::operator -()
{
	return complex(-this->_real, -this->_image);
}

//取复数的共轭复数
complex complex::getconjugate()
{
	return complex(_real, -_image);
}

//取复数的模
double complex::getmodulus()
{
	return sqrt((double)(_real * _real + _image * _image));
}

//取复数的模的平方
double complex::getsqrmodulus()
{
	return _real * _real + _image * _image;
}