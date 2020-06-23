#include<iostream>
#include<string>
#include<vcruntime.h>
#include<Windows.h>
#include<limits>
#include<iomanip>

#include"stu.h"
#include"linklist.h"

using namespace std;

#define setConsoleTextColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | color); 
#define setWhite() setConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
#define setBlue() setConsoleTextColor(FOREGROUND_BLUE);
#define setRed() setConsoleTextColor(FOREGROUND_RED);
#define setGreen() setConsoleTextColor(FOREGROUND_GREEN)
#define setPurple() setConsoleTextColor(FOREGROUND_RED | FOREGROUND_BLUE);
#define setYellow() setConsoleTextColor(FOREGROUND_RED | FOREGROUND_GREEN);
#define setBlueGreen() setConsoleTextColor(FOREGROUND_GREEN | FOREGROUND_BLUE);

void print(stu &);
void print_des();
bool equal_stu(stu &, stu &);
void reset_cin();

int main()
{
	//调用默认构造函数
	linklist list1 = linklist();
	//提示语
	print_des();
	char _str[1000];

	int cmdi = 0;
	while (true)
	{
		if (cmdi == 0)
		{
			setWhite();
			cout << "请输入命令[0~6]:" ;

			int cmd;cin >> cmd;

			setBlue();

			if (cmd == 0)
			{
				cout << "Bye!!" << endl;
				break;
			}
			else
			{
				cmdi = cmd;
			}
		}
		else
		{
			if (cmdi == 1)
			{
				setWhite();
				cout << "请输入添加的数据[学号(int) 姓名(string) 成绩(double)]:";
				//warning.
				stu *stu1 = new stu();
				cin >> *stu1;
				if (cin.fail())
				{
					setRed();
					cout << "输入格式错误" << endl;
					//cmdi = 0;
					//break;
				}
				else
				{
					if (stu1->id > 0)
					{
						list1.add(stu1);
						setBlueGreen();
						cout << "已添加一条数据" << endl;
					}
					else
					{
						setRed();
						cout << "学号需>0" << endl;
					}
				}
			}
			else if (cmdi == 2)
			{
				setWhite();
				cout << "请输入添加的数据[学号(int) 姓名(string) 成绩(double)]，直到输入的学号<0:" << endl;
				int _count = 0; int id;
				do
				{
					cout << ">";
					stu *pstu = new stu();
					cin >> *pstu;
					id = pstu->id;
					if (pstu->id > 0)
					{
						_count++;
						list1.add(pstu);
					}
				} while (id > 0);
				setBlueGreen();
				cout << "已添加" << _count << "条数据" << endl;
			}
			else if (cmdi == 3)
			{
				setWhite();
				cout << "请输入插入的索引及数据[索引(int) 学号(int) 姓名(string) 成绩(double)]:";
				stu *stu1 = new stu(); int index;
				cin >> index >> *stu1;
	
				bool result = list1.insert(stu1, index);
				if (result)
				{
					setBlue();
					cout << "已插入数据" << *stu1;
				}
				else
				{
					setRed();
					cout << "插入数据失败，可能是索引超过了链表的长度导致." << endl;
				}
			}
			else if (cmdi == 4)
			{
				setWhite();
				cout << "请输入要删除的学号[学号(int)]:";
				int id;
				cin >> id;
				if (cin.fail())
				{
					setRed();
					cout << "输入格式错误" << endl;
				}
				else
				{
					stu _stui;
					_stui.id = id;
					setBlue();
					if (list1.length() == 0)
					{
						cout << "空链表" << endl;
					}
					else
					{
						int result = list1.removeAll(&_stui, equal_stu);

						cout << "已删除" << result << "条记录" << endl;
					}
				}


			}
			else if (cmdi == 5)
			{
				setBlue();
				if (list1.length() == 0)
				{
					cout << "空链表" << endl;
				}
				else
				{
					cout << setw(10) <<"id" << setw(10) << "name" << setw(10) << "grade" << endl; 
					list1.forEach(print);
				}
			}
			else
			{
				setRed();
				cout << "无相应的命令" << endl;
			}

			cmdi = 0;
			//清空输入流缓存
			reset_cin();
		}
	}
	setWhite();
	system("pause");
	return 0;
}

void print_char(int count, char c = ' ')
{
	for (int i = 0; i < count; i++)
	{
		cout << c;
	}
}

void print_des()
{
	setYellow();
	print_char(40, '=');
	cout << "链表测试程序";
	print_char(40, '=');
	cout << endl;
	setBlue();
	cout << "Author:cht copyright ZJUT" << endl;
	setBlueGreen();
	print_char(30);
	cout << "【0】退出程序" << endl;
	print_char(30);
	cout << "【1】在末尾添加一条数据" << endl;
	print_char(30);
	cout << "【2】在末尾添加多条数据" << endl;
	print_char(30);
	cout << "【3】在指定索引处插入一条数据" << endl;
	print_char(30);
	cout << "【4】按照学号删除所有匹配的数据" << endl;
	print_char(30);
	cout << "【5】打印所有数据" << endl;
	//print_char(30);
	//cout << "【6】排序链表" << endl;
	setYellow();
	print_char(40, '=');
	cout << "链表测试程序";
	print_char(40, '=');
	cout << endl;
	setWhite();
}

void print(stu & a)
{
	cout << setw(10) << a.id << setw(10) << a.name << setw(10) << a.grade << endl;
}

bool equal_stu(stu & first, stu & second) 
{
	return first.id == second.id;
}

void reset_cin()
{
	cin.clear();
	cin.ignore(1000, '\n');
}

#pragma once

