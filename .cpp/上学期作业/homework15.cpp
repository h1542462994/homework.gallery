#include<iostream>
#include<string.h>
using namespace std;

int moveint(int size, int value, int offset)
{
	value += offset;
	if (value >= 0)
	{
		return value % size;
	}
	else
	{
		return value % size + size;
	}
}
int main()
{
	cout << "按循环方式生成n*n矩阵，第一行输入n，第二行输入n个数据，将以此左移数据并输出。" << endl;
	int num, data[100];
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> data[i];
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			//相当于查找右移的元素并输出。
			cout << data[moveint(5, j, i)] << ' ';
		}
		cout << endl;
	}

	return 0;
}
