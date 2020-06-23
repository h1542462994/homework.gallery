#include<iostream>
#include<vcruntime.h>
using namespace std;

class Vehicle
{
public:
    Vehicle(int speedLimit = 120, int seatCount = 2)
    {
        this->speedLimit = speedLimit;
        this->seatCount = seatCount;
        cout << "Vehicle constructor." << endl;
    }

    virtual ~Vehicle()
    {
        cout << "Vehicle destructor." << endl;
    }

    virtual void display() const = 0;
protected:
    int speedLimit; //限速
    int seatCount; //座位数量
};

class Car :public Vehicle
{
public:
    Car(int speedLimit = 120, int seatCount = 2, bool isAuto = true) :Vehicle(speedLimit, seatCount)
    {
        this->isAuto = isAuto;
    }

    virtual ~Car() override
    {
        cout << "Car destructor." << endl;
    }

    virtual void display() const override
    {
        cout << "A car is runing!" << endl;
        cout << "speedLimit = " << speedLimit << ",seatCount = " << seatCount << ",isAuto = " << isAuto << endl;
    }

protected:
    bool isAuto; //是否是自动挡
};

class Truck :public Vehicle
{
public:
    Truck(int speedLimit = 100, int seatCount = 2, double deadweight = 5) :Vehicle(speedLimit, seatCount)
    {
        this->deadweight = deadweight;
        cout << "Truck constructor." << endl;
    }
    virtual ~Truck() override
    {
        cout << "Truck destructor." << endl;
    }

    virtual void display() const override
    {
        cout << "A truck is running!" << endl;
        cout << "speedLimit = " << speedLimit << ",seatCount = " << seatCount << ",deadweight = " << deadweight << endl;
    }
protected:
    double deadweight; //载重量(吨)
};

class Boat :public Vehicle
{
public:
    Boat(int speedLimit = 72, int seatCount = 12, int eatHeight = 6) :Vehicle(speedLimit, seatCount)
    {
        this->eatHeight = eatHeight;
        cout << "Boat constructor" << endl;
    }

    virtual ~Boat() override
    {
        cout << "Boat destructor." << endl;
    }

    virtual void display() const override
    {
        cout << "A boat is runing!" << endl;
        cout << "speedLimit = " << speedLimit << ",seatCount = " << seatCount << ",eatHeight = " << eatHeight << endl;
    }
protected:

    double eatHeight; //吃水深度(m)
};

int main()
{
    Vehicle* pv = NULL;
    pv = new Car();
    pv->display();
    delete pv;
    
    pv = new Truck();
    pv->display();
    delete pv;

    pv = new Boat();
    pv->display();
    delete pv;

    return 0;
}