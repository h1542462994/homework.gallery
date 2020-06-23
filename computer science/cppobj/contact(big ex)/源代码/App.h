#pragma once

#include"AppBase.h"
#include"Context.h"
#include"Log.h"
#include<sstream>
#include"listener.h"
#include"Contact.h"
#include<iomanip>

using namespace std;

class DApp :public AppBase, public IOnPageChangedListener
{
public:
	DApp(Context* context) :AppBase(context) {}

protected:
	virtual void onLoad() override
	{
		Log::i("欢迎来到电话簿系统，请敬请享用吧。");
		//cout << getContext().getMenu("home");
	}

	virtual void onPageChanged(string page) override
	{
		//cout << getContext().getCurrentMenu();
	}

	virtual string onTip() override
	{


		string tip = "";
		string page = getContext().getPage();
		string subpage = getContext().subpage;

		if (subpage == "")
		{
			cout << getContext().getCurrentMenu();
		}

		if (page == "home")
		{
			if (subpage == "")
			{
				tip = "请选择菜单中的一项";
			}
			else if (subpage == "create")
			{
				tip = "请输入新建/打开的文件名";
			}
		}
		else if (page == "file")
		{
			if (subpage == "")
			{
				getContext().saveFile();
				tip = "请选择菜单中的一项";
			}
			else if (subpage == "create")
			{
				tip = "请输入新建/打开联系人的姓名";
			}
			else if (subpage == "search-name")
			{
				tip = "请输入想要查询人的姓名";
			}
			else if (subpage == "search-phone")
			{
				tip = "请输入想要查询人的电话";
			}
			else if (subpage == "search-address")
			{
				tip = "请输入想要查询人的地址";
			}
			else if (subpage == "search-group")
			{
				tip = "请输入想要查询的分组信息";
			}
			else if (subpage == "select")
			{
				tip = "选择第几个呢？你可以输入-1取消该操作";
			}
			else if (subpage == "sort")
			{
				cout << "0:退出排序" << endl
					<< "1:姓名" << endl
					<< "2:电话" << endl
					<< "3:地址" << endl
					<< "4:分组" << endl;
				tip = "请选择排序的键";
			}
		}
		else if (page == "contact")
		{
			if (subpage == "")
			{
				tip = "请选择菜单中的一项";
			}
			else if (subpage == "name")
			{
				tip = "请输入姓名";
			}
			else if (subpage == "sex")
			{
				tip = "请输入性别(M/W)";
			}
			else if (subpage == "phone")
			{
				tip = "请输入电话";
			}
			else if (subpage == "address")
			{
				tip = "请输入地址";
			}
			else if (subpage == "postCode")
			{
				tip = "请输入邮政编码";
			}
			else if (subpage == "email")
			{
				tip = "请输入邮箱";
			}
			else if (subpage == "qq")
			{
				tip = "请输入QQ号";
			}
			else if (subpage == "delete")
			{
				tip = "你确认要删除该联系人吗(Y/N)";
			}
			else if (subpage == "group")
			{
				tip = "请输入分组信息";
			}
		}
		return tip;
	}

