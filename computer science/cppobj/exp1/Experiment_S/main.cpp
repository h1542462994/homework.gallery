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
	//����Ĭ�Ϲ��캯��
	linklist list1 = linklist();
	//��ʾ��
	print_des();
	char _str[1000];

	int cmdi = 0;
	while (true)
	{
		if (cmdi == 0)
		{
			setWhite();
			cout << "����������[0~6]:" ;

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
				cout << "��������ӵ�����[ѧ��(int) ����(string) �ɼ�(double)]:";
				//warning.
				stu *stu1 = new stu();
				cin >> *stu1;
				if (cin.fail())
				{
					setRed();
					cout << "�����ʽ����" << endl;
					//cmdi = 0;
					//break;
				}
				else
				{
					if (stu1->id > 0)
					{
						list1.add(stu1);
						setBlueGreen();
						cout << "�����һ������" << endl;
					}
					else
					{
						setRed();
						cout << "ѧ����>0" << endl;
					}
				}
			}
			else if (cmdi == 2)
			{
				setWhite();
				cout << "��������ӵ�����[ѧ��(int) ����(string) �ɼ�(double)]��ֱ�������ѧ��<0:" << endl;
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
				cout << "�����" << _count << "������" << endl;
			}
			else if (cmdi == 3)
			{
				setWhite();
				cout << "��������������������[����(int) ѧ��(int) ����(string) �ɼ�(double)]:";
				stu *stu1 = new stu(); int index;
				cin >> index >> *stu1;
	
				bool result = list1.insert(stu1, index);
				if (result)
				{
					setBlue();
					cout << "�Ѳ�������" << *stu1;
				}
				else
				{
					setRed();
					cout << "��������ʧ�ܣ���������������������ĳ��ȵ���." << endl;
				}
			}
			else if (cmdi == 4)
			{
				setWhite();
				cout << "������Ҫɾ����ѧ��[ѧ��(int)]:";
				int id;
				cin >> id;
				if (cin.fail())
				{
					setRed();
					cout << "�����ʽ����" << endl;
				}
				else
				{
					stu _stui;
					_stui.id = id;
					setBlue();
					if (list1.length() == 0)
					{
						cout << "������" << endl;
					}
					else
					{
						int result = list1.removeAll(&_stui, equal_stu);

						cout << "��ɾ��" << result << "����¼" << endl;
					}
				}


			}
			else if (cmdi == 5)
			{
				setBlue();
				if (list1.length() == 0)
				{
					cout << "������" << endl;
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
				cout << "����Ӧ������" << endl;
			}

			cmdi = 0;
			//�������������
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
	cout << "������Գ���";
	print_char(40, '=');
	cout << endl;
	setBlue();
	cout << "Author:cht copyright ZJUT" << endl;
	setBlueGreen();
	print_char(30);
	cout << "��0���˳�����" << endl;
	print_char(30);
	cout << "��1����ĩβ���һ������" << endl;
	print_char(30);
	cout << "��2����ĩβ��Ӷ�������" << endl;
	print_char(30);
	cout << "��3����ָ������������һ������" << endl;
	print_char(30);
	cout << "��4������ѧ��ɾ������ƥ�������" << endl;
	print_char(30);
	cout << "��5����ӡ��������" << endl;
	//print_char(30);
	//cout << "��6����������" << endl;
	setYellow();
	print_char(40, '=');
	cout << "������Գ���";
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

