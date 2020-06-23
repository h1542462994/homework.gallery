#include "datetime.h"

#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<stdio.h>
#include<regex>


datetime::datetime()
{
	_tick = 0;
}

datetime::datetime(int hour, int minute, int second)
{
	if (istimevalid(hour, minute, second))
	{
		_tick = hour * TICK_HOUR + minute * TICK_MINUTE + second * TICK_SECOND;
		_tick -= timezone::current().offset() * TICK_HOUR;
	}
}

datetime::datetime(int hour, int minute, int second, int millisecond) :datetime(hour, minute, second)
{
	if (millisecond >= 0 && millisecond < 1000)
	{
		_tick += millisecond;
	}
	else
	{
		_tick = 0;
	}
}

datetime::datetime(ld tick)
{
	_tick = tick;
}

datetime::datetime(int year, int month, int day, int hour, int minute, int second) :datetime(hour, minute, second)
{
	if (year >= 1970 && isdatevalid(year, month, day))
	{
		_tick += caculatedays(year, month, day) * TICK_DAY;
	}
	else
	{
		_tick = 0;
	}
}

//获取现在的时间，为完善这个类，需要添加时区的概念。
datetime datetime::now()
{
	return datetime(time(NULL) * TICK_SECOND);
}

//解析时间字符串，当解析不成功时，将返回默认的值。
datetime datetime::parse(string format)
{
	//YYYY/MM/DD HH:MM:SS
	istringstream istr(format);
	int year, month, day, hour, minute, second;

	smatch m;
	if (regex_match(format, m, regex("(\\d{1,4})/(\\d{1,2})/(\\d{1,2}) (\\d{1,2}):(\\d{1,2}):(\\d{1,2})")))
	{
		sscanf_s(format.c_str(), "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
		return datetime(year, month, day, hour, minute, second);
	}
	else if (regex_match(format, m, regex("(\\d{1,2}):(\\d{1,2}):(\\d{1,2})")))
	{
		sscanf_s(format.c_str(), "%d:%d:%d", &hour, &minute, &second);
		return datetime(hour, minute, second);
	}
	return datetime();
}

bool datetime::tryparse(string format, datetime * out)
{
	//YYYY/MM/DD HH:MM:SS
	istringstream istr(format);
	int year, month, day, hour, minute, second;

	smatch m;
	if (regex_match(format, m, regex("(\\d{1,4})/(\\d{1,2})/(\\d{1,2}) (\\d{1,2}):(\\d{1,2}):(\\d{1,2})")))
	{
		sscanf_s(format.c_str(), "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
		*out = datetime(year, month, day, hour, minute, second);
		return true;
	}
	else if (regex_match(format, m, regex("(\\d{1,2}):(\\d{1,2}):(\\d{1,2})")))
	{
		sscanf_s(format.c_str(), "%d:%d:%d", &hour, &minute, &second);
		*out = datetime(hour, minute, second);
		return true;
	}
	return false;
}

int datetime::getyear() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);
	return year;
}

int datetime::getmonth() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);
	return month;
}

int datetime::getday() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);
	return day;
}

int datetime::gethour() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);
	return hour;
}

int datetime::getminute() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);
	return minute;
}

int datetime::getsecond() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);
	return second;
}

dayofweek datetime::getdayofweek() const
{
	int days = _tick / TICK_DAY;
	return (dayofweek)((4 + days) % 7);
}

//获取日期时间的日期部分
datetime datetime::getdate() const
{
	return datetime(_tick - _tick % TICK_DAY);
}

//获取日期时间的时间部分
datetime datetime::gettime() const
{
	return datetime(_tick % TICK_DAY);
}

//本地时间 format:"YYYY/MM/DD HH:MM:SS"
string datetime::to_localtimestring() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);

	ostringstream strx(0);
	strx << year << "/"
		<< setw(2) << setfill('0') << month << "/"
		<< setw(2) << setfill('0') << day << " "
		<< setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << minute << ":"
		<< setw(2) << setfill('0') << second
		<< setfill(' ');

	return strx.str();
}

//长时间 format:"YYYY年MM月DD日 HH:MM:SS"
string datetime::to_longtimestring() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);

	ostringstream strx(0);
	strx << year << "年"
		<< month << "月"
		<< day << "日 "
		<< setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << minute << ":"
		<< setw(2) << setfill('0') << second
		<< setfill(' ');

	return strx.str();
}

