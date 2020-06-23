#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	cout << "输入字符串，连接该字符串与其镜像字符串，并输出处理结果." << endl;
	char str[200], str_mirror[100];

	cin >> str;
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		str_mirror[length - 1 - i] = str[i];
	}
	str_mirror[length] = '\0';
	strcat_s(str, str_mirror);
	cout << str << endl;

	return 0;
}