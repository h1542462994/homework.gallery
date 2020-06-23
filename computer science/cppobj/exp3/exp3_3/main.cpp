#include<iostream>
#include<cstdlib>
#include<string>
#include"student.h"
using namespace std;

int main() 
{
	cout << "现在是录入数据阶段，请输入学生数据(id,name,eng_grade,lisanmath_grade,cpp_grade)，直到输入为零:" << endl;
	student arr_stu[100];
	int len = 0;
	do
	{
		student stu;
		cout << "请输入第" << (len + 1) << "个学生的数据:";
		if (stu.set_stu_inf())
		{
			if (stu.get_stu_num() > 0)
			{
				arr_stu[len] = stu;
				len++;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "录入失败，请重新输入" << endl;
		}
	} while (true);

	//arr_stu[0] = student(1, "张三", 56, 78, 98);
	//arr_stu[1] = student(2, "李四", 92, 78, 46);
	//arr_stu[2] = student(3, "王五", 87, 94, 78);
	//len = 3;


	cout << "录入成功" << endl;

	string cmd;
	while (true)
	{
		cout << "请输入命令(exit:退出,detail:输出细节和统计部分,find:查询)" << endl;
		getline(cin, cmd);

		if (cmd == "exit")
		{
			break;
		}
		else if (cmd == "detail")
		{

			cout << "===========输出细节部分===========" << endl;
			for (int i = 0; i < len; i++)
			{
				cout << "id:" << arr_stu[i].get_stu_num() << " sum:" << arr_stu[i].sum() << " average:" << arr_stu[i].average() << endl;;
			}
			cout << "===========统计部分===============" << endl;
			student *stu_max_eng = max_eng(arr_stu, len);
			cout << "英语成绩最高的学生的信息:";
			stu_max_eng->print();
			cout << endl;

			student *stu_max_lisanmath = max_lisanmath(arr_stu, len);
			cout << "离散数学最高的学生的信息:";
			stu_max_lisanmath->print();
			cout << endl;

			student *stu_max_cpp = max_cpp(arr_stu, len);
			cout << "C++最高的学生的信息:";
			stu_max_cpp->print();
			cout << endl;

			student *stu_max_sum = max_sum(arr_stu, len);
			cout << "总分最高的学生的信息:";
			stu_max_sum->print();
			cout << endl;

			double ave_all = get_ave_all(arr_stu, len);
			cout << "全班的平均分为:" << ave_all << endl
				<< "其中低于平均分的学生信息为:" << endl;
			for (int i = 0; i < len; i++)
			{
				if (arr_stu[i].sum() < ave_all)
				{
					arr_stu[i].print();
					cout << endl;
				}
			}
		}
		else if (cmd == "find")
		{
			cout << "请输入要查询的学号:";
			int searchkey;

			cin >> searchkey;

			int i = 0;
			for (i = 0; i < len; i++)
			{
				if (arr_stu[i].get_stu_num() == searchkey)
				{
					cout << "该学生的信息为:";
					arr_stu[i].print();
					cout << endl;
					break;
				}
			}
			if ( i == len)
			{
				cout << "未找到该学生的信息" << endl;
			}
		}
		else
		{
			cout << "Command Not Found Exception" << endl;
			continue;
		}


		cin.clear();
		cin.ignore(1000, '\n');
	}

	system("pause");
	return 0;
}