#pragma once
#include<iostream>
using namespace std;

enum class dayofweek
{
	Sunday = 0,
	Monday = 1,
	Tuesday = 2,
	Wednesday = 3,
	Thursday = 4,
	Friday = 5,
	Saturday = 6
};

//ostream & operator << (ostream & outstr, dayofweek arg) {
//	string t = "";
//	if (arg == dayofweek::Sunday)
//	{
//		t = "星期天";
//	}
//	else if (arg == dayofweek::Monday)
//	{
//		t = "星期一";
//	}
//	else if (arg == dayofweek::Tuesday)
//	{
//		t = "星期二";
//	}
//	else if (arg == dayofweek::Wednesday)
//	{
//		t = "星期三";
//	}
//	else if (arg == dayofweek::Thursday)
//	{
//		t = "星期四";
//	}
//	else if (arg == dayofweek::Friday)
//	{
//		t = "星期五";
//	}
//	else
//	{
//		t = "星期六";
//	}
//	outstr << t;
//	return outstr;
//}