	virtual bool onHandleInput(string command) override
	{
		string page = getContext().getPage();
		string& subpage = getContext().subpage;
		istringstream istr(command);

		if (page == "home")
		{
			if (subpage == "")
			{
				int cmd = -1;
				istr >> cmd;
				//新建/打开文件
				if (cmd == 1)
				{
					subpage = "create";
				}
				//退出程序
				else if (cmd == 2)
				{
					return false;
				}
				else
				{
					Log::e("输入错误，请重新输入。");
				}
			}
			else if (subpage == "create")
			{
				int check = checkFileName(command);
				if (check == 1)
				{
					Log::e("文件名不能为空");
				}
				else if (check == 2)
				{
					Log::e("文件名太长，不应该超过40个字符");
				}
				else if (check == 3)
				{
					Log::e("文件名不应该含有[/\\:*\"<>|?]这些非法字符");
				}
				else
				{

					bool r = getContext().createFile(command);
					if (r)
					{
						Log::w("已创建文件" + command);
					}
					else
					{
						getContext().loadFile(command);
						Log::w("已打开文件" + command);
					}
					getContext().subpage = "";
					getContext().setPage("file");
				}
			}
		}
		else if (page == "file")
		{
			if (subpage == "")
			{
				int cmd = -1;
				istr >> cmd;

				if (cmd == 1)
				{
					subpage = "create";
				}
				else if (cmd == 2)
				{
					if (getContext().contacts.size() < 1)
					{
						Log::w("当前还没有联系人");
					}
					else
					{
						cout << consoleforecolor::cyan << setw(6) << std::left << "序号"
							<< setw(12) << "姓名"
							<< setw(6) << "性别"
							<< setw(20) << "电话"
							<< setw(20) << "地址"
							<< setw(6) << "分组" << consoleforecolor::normal << endl;

						for (int i = 0; i < getContext().contacts.size(); i++)
						{
							cout << consoleforecolor::cyan << setw(6) << std::left << i << consoleforecolor::normal;


							Contact* c = getContext().contacts[i];

							if (getContext().eggvar == 1 && (c->name == "cg"))
							{
								cout << setw(12) << consoleforecolor::red << ("(*＾-＾*) " + c->name) << consoleforecolor::normal;
							}
							else
							{
								cout << setw(12) << c->name;
							}

							cout
								<< setw(6) << (c->sex == "M" ? "男" : "女")
								<< setw(20) << c->phone
								<< setw(20) << c->address
								<< setw(6) << (c->type == "" ? "无" : c->type)
								<< consoleforecolor::normal << endl;
						}
						//getContext().search = NULL;
						subpage = "select";
					}

				}
				else if (cmd == 3)
				{
					subpage = "search-name";
				}
				else if (cmd == 4)
				{
					subpage = "search-phone";
				}
				else if (cmd == 5)
				{
					subpage = "search-address";
				}
				else if (cmd == 6)
				{
					subpage = "search-group";
				}
				else if (cmd == 7)
				{
					getContext().showContactGroup();
				}
				else if (cmd == 8)
				{
					subpage = "sort";
				}
				else if (cmd == 9)
				{
					getContext().fileName = "";
					getContext().setPage("home");
				}
				else
				{
					Log::e("输入错误，请重新输入。");
				}
			}
			else if (subpage == "create")
			{
				//verbose :: any !!
				if (command == "")
				{
					Log::e("姓名不能为空");
				}
				else if (command.size() > 20)
				{
					Log::e("姓名太长，应不大于20个字符");
				}
				else
				{
					bool flag = false;
					for (int i = 0; i < getContext().contacts.size(); i++)
					{
						if (getContext().contacts[i]->name == command)
						{
							getContext().currentContact = getContext().contacts[i];
							Log::w("打开联系人成功");
							flag = true;
							break;
						}
					}

					if (!flag)
					{
						Contact* contact = new Contact(command);
						getContext().contacts.push_back(contact);
						getContext().currentContact = contact;
					}


					getContext().subpage = "";
					getContext().setPage("contact");

					getContext().fileState = 1;
				}


			}
			//选择界面
			else if (subpage == "select")
			{
				if (getContext().search == NULL)
				{
					auto se = &getContext().contacts;

					int index = -2;
					istr >> index;

					if (index == -1)
					{
						subpage = "";
					}
					else if (index >= 0 && index < se->size())
					{
						getContext().currentContact = (*se)[index];
						getContext().clearSearch();
						subpage = "";
						getContext().setPage("contact");
					}
					else
					{
						Log::e("无效的输入");
					}

				}
				else
				{
					auto se = getContext().search;

					int index = -2;
					istr >> index;

					if (index == -1)
					{
						subpage = "";
					}
					else if (index >= 0 && index < se->size())
					{
						getContext().currentContact = (*se)[index].first;
						subpage = "";
						getContext().setPage("contact");
					}
					else
					{
						Log::e("无效的输入");
					}
				}

			}
			//按照人员来查找
			else if (subpage == "search-name" || subpage == "search-phone" || subpage == "search-address" || subpage == "search-group")
			{
				if (subpage == "search-name")
				{
					getContext().searchContact("name", command);
				}
				else if (subpage == "search-phone")
				{
					getContext().searchContact("phone", command);
				}
				else if (subpage == "search-address")
				{
					getContext().searchContact("address", command);
				}
				//getContext().searchContact("name", command);
				else if (subpage == "search-group")
				{
					getContext().searchContact("group", command);
				}

				if (getContext().search->size() > 0)
				{
					cout << consoleforecolor::cyan
						<< setw(6) << std::left << "序号";
					if (subpage == "search-address")
					{
						cout << setw(20) << "地址"
							<< setw(12) << "姓名"
							<< setw(6) << "性别"
							<< setw(20) << "电话"
							<< setw(6) << "分组" << consoleforecolor::normal << endl;
					}
					else if (subpage == "search-name")
					{
						cout
							<< setw(12) << "姓名"
							<< setw(6) << "性别"
							<< setw(20) << "电话"
							<< setw(20) << "地址"
							<< setw(6) << "分组" << consoleforecolor::normal << endl;
					}
					else if (subpage == "search-phone")
					{
						cout
							<< setw(20) << "电话"
							<< setw(12) << "姓名"
							<< setw(6) << "性别"
							<< setw(20) << "地址"
							<< setw(6) << "分组" << consoleforecolor::normal << endl;
					}
					else if (subpage == "search-group")
					{
						cout
							<< setw(20) << "地址"
							<< setw(12) << "姓名"
							<< setw(6) << "性别"
							<< setw(20) << "电话"
							<< setw(6) << "分组" << consoleforecolor::normal << endl;
					}

					for (int i = 0; i < getContext().search->size(); i++)
					{
						cout << consoleforecolor::cyan << setw(6) << i << consoleforecolor::normal;
						Contact* c = getContext().search->at(i).first;

						if (subpage == "search-address")
						{

							cout << consoleforecolor::ochre
								<< setw(20) << c->address
								<< consoleforecolor::normal;
							//<< setw(12) << c->name 
							if (getContext().eggvar == 1 && (c->name == "cg"))
							{
								cout << setw(12) << consoleforecolor::red << ("(*＾-＾*) " + c->name) << consoleforecolor::normal;
							}
							else
							{
								cout << setw(12) << c->name;
							}
							cout << setw(6) << (c->sex == "M" ? "男" : "女")
								<< setw(20) << c->phone
								<< setw(6) << (c->type == "" ? "无" : c->type)
								<< consoleforecolor::normal;
						}
						else if (subpage == "search-name")
						{
							cout << consoleforecolor::ochre;

							if (getContext().eggvar == 1 && (c->name == "cg"))
							{
								cout << setw(12) << consoleforecolor::red << ("(*＾-＾*) " + c->name) << consoleforecolor::normal;
							}
							else
							{
								cout << setw(12) << c->name;
							}

							cout<< consoleforecolor::normal
								<< setw(6) << (c->sex == "M" ? "男" : "女")
								<< setw(20) << c->phone
								<< setw(20) << c->address
								<< setw(6) << (c->type == "" ? "无" : c->type)
								<< consoleforecolor::normal;
						}
						else if (subpage == "search-phone")
						{
							cout << consoleforecolor::ochre
								<< setw(20) << c->phone
								<< consoleforecolor::normal;
								//<< setw(12) << c->name
								if (getContext().eggvar == 1 && (c->name == "cg"))
								{
									cout << setw(12) << consoleforecolor::red << ("(*＾-＾*) " + c->name) << consoleforecolor::normal;
								}
								else
								{
									cout << setw(12) << c->name;
								}
								 cout << setw(6) << (c->sex == "M" ? "男" : "女")
								<< setw(20) << c->address
								<< setw(6) << (c->type == "" ? "无" : c->type)
								<< consoleforecolor::normal;
						}
						else if (subpage == "search-group")
						{
							cout << consoleforecolor::ochre
								<< setw(6) << (c->type == "" ? "无" : c->type)
								<< consoleforecolor::normal;
								//<< setw(12) << c->name
								if (getContext().eggvar == 1 && (c->name == "cg"))
								{
									cout << setw(12) << consoleforecolor::red << ("(*＾-＾*) " + c->name) << consoleforecolor::normal;
								}
								else
								{
									cout << setw(12) << c->name;
								}
								 cout << setw(6) << (c->sex == "M" ? "男" : "女")
								<< setw(20) << c->phone
								<< setw(20) << c->address
								<< consoleforecolor::normal;
						}
						cout << endl;
					}

					subpage = "select";
				}
				else
				{
					Log::i("未找到该联系人");

					subpage = "";
				}
			}
			else if (subpage == "sort")
			{
				int cmd = -1;
				istr >> cmd;
				if (cmd < 0 || cmd > 4)
				{
					Log::e("输入错误");
				}
				else
				{
					if (cmd == 0)
					{
						Log::w("已退出排序");
					}
					else if (getContext().contacts.size() > 0)
					{
						if (cmd == 1)
						{
							getContext().sortContact("name");
							getContext().fileState = 1;
						}
						else if (cmd == 2)
						{
							getContext().sortContact("phone");
							getContext().fileState = 1;
						}
						else if (cmd == 3)
						{
							getContext().sortContact("address");
							getContext().fileState = 1;
						}
						else if (cmd == 4)
						{
							getContext().sortContact("group");
							getContext().fileState = 1;
						}
						Log::w("已排序完成");
					}
					else
					{
						Log::w("无联系人，无法完成排序");
					}

					getContext().subpage = "";
				}


			}
		}
		else if (page == "contact")
		{
			if (subpage == "")
			{
				int cmd = -1;
				istr >> cmd;
				if (cmd == 1)
				{
					cout << *getContext().currentContact;
				}
				else if (cmd == 2)
				{
					subpage = "name";
				}
				else if (cmd == 3)
				{
					subpage = "sex";
				}
				else if (cmd == 4)
				{
					subpage = "phone";
				}
				else if (cmd == 5)
				{
					subpage = "address";
				}
				else if (cmd == 6)
				{
					subpage = "postCode";
				}
				else if (cmd == 7)
				{
					subpage = "email";
				}
				else if (cmd == 8)
				{
					subpage = "qq";
				}
				else if (cmd == 9)
				{
					subpage = "group";
				}
				else if (cmd == 10)
				{
					subpage = "delete";
				}
				else if (cmd == 11)
				{
					if (getContext().currentContact->isValid())
					{
						subpage = "";
						getContext().setPage("file");
						getContext().currentContact = NULL;
					}
					else
					{
						Log::e("当前联系人缺少必要的字段：性别和电话，你可以选择删除联系人或者将这些信息补充完整。");
					}
				}
				else
				{
					Log::e("输入错误，请重新输入。");
				}
			}
			else if (subpage == "name")
			{
				if (command == "")
				{
					Log::e("姓名字段不能为空");
				}
				else if (command.size() > 20)
				{
					Log::e("姓名字段长度应不大于20个字符");
				}
				else
				{
					getContext().currentContact->name = command;
					Log::w("修改姓名字段成功");
					subpage = "";
					//getContext().saveFile();
					getContext().fileState = 1;
				}
			}
			else if (subpage == "sex")
			{
				if (command == "M" || command == "W")
				{
					getContext().currentContact->sex = command;
					Log::w("修改性别字段成功");
					subpage = "";
					//getContext().saveFile();
					getContext().fileState = 1;
				}
				else if (command == "")
				{
					Log::e("性别字段不能为空");
				}
				else
				{
					Log::e("非法的输入");
				}
			}
			else if (subpage == "phone")
			{
				getContext().currentContact->phone = command;
				Log::w("修改电话字段成功");
				subpage = "";
				getContext().fileState = 1;
			}
			else if (subpage == "address")
			{
				getContext().currentContact->address = command;
				Log::w("修改地址字段成功");
				subpage = "";
				getContext().fileState = 1;
			}
			else if (subpage == "postCode")
			{
				getContext().currentContact->postCode = command;
				Log::w("修改邮政编码字段成功");
				subpage = "";
				getContext().fileState = 1;
			}
			else if (subpage == "email")
			{
				getContext().currentContact->email = command;
				Log::w("修改邮箱字段成功");
				subpage = "";
				getContext().fileState = 1;
			}
			else if (subpage == "delete")
			{
				if (command == "Y")
				{
					for (int i = 0; i < getContext().contacts.size(); i++)
					{
						if (getContext().contacts[i] == getContext().currentContact)
						{
							vector<Contact*>::iterator iter = getContext().contacts.begin() + i;
							getContext().contacts.erase(iter);
						}
					}

					delete getContext().currentContact;
					getContext().currentContact = NULL;
					getContext().fileState = 1;

					subpage = "";
					getContext().setPage("file");
					Log::w("已删除联系人");
				}
				else if (command == "N")
				{
					subpage = "";
				}
				else
				{
					Log::e("输入错误");
				}

			}
			else if (subpage == "group")
			{
				getContext().currentContact->type = command;
				Log::w("修改分组信息成功");
				subpage = "";
				getContext().fileState = 1;
			}
			else if (subpage == "qq")
			{
				getContext().currentContact->qq = command;
				Log::w("修改QQ信息成功");
				subpage = "";
				getContext().fileState = 1;
			}
		}
		return true;
	}

private:
	//用于检查文件名是否合法。
	int checkFileName(string fileName)
	{
		if (fileName == "")
		{
			return 1;
		}
		else if (fileName.size() > 40)
		{
			return 2;
		}
		else
		{
			string except = "/\\:*\"<>|?";
			for (int i = 0; i < except.length(); i++)
			{
				if (fileName.find(except[i]) != string::npos)
				{
					return 3;
				}
			}
		}
		return 0;
	}

