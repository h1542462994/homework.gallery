#pragma once
#include"Context.h"
#include"Log.h"
#include<iostream>
using namespace std;

/*
应用程序类，为CUI提供了基础输入与输出封装。
*/
class AppBase
{
public:
	//启动应用程序，这一步操作总是第一步执行的。
	void run()
	{
		onLoad();
		handleInput();
	}
	AppBase(Context* context):context(context)
	{
	}

protected:
	//显示提示字符串信息，由handleInput()函数来调用，需要进行重写。
	virtual string onTip() = 0;
	//在初始化的时候会被调用的函数。
	virtual void onLoad() = 0;
	//处理控制字符信息，由handleInput()函数来调用，需要进行重写。
	//@return 是否继续执行，若返回false，则表示应用程序终止运行。
	virtual bool onHandleInput(string command) = 0;
	
	//获取当前的上下文信息。
	Context& getContext()
	{
		return *context;
	}

private:

	//将系统的cin封装起来，用于和用户进行交互
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