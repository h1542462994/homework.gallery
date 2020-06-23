#include<iostream>
using namespace std;

char *substr(char *str, int length)
{
	char *temp = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	temp[length] = '\0';

	return temp;
}
int main()
{
	cout << "截取字符串." << endl;
	char str[100]; int n;
	gets_s(str);
	cin >> n;
	cout << substr(str, n);

	return 0;
}