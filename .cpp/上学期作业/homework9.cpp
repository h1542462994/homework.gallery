#include<iostream>
#include<string>
#include<vector>
using namespace std;
string getbitfromdec(int value)
{
	vector<char> bits(0);
	int absolutevalue = abs(value);

	do
	{
		bits.push_back(absolutevalue % 2);
		absolutevalue /= 2;
	} while (absolutevalue > 0);

	string result = "";
	if (value < 0)
	{
		result += '-';
	}

	for (int i = bits.size() - 1; i >= 0; i--)
	{
		result += bits[i] + 48;
	}

	return result;
}
int main()
{
	cout << "请重复输入一个正整数，我将输出它对应的二进制数串，直到你输入一个非正整数为止:" << endl;
	int number;
	while (cin >> number && number > 0)
	{
		cout << getbitfromdec(number) << endl;
	}

	return 0;
}