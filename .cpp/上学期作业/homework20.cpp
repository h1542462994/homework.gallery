#include<iostream>
using namespace std;

long getfactorial_static(int x)
{
	static int num = 1;
	static int result = 1;

	if (x > num)
	{
		for (int i = num + 1; i <= x; i++)
		{
			result *= i;
		}
		num = x;
	}
	else if (x < num && x >= 1)
	{
		num = 1;
		result = 1;
		for (int i = 2; i <= x; i++)
		{
			result *= i;
		}
	}
	else if (x < 1)
	{
		return -1;
	}

	return result;
}
int main()
{
	cout << "在函数中使用静态局部变量，调用函数计算n的阶乘。，请输入n，返回它的阶乘。" << endl;
	int num;
	while (cin >> num && num > 0)
	{
		cout << getfactorial_static(num) << endl;
	}


	return 0;
}