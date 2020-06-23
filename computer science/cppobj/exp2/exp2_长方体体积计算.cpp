/**
 * @description: C++ 第八章课后习题 第6题
 * @author:cht ZJUT
 */

#include<iostream>
#include<cstdlib>
using namespace std;

#pragma region defination
// 长方柱
class bulk 
{
public:
	void setlwh();
	double calcvolumn();
private:
	double length;
	double width;
	double height;
};

void bulk::setlwh()
{
	cin >> length >> width >> height;
}

double bulk::calcvolumn()
{
	return length * width * height;
}

#pragma endregion


int main() 
{
	bulk b[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i << "个长方体的长、宽、高:";
		b[i].setlwh();
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "第" << i << "个长方体的体积为:" << b[i].calcvolumn() << endl;
	}

	system("pause");
	return 0;
}