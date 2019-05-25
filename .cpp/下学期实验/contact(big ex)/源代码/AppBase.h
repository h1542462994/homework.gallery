#pragma once
#include"Context.h"
#include"Log.h"
#include<iostream>
using namespace std;

/*
Ӧ�ó����࣬ΪCUI�ṩ�˻��������������װ��
*/
class AppBase
{
public:
	//����Ӧ�ó�����һ���������ǵ�һ��ִ�еġ�
	void run()
	{
		onLoad();
		handleInput();
	}
	AppBase(Context* context):context(context)
	{
	}

protected:
	//��ʾ��ʾ�ַ�����Ϣ����handleInput()���������ã���Ҫ������д��
	virtual string onTip() = 0;
	//�ڳ�ʼ����ʱ��ᱻ���õĺ�����
	virtual void onLoad() = 0;
	//��������ַ���Ϣ����handleInput()���������ã���Ҫ������д��
	//@return �Ƿ����ִ�У�������false�����ʾӦ�ó�����ֹ���С�
	virtual bool onHandleInput(string command) = 0;
	
	//��ȡ��ǰ����������Ϣ��
	Context& getContext()
	{
		return *context;
	}

private:

	//��ϵͳ��cin��װ���������ں��û����н���
	void handleInput() 
	{
		while (true)
		{
			auto tip = onTip();
			cout << consoleforecolor::seablue << "> " << tip << ":" <<  consoleforecolor::normal;
			string cmd;
			getline(cin, cmd);
			if (!onHandleInput(cmd))
			{
				break;
			}
		}
	}

	Context* context;


};