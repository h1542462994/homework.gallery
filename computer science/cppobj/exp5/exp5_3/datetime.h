#pragma once
#include"dayofweek.h"
#include"timespan.h"
#include"timezone.h"

using namespace std;

typedef long long ld;

class datetime
{
public:
	const static ld TICK_SECOND = 1000;
	const static ld TICK_MINUTE = 60 * TICK_SECOND;
	const static ld TICK_HOUR = 60 * TICK_MINUTE;
	const static ld TICK_DAY = 24 * TICK_HOUR;
	const static ld TICK_NORMAL_YEAR = 365 * TICK_DAY;

#pragma region 构造函数
	datetime();
	datetime(int hour, int minute, int second);
	datetime(int hour, int minute, int second, int millisecond);
	datetime(ld tick);
	datetime(int year, int month, int day, int hour, int minute, int second);
#pragma endregion

	//获取现在的时间，为完善这个类，需要添加时区的概念。
	static datetime now();
#pragma region 解析字符串
	//解析时间字符串，当解析不成功时，将返回默认的值。
	static datetime parse(string format);
	static bool tryparse(string format, datetime* out);
#pragma endregion
#pragma region 获取属性
	ld tick() { return _tick; }
	int getyear() const;
	int getmonth() const;
	int getday() const;
	int gethour() const;
	int getminute() const;
	int getsecond() const;
	dayofweek getdayofweek() const;
	//获取日期时间的日期部分
	datetime getdate() const;
	//获取日期时间的时间部分
	datetime gettime() const;
#pragma endregion

#pragma region 格式字符串的输出
	//本地时间 format:"YYYY/MM/DD HH:MM:SS"
	string to_localtimestring() const;
	//长时间 format:"YYYY年MM月DD日 HH:MM:SS"
	string to_longtimestring() const;
	//短时间 format:"HH:MM:SS"
	string to_shorttimestring() const;

	friend ostream& operator << (ostream& out,const datetime& arg)
	{
		out << arg.to_shorttimestring() ;
		return out;
	}
	friend istream& operator >> (istream& istr,datetime& arg)
	{
		string t;
		istr >> t;
		datetime td = datetime::parse(t);
		arg._tick = td._tick;

		return istr;
	}
#pragma endregion

#pragma region 操作符
	timespan operator- (const datetime other)
	{
		return timespan(_tick - other._tick);
	}
	datetime operator+ (const timespan span)
	{
		return datetime(_tick + span.tick());
	}
	datetime operator++ ()
	{
		this->_tick += TICK_SECOND;
		return *this;
	}
	datetime operator++ (int)
	{
		datetime temp = *this;
		this->_tick += TICK_SECOND;
		return temp;
	}

	bool operator == (const datetime other)
	{
		return _tick == other._tick;
	}
	bool operator <= (const datetime other)
	{
		return _tick <= other._tick;
	}
	bool operator < (const datetime other)
	{
		return _tick < other._tick;
	}
	bool operator >= (const datetime other)
	{
		return _tick >= other._tick;
	}
	bool operator > (const datetime other)
	{
		return _tick > other._tick;
	}

	bool equals(const datetime& other);
#pragma endregion

private:
	//约定_tick=0对应1970/01/01 00:00:00(UTC时间)
	ld _tick = 0;
	void getdetail(int *year, int *month, int *day, int *hour, int *minute, int *second, int *millisecond) const;
	static bool isleapyear(int year);
	static bool isdatevalid(int year, int month, int day);
	static bool istimevalid(int hour, int minute, int second);

	static ld caculatedays(int year, int month, int day);
	static void getdatefromdays(int days, int *year, int *month, int *day);
	static void gettimefromtick(int tick, int *hour, int *minute, int *second, int *millisecond);
};
