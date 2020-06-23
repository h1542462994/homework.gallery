#include<iostream>
#include<string>
#include"declare.h"
using namespace std;

void Teacher::display()
{
    cout << "name:" << name << endl
        << "age:" << age << endl
        << "sex:" << sex << endl
        << "address:" << address << endl
        << "phone:" << phone << endl
        << "title" << title << endl;
}

void Cadre::display()
{
    cout << "name:" << name << endl
        << "age:" << age << endl
        << "sex:" << sex << endl
        << "address:" << address << endl
        << "phone:" << phone << endl
        << "post" << post << endl;
}


void Teacher_Cadre::display()
{
    Teacher::display();
    cout << "post:" << post << endl
        << "wages:" << wages << endl;
}