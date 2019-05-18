#include"declare.h"
#include<iostream>
using namespace std;

int main()
{
    Professor pr(10000, "zs", 'M', BirthDate(1999, 4, 2));
    pr.display();
    pr.setBirthday(BirthDate(2000, 5, 12));
    pr.display();

    return 0;
}