#include<iostream>
using namespace std;

int main()
{
	cout << "输入一个字符串，判断其是否为回文" << endl;
	char str[100];
	cin >> str;
	int length = strlen(str);

	bool flag = true;
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - 1 - i])
		{
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}