//短时间 format:"HH:MM:SS"
string datetime::to_shorttimestring() const
{
	int year, month, day, hour, minute, second, millisecond;
	getdetail(&year, &month, &day, &hour, &minute, &second, &millisecond);

	ostringstream strx(0);
	strx << setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << minute << ":"
		<< setw(2) << setfill('0') << second
		<< setfill(' ');

	return strx.str();
}

void datetime::getdetail(int * year, int * month, int * day, int * hour, int * minute, int * second, int * millisecond) const
{
	ld localtick = _tick + timezone::current().offset() * TICK_HOUR;
	int days = localtick / TICK_DAY;
	getdatefromdays(days, year, month, day);
	gettimefromtick(localtick % TICK_DAY, hour, minute, second, millisecond);
}

bool datetime::isleapyear(int year)
{
	//BUG 计算闰月时忘记加"==0"导致错误。
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

bool datetime::isdatevalid(int year, int month, int day)
{
	int mdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month <= 0 || month > 12)
	{
		return false;
	}
	if (month != 2)
	{
		if (day > 0 && day <= mdays[month - 1])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (isleapyear(year) && day > 0 && day <= 29)
		{
			return true;
		}
		else if (day > 0 && day <= 28)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

ld datetime::caculatedays(int year, int month, int day)
{
	int circle_short = (year - 1970) / 4;
	int rem_short = (year - 1970) % 4;
	//int rem_end = year - rem_short;
	//int rem_start = 1970 + rem_short;

	//----计算年的部分
	//4年一个循环
	ld days = circle_short * (365 * 3 + 366);
	//加上最开始几年的天数
	if (rem_short == 1)
	{
		days += 365;
	}
	else if (rem_short == 2)
	{
		days += 2 * 365;
	}
	else if (rem_short == 3)
	{
		days += 2 * 365 + 366;
	}

	int yh = (year - 1) / 100;
	if (yh >= 20)
	{
		days -= (yh - 20);
		days += (yh - 20) / 4;
	}

	//----计算剩余的月的部分
	int mdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < month - 1; i++)
	{
		days += mdays[i];
	}
	//算上闰年的部分
	if (isleapyear(year) && month >= 3)
	{
		days += 1;
	}
	days += day - 1;

	//ld days = time(NULL) / 3600 / 24;

	return days;
}

void datetime::getdatefromdays(int days, int * year, int * month, int * day)
{
	//四年的循环个数
	int circle_short = days / (365 * 3 + 366);
	int rem_short = days % (365 * 3 + 366);

	int t_year = 1970 + circle_short * 4;

	//调整偏差。
	int yh = (t_year - 1) / 100;
	if (yh >= 20)
	{
		rem_short += (yh - 20);
		rem_short -= (yh - 20) / 4;
	}
	rem_short++;
	//rem_short += ((t_year / 100 - 20) / 4) * 3 + ((t_year / 100 - 20) % 4);
	int ydays[] = { 365,365,366,365 };
	int i = 0;
	while (rem_short > ydays[i])
	{
		rem_short -= ydays[i];
		t_year++;
		i++;
	}


	//---继续算月份
	int mdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//调整天数
	if (isleapyear(t_year))
	{
		mdays[1] = 29;
	}
	int t_month = 1; int t_day = 1;
	while (rem_short > mdays[t_month - 1] && t_month < 12)
	{
		rem_short -= mdays[t_month - 1];
		t_month++;
	}

	t_day = rem_short;

	//传出处理结果
	*year = t_year; *month = t_month; *day = t_day;
}

void datetime::gettimefromtick(int tick, int * hour, int * minute, int * second, int * millisecond)
{
	*millisecond = (int)(tick % TICK_SECOND);
	tick -= *millisecond;
	*second = (int)(tick % TICK_MINUTE) / TICK_SECOND;
	tick -= *second * TICK_SECOND;
	*minute = (int)(tick % TICK_HOUR) / TICK_MINUTE;
	//BUG 错把minute写成second导致错误。
	tick -= *minute * TICK_MINUTE;
	*hour = (int)(tick % TICK_DAY) / TICK_HOUR;
}
