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
		out << "����:\t" << obj.name << endl
			<< "�Ա�:\t" << (obj.sex == "" ? "(��)" : (obj.sex == "M" ? "��" : "Ů")) << endl
			<< "�绰:\t" << obj.phone << endl
			<< "��ַ:\t" << obj.address << endl
			<< "��������:\t" << obj.postCode << endl
			<< "����:\t" << obj.email << endl
			<< "QQ��:\t" << obj.qq << endl
			<< "����:\t" << (obj.type == "" ? "(��)" : obj.type) << endl;

		return out;
	}

	void showSimple()
	{
		cout << setw(12) << name << setw(20) << phone << setw(6) << ( type == ""?"(��)":type) << endl;
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