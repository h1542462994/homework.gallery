#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct employee
{
	string id;
	string name;
	int age;
	int wages;
};

ostream& operator << (ostream& output, const employee& obj)
{
	output << "号码:" << obj.id << endl
		<< "姓名:" << obj.name << endl
		<< "年龄:" << obj.age << endl
		<< "工资:" << obj.wages << endl;
	return output;
}

void setf_employee(fstream& f, const employee& obj)
{
	f << obj.id << " " << obj.name << " " << obj.age << " " << obj.wages << endl;
}

istream& operator >> (istream& input, employee& obj)
{
	input >> obj.id >> obj.name >> obj.age >> obj.wages;
	return input;
}

int main()
{
	cout << "简要员工系统" << endl
		<< "正在向文件中写入5位员工的信息" << endl;

	employee es[7] = { {"10000","Zhang-San",32,3600},
	{"10001","Li-Si",28,5400},
	{"10002","Wang-Wu",41,8000},
	{"10003","Qian-Liu",21,2000},
	{"10004","Su-Qi",52,10000} };

	fstream f;
	f.open("test_a.txt", ios::out);
	for (int i = 0; i < 5; i++)
	{
		setf_employee(f, es[i]);
	}
	f.close();

	cout << "请输入两位员工的信息 包括员工号(请输入大于10004的员工号),姓名,年龄,工资:" << endl;

	for (int i = 0; i < 2; i++)
	{
		cin >> es[5 + i];
	}

	cout << "正在向文件末尾写入2位员工的信息:" << endl;

	f.open("test_a.txt", ios::app);
	for (int i = 0; i < 2; i++)
	{
		setf_employee(f, es[5 + i]);
	}
	f.close();

	int index = 0;
	f.open("test_a.txt", ios::in);
	cout << "正在读取文件中的信息." << endl;
	while (f >> es[index] && !f.eof())
	{

		index++;
	}

	for (int i = 0; i < index; i++)
	{
		cout << es[i] << endl;
	}
	f.close();

	
	cout << "请输入你想查询的号码,输入(0)中止:" << endl;
	string _id;
	while (cin >> _id && _id != "0")
	{
		bool flag = false;
		for (int i = 0; i < 7; i++)
		{
			if (es[i].id == _id)
			{
				cout << "此员工是第" << _id << "个员工，员工信息为" << endl
					<< es[i] << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << "无此人" << endl;
		}
	}

	//system("pause");
	return 0;
}
