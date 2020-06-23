#pragma once
#include<ctime>

//时区
class timezone 
{
public:
	timezone(int offset);
	static timezone current();
	int offset() 
	{
		return _offset;
	}

private:
	//时区
	int _offset;
};