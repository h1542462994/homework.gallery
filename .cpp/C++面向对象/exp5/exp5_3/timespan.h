#pragma once

typedef long long ld;

class timespan
{
public:
	const static ld TICK_SECOND = 1000;
	const static ld TICK_MINUTE = 60 * TICK_SECOND;
	const static ld TICK_HOUR = 60 * TICK_MINUTE;
	const static ld TICK_DAY = 24 * TICK_HOUR;
	const static ld TICK_NORMAL_YEAR = 365 * TICK_DAY;
	timespan();
	timespan(ld tick);

#pragma region 工厂函数
	static timespan fromdays(int days);
	static timespan fromhours(int hours);
	static timespan fromminutes(int minutes);
	static timespan fromseconds(int seconds);
#pragma endregion

	double gettotaldays() const;
	double gettotalhours() const;
	double gettotalminutes() const;
	int gettotalseconds() const;

	ld tick()  const { return _tick; }

#pragma region 操作符
	bool operator == (const timespan other)
	{
		return _tick == other._tick;
	}
	bool operator < (const timespan other)
	{
		return _tick < other._tick;
	}
	bool operator > (const timespan other)
	{
		return _tick > other._tick;
	}
#pragma endregion
private:
	ld _tick = 0;
};