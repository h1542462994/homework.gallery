#include<iostream>
using namespace std;

bool isleapyear(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else if (year % 100 == 0)
	{
		return false;
	}
	else if (year % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cout << "这是一个给出某一月有几天的小程序。" << endl
		<< "现在，请你输入[年份]和[月份]：";
	int year, month, days;
	cin >> year >> month;
	bool isinvalid = false;
	if (month <= 0 || month > 12)
	{
		cout << "something unexpected happend:you month is out of the valid range." << endl;
		isinvalid = true;
	}
	if (!isinvalid)
	{
		switch (month)
		{
		case 2:
			if (isleapyear(year))
			{
				days = 29;
			}
			else
			{
				days = 28;
			}
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31; break;
		default:
			days = 30; break;
		}

		cout << year << '-' << month << ':' << days;
	}

	return 0;
}