#include<iostream>
#include<vcruntime.h>
using namespace std;

class Felid {
public:
    Felid()
    {

        cout << "Felid constructor." << endl;
    }
    virtual ~Felid()
    {
        cout << "Felid destructor." << endl;
    }
    virtual void sound() const
    {
        cout << "Felid sound!" << endl;
    }

};

class Cat :public Felid
{
public:
    Cat()
    {
        cout << "Cat constructor." << endl;
    }


    ~Cat()
    {
        cout << "Cat destructor." << endl;
    }
    void sound() const
    {
        cout << "Maiow !" << endl;
    }
protected:

};

class Leopard :public Felid
{
public:
    Leopard()
    {

        cout << "Leopard constructor." << endl;
    }
    ~Leopard()
    {
        cout << "Leopard destructor." << endl;
    }
    void sound() const
    {
        cout << "How!!" << endl;
    }
};

int main()
{
    Felid* animal = NULL;
    animal = new Cat;
    animal->sound();
    delete animal;

    animal = new Leopard;
    animal->sound();
    delete animal;

    return 0;
}