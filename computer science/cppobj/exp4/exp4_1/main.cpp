#include<iostream>
#include"Student.h"
using namespace std;

//@entrypoint
int main()
{
    Student stud(101,78.5);
    Student* p = &stud;
    p->display();
    p->change(101,80.5);
    p->display();

    return 0;
}