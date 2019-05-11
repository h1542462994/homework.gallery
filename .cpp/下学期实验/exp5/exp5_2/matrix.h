#include<iostream>
#include<iomanip>
using namespace std;

class matrix
{
public:
    matrix() {}
    friend istream& operator>> (istream& istr, matrix& arg);

    friend ostream& operator<< (ostream& out, const matrix& arg);

    matrix operator + (matrix other);

    matrix operator - (matrix other);

private:
    int content[6] = { 0 };
};
