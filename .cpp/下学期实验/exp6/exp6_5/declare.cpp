#include<iostream>
#include<string>
#include"declare.h"
using namespace std;

void Vehicle::beep() 
{
    cout << "A Vehicle is runing!" << endl;
}

void Vehicle::show() 
{
    beep();
    cout << "MaxSpeed=" << speedLimit << endl
        << "Weight=" << weight << endl;
}

void Bicycle::beep()  
{
    cout << "A Bicycle is running!" << endl;
}

void Bicycle::show() 
{
    beep();
    Vehicle::show();
    cout << "Height=" << height << endl;
}

void Motor_veh::beep() 
{
    cout << "A Motor_veh is running!" << endl;
}

void Motor_veh:: show()
{
    beep();
    Vehicle::show();
    cout << "seatNumber=" << pLimit << endl;
}

void Motorcycle::beep()
{
    cout << "A Motorcycle is running!" << endl;
}

void Motorcycle::show()  
{
    beep();
    Motor_veh::show();
    cout << "Ennnnnnnn, a little fast?" << endl; 
}