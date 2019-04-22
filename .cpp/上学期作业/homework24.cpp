#include<iostream>
#include<cstdio>
using namespace std;

int my_strlen(char *str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return i;
}
int main()
{
	char str[100];

	cout << "求字符串长度:" << endl;
	gets_s(str, 99);
	cout << my_strlen(str) << endl;

	return 0;
}