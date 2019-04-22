#include<iostream>
using namespace std;

int main()
{
	int numbers[10];
	cout << "请以此输入10个整数，我将逆序输出其中的正数:";
	for (int i = 0; i < 10; i++)
	{
		cin >> numbers[i];
	}
	for (int i = 10 - 1; i >= 0; i--)
	{
		if (numbers[i] > 0)
		{
			cout << numbers[i] << ' ';
		}
	}
	cout << endl;

	return 0;
}