#pragma once
#include"datetime.h"

//表示一次停车
class park 
{
public:
	park() 
	{

	}
	park(datetime start,datetime end)
	{
		this->start = start;
		this->end = end;
	}
	
	double getpayment() 
	{
		double hours = (end - start).gettotalhours();
		if (start >= end)
		{
			return -1;
		}
		else if(hours <= 48)
		{
			if (hours <= 1.0)
			{
				return 4.5;
			}
			else
			{
				return 4.5 + ceil((hours - 1.0) * 2) / 2.0 * 6;
			}
		}
		else
		{
			return 286.5 + ceil((hours - 48)) * 12;
		}
	}
	

	datetime start;
	datetime end;
private:
	
};