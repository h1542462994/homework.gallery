#include<iostream>
#include<string>
#include"declare.h"
using namespace std;

void Employee::display() 
{
    cout << "id=" << id << endl
        << "name=" << name << endl
        << "salary=" << salary << endl;
}

void Manager::pay() 
{
    salary = 5000;
}

void Manager::display() 
{
    cout << "type=" << "Manager" << endl;
    Employee::display();
}

void Manager::setState() 
{
    cout << "请输入经理的id和name:" << endl;
    cin >> id >> name;
}

void Technician::pay() 
{
    salary = 100 * time;
}

void Technician::display()
{
    cout << "type=" << "Technician" << endl;
    Employee::display();
    cout << "time=" << time << endl;
}

void Technician::setState()
{
    cout << "请输入技术人员的id,name以及time:" << endl;
    cin >> id >> name >> time;
}

void Salesman::pay()
{
    salary = sale * 0.07;
}

void Salesman::display()  
{
    cout << "type=" << "Salesman" << endl;
    Employee::display();
    cout << "sale=" << sale << endl;
}

void Salesman::setState()
{
    cout << "请输入销售员的id,name和sale" << endl;
    cin >> id >> name >> sale;
}

void SalesManager::pay()
{
    salary = 8000 + sale * 0.07 + teamsale * 0.002;
}

void SalesManager::display() 
{
    cout << "type=" << "SalesManager" << endl;
    Employee::display();
    cout << "sale=" << sale << endl
        << "teamsale=" << teamsale << endl;
}

void SalesManager::setState()
{
    cout << "请输入销售经理的id,name,sale和teamsale" << endl;
    cin >> id >> name >> sale >> teamsale;
}