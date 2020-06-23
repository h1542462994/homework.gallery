#include<iostream>
#include<cstdlib>
#include"student.h"
using namespace std;




int main()
{
	student stu[5] = 
	{
		student(1,81),
		student(2,74),
		student(3,85),
		student(4,94),
		student(5,64)
	};

	student *max_stu = student::max(stu, 5);
	student *max_stu = stu[1].max(stu, 5);
	
	cout << "id:" << max_stu->id << " grade:" << max_stu->grade << endl;

	system("pause");
	return 0;
}