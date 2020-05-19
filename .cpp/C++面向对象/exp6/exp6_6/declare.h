#include<iostream>
#include<string>
using namespace std;

class Employee 
{
public:
    virtual void pay() = 0;
    virtual void display();
    virtual void setState() = 0;
protected:
    Employee():id(""),name(""),salary(0){}
    //只允许继承类初始化。
    Employee(string id,string name):id(id),name(name),salary(0){}
    string id;
    string name;
    double salary;
};

class Manager:public virtual Employee
{
public:
    Manager():Employee(){}
    Manager(string id,string name):Employee(id,name){}
    virtual void pay() override ;
    virtual void display() override ;
    virtual void setState() override ;
protected:
};

class Technician:public virtual Employee
{
public:
    Technician():Employee(),time(0){}
    Technician(string id,string name,double time):Employee(id,name),time(time){}
    virtual void pay() override ;
    virtual void display() override;
    virtual void setState() override;
protected:
    double time;
};

class Salesman:public virtual Employee
{
public:
    Salesman():Employee(),sale(0){}
    Salesman(string id,string name,double sale):Employee(id,name),sale(sale){}
    virtual void pay() override;
    virtual void display() override ;
    virtual void setState() override;
protected:
    double sale;
};

class SalesManager :public virtual Salesman 
{
public:
    SalesManager():Salesman(),Employee(),teamsale(0){}
    SalesManager(string id,string name,double sale,double teamsale)
        :Salesman(id,name,sale),Employee(id,name),teamsale(teamsale){}
    virtual void pay() override;
    virtual void display() override;
    virtual void setState() override;
protected:
    double teamsale;
};