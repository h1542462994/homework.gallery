#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

char* transferstring(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}
	return str;
}
int main()
{
	cout << "改变字符串大小写字符，请输入一行字符串:" << endl;
	char * str = new char[1000];
	gets_s(str, 999);
	cout << transferstring(str);

	delete str;
	return 0;
}