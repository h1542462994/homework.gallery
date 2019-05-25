#pragma once

#include<iostream>
#include<vector>
#include<tuple>
#include"Menu.h"
#include"listener.h"
#include"Contact.h"
#include<map>
#include<algorithm>
#include<fstream>
#include"Log.h"
//#include"AppBase.h"

using namespace std;


bool contactComparerByGroup(Contact* p1, Contact* p2)
{
	return p1->type < p2->type;
}
bool contactComparerByName(Contact* p1,Contact* p2)
{
	return p1->name < p2->name;
}
bool contactComparerByPhone(Contact* p1,Contact * p2)
{
	return p1->phone < p2->phone;
}
bool contactComparerByAddress(Contact* p1, Contact* p2)
{
	return p1->address < p2->address;
}

//@attach("android.Context")
class Context
{
public:
	Context()
	{
		init();
	}

	Menu& getMenu(string key) {
		return menus[key];
	}
	Menu& getCurrentMenu()
	{
		return menus[page];
	}

	void setOnPageChangedListener(IOnPageChangedListener* listener)
	{
		pageChangedListener = listener;
	}
	bool createFile(string fileName)
	{
		this->fileName = fileName;
		fstream _file;
		_file.open(fileName, ios::in);
		if (_file)
		{
			return false;
		}
		fileState = 1;
		if (contacts.size() > 0)
		{
			for (int i = 0; i < contacts.size(); i++)
			{
				delete contacts[i];
			}
		}
		contacts.clear();
		return true;
	}
	bool loadFile(string fileName)
	{
		this->fileName = fileName;
		fstream _file;
		_file.open(fileName, ios::in);
		if (!_file)
		{
			return false;
		}
		else 
		{
			for (int i = 0; i < contacts.size(); i++)
			{
				delete contacts[i];
			}
			contacts.clear();

			int index = 0;
			int ti = 0;
			string line;
			Contact* contact = NULL;
			while (getline(_file, line) && !_file.eof())
			{
				if (ti == 0)
				{
					contact = new Contact();
					contact->name = line.substr(1);
				}
				else if (ti == 1)
				{
					contact->sex = line;
				}
				else if (ti == 2)
				{
					contact->phone = line;
				}
				else if (ti == 3)
				{
					contact->address = line;
				}
				else if (ti ==4)
				{
					contact->postCode = line;
				}
				else if (ti == 5)
				{
					contact->email = line;
				}
				else if (ti == 6)
				{
					contact->qq = line;
				}
				else if (ti == 7)
				{
					contact->type = line;
				}
				ti++;
				if (ti == 8)
				{
					ti = 0;
					contacts.push_back(contact);
				}
			}
			_file.close();
			return true;
		}
	}
	void saveFile()
	{
		if (fileState == 1)
		{
			fstream _file;
			_file.open(fileName, ios::out | ios::trunc);
			for (int i = 0; i < contacts.size(); i++)
			{
				Contact* c = contacts[i];
				_file << "#" << c->name << endl
					<< c->sex << endl
					<< c->phone << endl
					<< c->address << endl
					<< c->postCode << endl
					<< c->email << endl
					<< c->qq << endl
					<< c->type << endl;
			}
			_file.close();
			fileState = 0;
		}

	}
	string getPage()
	{
		return page;
	}
	void setPage(string page)
	{
		this->page = page;
		if (pageChangedListener != NULL)
		{
			pageChangedListener->onPageChanged(page);
		}
	}
	//����ģʽ������ϵ�ˣ��������ݽ��ᱣ����search�ֶ���
	void searchContact(string mode, string param)
	{
		
		auto re = new vector<pair<Contact*,int>>();
		for (int i = 0; i < contacts.size(); i++)
		{
			if (mode == "name")
			{
				if (hasSubString(contacts[i]->name, param))
				{
					re->push_back(pair<Contact*, int>(contacts[i], i));
				}
			}
			else if (mode == "phone")
			{
				if (hasSubString(contacts[i]->phone, param))
				{
					re->push_back(pair<Contact*, int>(contacts[i], i));
				}
			}
			else if (mode == "address")
			{
				if (hasSubString(contacts[i]->address,param))
				{
					re->push_back(pair<Contact*, int>(contacts[i], i));
				}
			}
			else if (mode == "group")
			{
				if (hasSubString(contacts[i]->type,param))
				{
					re->push_back(pair<Contact*, int>(contacts[i], i));
				}
			}
		}

		if (search != NULL)
		{
			delete search;
		}

		search = re;
	}
	//��ղ�������
	void clearSearch() 
	{
		if (search!= NULL)
		{
			delete search;
			search = NULL;
		}
	}
	//չʾһ����ϵ�˵ķ������
	void showContactGroup()
	{
		if (contacts.size() == 0)
		{
			Log::w("��ϵ��Ϊ��");
		}
		else
		{
			vector<Contact*> ccopy;
			for (int i = 0; i < contacts.size(); i++)
			{
				ccopy.push_back(contacts[i]);
			}

			sort(ccopy.begin(), ccopy.end(), contactComparerByGroup);

			cout << "  " << consoleforecolor::cyan //<< setw(6) << std::left << "���"
				<< setw(12) << "����"
				<< setw(6) << "�Ա�"
				<< setw(20) << "�绰"
				<< setw(20) << "��ַ"
				<< setw(6) << "����" << consoleforecolor::normal << endl;
			string type = ccopy[0]->type;
			cout << consoleforecolor::ochre << (type==""?"��":type) << consoleforecolor::normal <<  endl;


			for (int i = 0; i < ccopy.size(); i++)
			{
				if (ccopy[i]->type != type)
				{
					type = ccopy[i]->type;
					cout << consoleforecolor::ochre << (type == "" ? "��" : type) << consoleforecolor::normal << endl;
				}
				cout << "  ";
				Contact* c = ccopy[i];
				cout << consoleforecolor::normal;
					//<< setw(6) << i 
					//<< setw(12) << c->name
					if (eggvar == 1 && (c->name == "cg"))
					{
						cout << setw(12) << consoleforecolor::red << ("(*��-��*) " + c->name) << consoleforecolor::normal;
					}
					else
					{
						cout << setw(12) << c->name;
					}
				    cout << setw(6) << (c->sex == "M" ? "��" : "Ů")
					<< setw(20) << c->phone
					<< setw(20) << c->address
					<< setw(6) << (c->type == "" ? "��" : c->type)
					<< consoleforecolor::normal << endl;
			}
		}
	}
	//����ģʽ����ϵ�˽�������
	void sortContact(string mode)
	{
		if (mode == "name")
		{
			sort(contacts.begin(), contacts.end(), contactComparerByName);
		}
		else if (mode == "phone")
		{
			sort(contacts.begin(), contacts.end(), contactComparerByPhone);
		}
		else if (mode == "address")
		{
			sort(contacts.begin(), contacts.end(), contactComparerByAddress);
		}
		else if (mode == "group")
		{
			sort(contacts.begin(), contacts.end(), contactComparerByGroup);
		}
	}
	//��ѯ�Ľ���Ķ�̬����
	vector<pair< Contact*,int>>* search = NULL;
	string subpage;
	//��ϵ�˵Ĵ洢
	vector<Contact*> contacts;
	//��ǰ����ϵ�ˣ����ڵ�page="contact"ʱ��Ч
	Contact* currentContact = NULL;
	//�ļ���
	string fileName = "";
	//�ļ���״̬��0��ʾ�ļ�δ�򿪻���δ���ģ�1��ʾ�ļ��Ѿ����ģ���û�б��浽�ļ���
	int fileState = 0;
	//��ʶ�Ƿ��ǲʵ�
	const int eggvar = 1;
private:
	inline void init()
	{
		page = "home";
		menus["home"] = { "�½�/���ļ�","�˳�����" };
		menus["file"] = { "�½�/����ϵ��","�г���ϵ���嵥","����(����)","����(�绰)","����(סַ)","����(����)","��ʾ��ǰ������Ϣ","����","�ص���һ���˵�" };
		menus["contact"] = { "��ʾ��ϸ����","�޸�����","�޸��Ա�","�޸ĵ绰","�޸ĵ�ַ","�޸���������","�޸�����","�޸�QQ��Ϣ","�ƶ�����","ɾ����ϵ��","�ص���һ���˵�" };
		subpage = "";
	}
	map<string, Menu> menus;
	string page;
	IOnPageChangedListener* pageChangedListener = NULL;
	

	//���str2�Ƿ���str1���Ӵ���һ����򵥵�ģ�����ҷ���
	bool hasSubString(string str1,string str2)
	{
		if (str1.find(str2)!= string::npos)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};
