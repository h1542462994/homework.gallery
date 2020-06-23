#include"declare.h"

void Teacher::display()
{
    cout << "num:" << num << endl
        << "name:" << name << endl
        << "sex" << sex << endl;
}

void BirthDate::display()
{
    cout << year << "/" << month << "/" << day;
}

void Professor::setBirthday(BirthDate birthday)
{
    this->birthday = birthday;
}

void Professor::display()
{
    Teacher::display();
    cout << "birthday:";
    birthday.display();
    cout << endl;
}

BirthDate Professor::getBirthday()
{
    return birthday;
}