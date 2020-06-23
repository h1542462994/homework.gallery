#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
    Teacher(string name, int age, char sex, string address, string phone, string title) 
        :name(name), age(age), sex(sex), address(address), phone(phone), title(title) {}
    void display();
protected:
    string name;
    int age;
    char sex;
    string address;
    string phone;
    string title;
};



class Cadre 
{
public:
    Cadre(string name,int age,char sex,string address,string phone,string post)
        :name(name),age(age),sex(sex),address(address),phone(phone),post(post){}
    void display();
protected:
    string name;
    int age;
    char sex;
    string address;
    string phone;
    string post;
};



class Teacher_Cadre:public Teacher,public Cadre
{
public:
    Teacher_Cadre(string name, int age, char sex, string address, string phone, string title,string post,int wages)
        :Teacher(name,age,sex,address,phone,title),
        Cadre(name,age,sex,address,phone,post),
        wages(wages){}
    void display();
protected:
    int wages;
};