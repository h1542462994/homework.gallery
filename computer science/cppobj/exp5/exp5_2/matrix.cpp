#include<iostream>
#include"matrix.h"
using namespace std;

istream& operator>> (istream& istr,matrix& arg)
{
    for (int i = 0; i < 6; i++)
    {
        istr >> arg.content[i];
    }

    return istr;
}

ostream& operator<< (ostream& out, const matrix& arg)
{
    for (int i = 0; i < 3; i++)
    {
        out << setw(5) << arg.content[i];
    }
    out << endl;
    for (int i = 0; i < 3; i++)
    {
        out << setw(5) << arg.content[3 + i];
    }

    return out;
}

matrix matrix::operator+ (matrix other)
{
    matrix result;
    for (int i = 0; i < 6; i++)
    {
        result.content[i] = content[i] + other.content[i];
    }

    return result;
}

matrix matrix::operator- (matrix other)
{
    matrix result;
    for (int i = 0; i < 6; i++)
    {
        result.content[i] = content[i] - other.content[i];
    }

}