	//deprecated
	Contact createContact(string name)
	{
		Contact contact(name);
		int iloop = 1;
		while (iloop > 0)
		{
			if (iloop == 1)
			{
				cout << consoleforecolor::seablue << "请输入性别(M/W)：" << consoleforecolor::normal;
			}
			else if (iloop == 2)
			{
				cout << consoleforecolor::seablue << "请输入电话(不可为空)：" << consoleforecolor::normal;
			}
			else if (iloop == 3)
			{
				cout << consoleforecolor::seablue << "请输入地址(不可为空)：" << consoleforecolor::normal;
			}
			else if (iloop == 4)
			{
				cout << consoleforecolor::seablue << "请输入邮箱：" << consoleforecolor::normal;
			}
			else if (iloop == 5)
			{
				cout << consoleforecolor::seablue << "请输入邮政编码：" << consoleforecolor::normal;
			}
			else if (iloop == 6)
			{
				cout << consoleforecolor::seablue << "请输入qq号码：" << consoleforecolor::normal;
			}
			else if (iloop == 7)
			{
				cout << consoleforecolor::seablue << "请输入分组信息：" << consoleforecolor::normal;
			}

			string line;
			getline(cin, line);
			//istringstream istr(line);

			if (iloop == 1)
			{
				//cout << consoleforecolor::seablue << "请输入性别(M/W)：" << consoleforecolor::normal;
				if (line == "M" || line == "W")
				{
					contact.sex = line;
					++iloop;
				}
				else
				{
					Log::e("输入非法的字符，正确的输入应为M/W");
				}
			}
			else if (iloop == 2)
			{
				//cout << consoleforecolor::seablue << "请输入电话：" << consoleforecolor::normal;
				if (line == "")
				{
					Log::e("输入不能为空");
				}
				else
				{
					contact.phone = line;
					++iloop;
				}
			}
			else if (iloop == 3)
			{
				//cout << consoleforecolor::seablue << "请输入地址：" << consoleforecolor::normal;
				if (line == "")
				{
					Log::e("输入不能为空");
				}
				else
				{
					contact.address = line;
					++iloop;
				}
			}
			else if (iloop == 4)
			{
				contact.email = line;
			}
			else if (iloop == 5)
			{
				contact.postCode = line;
			}
		}
	}
};