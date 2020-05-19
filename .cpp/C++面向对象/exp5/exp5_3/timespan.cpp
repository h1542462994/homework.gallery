#include "timespan.h"

timespan::timespan()
{
	_tick = 0;
}

timespan::timespan(ld tick)
{
	_tick = tick;
}

timespan timespan::fromdays(int days)
{
	return timespan(days * TICK_DAY);
}

timespan timespan::fromhours(int hours)
{
	return timespan(hours * TICK_HOUR);
}

timespan timespan::fromminutes(int minutes)
{
	return timespan(minutes * TICK_MINUTE);
}

timespan timespan::fromseconds(int seconds)
{
	return timespan(seconds * TICK_SECOND);
}

double timespan::gettotaldays() const
{
	return (double)_tick / TICK_DAY;
}

double timespan::gettotalhours() const
{
	return (double)_tick / TICK_HOUR;
}

double timespan::gettotalminutes() const
{
	return (double)_tick / TICK_MINUTE;
}

int timespan::gettotalseconds() const
{
	return _tick / TICK_SECOND;
}
