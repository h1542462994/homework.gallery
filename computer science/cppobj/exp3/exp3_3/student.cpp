#include"student.h"
#include<iostream>
#include<sstream>
using namespace std;

student *max_eng(student * arr_stu, int length)
{
	int maxindex = 0;
	for (int i = 1; i < length; i++)
	{
		if (arr_stu[i].get_eng_grade() > arr_stu[maxindex].get_eng_grade())
		{
			maxindex = i;
		}
	}
	return &arr_stu[maxindex];
}
student *max_lisanmath(student * arr_stu, int length)
{
	int maxindex = 0;
	for (int i = 1; i < length; i++)
	{
		if (arr_stu[i].get_lisanmath_grade() > arr_stu[maxindex].get_lisanmath_grade())
		{
			maxindex = i;
		}

	}
	return &arr_stu[maxindex];
}
student *max_cpp(student * arr_stu, int length)
{
	int maxindex = 0;
	for (int i = 1; i < length; i++)
	{
		if (arr_stu[i].get_cpp_grade() > arr_stu[maxindex].get_cpp_grade())
		{
			maxindex = i;
		}

	}
	return &arr_stu[maxindex];
}
student *max_sum(student * arr_stu, int length)
{
	int maxindex = 0;
	for (int i = 1; i < length; i++)
	{
		if (arr_stu[i].sum() > arr_stu[maxindex].sum())
		{
			maxindex = i;
		}
	}
	return &arr_stu[maxindex];
}

double get_ave_all(student *arr_stu, int length)
{
	double sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr_stu[i].sum();
	}
	return (sum / length);
}

double student::sum()
{
	return eng_grade + lisanmath_grade + cpp_grade;
}

double student::average()
{
	return sum() / 3;
}

void student::print()
{
	cout << "id:" << id << " name:" << name << " eng_grade:" << eng_grade << " lisanmath_grade:" << lisanmath_grade << " cpp_grade" << cpp_grade;
}

bool student::set_stu_inf()
{
	string line;
	getline(cin, line);
	
	istringstream istr(line);

	istr >> id;
	if (id != 0)
	{
		istr >> name >> eng_grade >> lisanmath_grade >> cpp_grade;
	}

	if (istr.fail())
	{
		return false;
	}

	return true;
	//cin.ignore(1000, '\n');
}
