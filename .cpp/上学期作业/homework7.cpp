#include<iostream>
#include<vector>
using namespace std;

bool isshuixianhuanumber(int value)
{
	int h = value / 100;
	int s = (value - h * 100) / 10;
	int g = value % 10;
	if (value == h * h * h + s * s * s + g * g * g)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	cout << "这是一个在给定范围内输出水仙花数的小程序:" << endl
		<< "现在，请依次输入范围的最小值(minvalue)和最大值(maxvalue):";
	int minvalue, maxvalue;
	vector<int> results;
	cin >> minvalue >> maxvalue;
	if ((minvalue < 100 || minvalue >= 1000) || (maxvalue < 100 || maxvalue >= 1000))
	{
		cout << "argument error:the minvalue or maxvalue should be in the range of 101~999.";
	}
	else if (minvalue > maxvalue)
	{
		cout << "argument error:the minvalue should equal to or less than the maxvalue";
	}
	else
	{
		for (int i = minvalue; i < maxvalue; i++)
		{
			if (isshuixianhuanumber(i))
			{
				results.push_back(i);
			}
		}
		for (int i = 0; i < results.size(); i++)
		{
			cout << results[i];
			if (i < results.size() - 1)
			{
				cout << ' ';
			}
		}
	}

	return 0;
}