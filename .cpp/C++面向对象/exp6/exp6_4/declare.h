#include<iostream>
#include<string>

using namespace std;

class Teacher
{
public:
    Teacher(int num, string name, char sex)
        :num(num), name(name), sex(sex) {}
    void display();

private:
    int num;
    string name;
    char sex;
};

class BirthDate
{
public:
    BirthDate() :year(1970), month(1), day(1) {}
    BirthDate(int year, int month, int day) :year(year), month(month), day(day) {}
    void display();

private:
    int year;
    int month;
    int day;
};

class Professor :public Teacher
{
public:
    Professor(int num, string name, char sex, BirthDate birthday)
        :Teacher(num, name, sex), birthday(birthday) {}
    void setBirthday(BirthDate birthday);
    void display();
    BirthDate getBirthday();
private:
    BirthDate birthday;
};