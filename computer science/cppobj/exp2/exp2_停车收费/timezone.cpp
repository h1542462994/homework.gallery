#include "timezone.h"

timezone::timezone(int offset)
{
	_offset = offset;
}

timezone timezone::current()
{
	tm *a = new tm();
	time_t t = time(NULL);
	localtime_s(a, &t);
	int local = a->tm_mday * 24 + a->tm_hour;
	gmtime_s(a, &t);
	int gm = a->tm_mday * 24 + a->tm_hour;

	return timezone(local - gm);
}
