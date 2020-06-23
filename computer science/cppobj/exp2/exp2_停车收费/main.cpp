#include<iostream>
#include<cstdlib>
#include"datetime.h"
#include"park.h"
#include<ctime>
#include<string>
using namespace std;

int main() 
{

	do
	{
		cout << "================"
			<< "欢迎来到停车收费系统"  
			<< "================" << endl
			<< "若要停车，请输入停车时间" << endl
			<< "若要退出程序，请输入exit" << endl
			<< "若要查看收费规则，请输入pay" << endl
			<< "================================================" << endl
			<< "请输入命令或停车的时间:" ;
		string x,y; 
		park _park;
		datetime start,end;
		getline(cin, x);
		if (x == "exit")
		{
			cout << "欢迎下次光临，再见。" << endl;
			break;
		}
		else if(x == "pay")
		{
			cout << "当你停车不足一小时时，收费4.5元。" << endl
				<< "超过1小时并不超过48小时的，超过的部分每小时收费6元，不足30分钟则按30分钟计算。" << endl
				<< "超过48小时，超过的部分每小时收费12元，不足一小时则按一小时计算。" << endl;
			continue;
		}
		if (datetime::tryparse(x,&start))
		{
			_park.start = start;
		}
		else
		{
			cout << "> 抱歉，你的输入有误，本次交易已取消." << endl;
			continue;
		}
		cout << "请输入离开的时间:";
		getline(cin, y);
		if (datetime::tryparse(y,&end))
		{
			_park.end = end;
		}
		else
		{
			cout << "> 抱歉，你的输入有误，本次交易已取消." << endl;
			continue;
		}
		int pay = _park.getpayment();
		if (pay == -1)
		{
			cout << "> 交易失败，你停车的时间为负数" << endl;
		}
		else
		{
			cout << "> 交易成功，你共停车"<< (int)((_park.end - _park.start).gettotalhours() * 100)/100.0 <<"个小时，你需要支付" << _park.getpayment() << "元" << endl;
		}
		
	} while (true);

	//datetime xtime = datetime::now();
	//datetime time1 = datetime::parse("2019/03/19 22:33:57");

	//cout << time1.to_localtimestring() << endl;
	//cout << xtime.to_localtimestring() << endl;

	//cout << (xtime - time1).gettotaldays() << endl;
	//cout << xtime.getdayofweek() << endl;

	system("pause");
	return 0;
}