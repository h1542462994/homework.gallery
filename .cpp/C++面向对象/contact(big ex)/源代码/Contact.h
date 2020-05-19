#pragma once
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

//data class
class Contact
{
public:
	Contact()
	{
	}
	Contact(string name) :name(name)
	{
	}

	string name;
	string sex;
	string phone;
	string address;
	string postCode;
	string email;
	string qq;
	string type;

	friend ostream& operator << (ostream& out, const Contact& obj)
	{
		out << "姓名:\t" << obj.name << endl
			<< "性别:\t" << (obj.sex == "" ? "(无)" : (obj.sex == "M" ? "男" : "女")) << endl
			<< "电话:\t" << obj.phone << endl
			<< "地址:\t" << obj.address << endl
			<< "邮政编码:\t" << obj.postCode << endl
			<< "邮箱:\t" << obj.email << endl
			<< "QQ号:\t" << obj.qq << endl
			<< "分组:\t" << (obj.type == "" ? "(无)" : obj.type) << endl;

		return out;
	}

	void showSimple()
	{
		cout << setw(12) << name << setw(20) << phone << setw(6) << ( type == ""?"(无)":type) << endl;
	}

	bool isValid()
	{
		if (sex == "M" || sex == "W")
		{
		}
		else
		{
			return false;
		}

		if (phone == "")
		{
			return false;
		}
		return true;
	}
};