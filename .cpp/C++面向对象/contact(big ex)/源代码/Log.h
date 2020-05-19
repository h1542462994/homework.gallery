#pragma once
#include<iostream>
#include"consolecolor.h"

using namespace std;

class Log
{
public:
	template<typename T>
	static void w(T warning)
	{
		cout << consoleforecolor::yellow << warning << endl
			<< consoleforecolor::normal;
	}
	template<typename T>
	static void e(T error) 
	{
		cout << consoleforecolor::red << error << endl
			<< consoleforecolor::normal;
	}
	template<typename T>
	static void i(T info)
	{
		cout << consoleforecolor::seablue << info << endl
			<< consoleforecolor::normal;
	}

	template<typename T>
	static void d(T debug)
	{
		cout << consoleforecolor::normal << debug << endl;
	}

};