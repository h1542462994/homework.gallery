#include<iostream>
using namespace std;
int main()
{
	//define
	int a[1000], b[1000], result[1000];
	int a_count, b_count, result_count = 0;

	//input
	cout << "请在第一行输入两个整数，分别表示两个序列的长度，" << endl
		<< "请在第二及第三行输入相应长度的数字序列，注意需要从小到大排列" << endl;
	cin >> a_count >> b_count;
	for (int i = 0; i < a_count; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < b_count; i++)
	{
		cin >> b[i];
	}

	//analyse
	int i = 0, j = 0;
	while (i < a_count && j < b_count)
	{
		if (a[i] < b[j])
		{
			i++;
		}
		else if (a[i] > b[j])
		{
			j++;
		}
		else
		{
			result[result_count] = a[i];
			result_count++;
			i++;
			j++;
		}

	}
	if (result_count > 0)
	{
		for (int i = 0; i < result_count; i++)
		{
			cout << result[i] << ' ';
		}
	}
	else
	{
		cout << "No";
	}
	cout << endl;

	return 0;
}