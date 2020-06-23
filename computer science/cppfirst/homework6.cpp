#include<iostream>
using namespace std;
int main() 
{
	cout << "这是统计10个正整数中能被3整除的数的个数的小程序." << endl
		<< "现在，请以此输入10个正整数:";
	int current_x, count = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> current_x;
		if (current_x <= 0)
		{
			cout << "argument error at the " << i + 1 << " number.";
			return 0;
		}
		if (current_x % 3 == 0)
		{
			count++;
		}
	}

	cout << count << endl;
	return 0;
}