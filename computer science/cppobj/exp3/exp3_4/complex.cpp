#include "complex.h"
#include<iostream>
using namespace std;

complex::complex(double real, double image) :real(real), image(image)
{
	cout << "Call constructor" << endl;
}

complex::complex(const complex & obj)
{
	real = obj.real;
	image = obj.image;
	cout << "Call copy constructor" << endl;
}

complex::~complex()
{
	cout << "Call destructor" << endl;
}

void complex::display()
{
	if (image == 0)
	{
		cout << real << endl;
	}
	else if (real == 0)
	{
		cout << image << "i" << endl;
	}
	else
	{
		if (image > 0)
		{
			cout << real << "+" << image << "i" << endl;
		}
		else
		{
			cout << real << image << "i" << endl;
		}
	}
}
