#include"student.h"

student * student:: max(student * arr_stu, int length)
{
	int maxindex = 0;
	for (int i = maxindex; i < length; i++)
	{
		if (arr_stu[i].grade > arr_stu[maxindex].grade)
		{
			maxindex = i;
		}
	}
	return &arr_stu[maxindex];
}
