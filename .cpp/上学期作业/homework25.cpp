#include<iostream>
#include<cstdio>
using namespace std;

int my_strcmp(char *str1, char *str2)
{
	int i = 0;
	while (str1[i] == str2[i])
	{
		//说明两个字符串都结束且相等。
		if (str1[i] = '\0')
		{
			return 0;
		}
		i++;
	}
	return str1[i] - str2[i];
}
int main()
{
	cout << "比较两个字符串是否相等:" << endl;

	char str1[100], str2[100];
	gets_s(str1, 99);
	gets_s(str2, 99);

	cout << my_strcmp(str1, str2) << endl;

	return 0;
}