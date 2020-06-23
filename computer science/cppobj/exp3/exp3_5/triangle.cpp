#include "triangle.h"
#include<cmath>

triangle::triangle(double a, double b, double c) :a(a), b(b), c(c)
{

}

double triangle::area()
{
	double p = get_p();
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double triangle::length()
{
	return a + b + c;
}

double triangle::get_p()
{
	return (a + b + c) / 2;
}
