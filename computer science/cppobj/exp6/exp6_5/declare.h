#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
public:
    Vehicle(int speedLimit,double weight):speedLimit(speedLimit),weight(weight)
    {
    }
    void beep();
    virtual void show();
private:
    int speedLimit;
    double weight;

};

class Bicycle:public virtual Vehicle
{
public:
    Bicycle(int speedLimit,double weight,double height):Vehicle(speedLimit,weight),height(height)
    {
    }
    void beep();
    virtual void show() override;
private:
    double height;
};

class Motor_veh :public virtual Vehicle
{
public:
    Motor_veh(int speedLimit,double weight,int pLimit):Vehicle(speedLimit,weight),pLimit(pLimit)
    {
    }
    void beep();
    virtual void show();
private:
    int pLimit;
};

class Motorcycle :public virtual Bicycle, public virtual Motor_veh
{
public:
    Motorcycle(int speedLimit,double weight,double height,int pLimit)
        :Bicycle(speedLimit,weight,height),
        Motor_veh(speedLimit,weight,pLimit),
        Vehicle(speedLimit,weight)
    {
    }
    void beep();

    virtual void show() override ;
private:

};