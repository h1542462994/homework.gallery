#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "请输入一行文本，将输出转译后的文本。[其中大写字符+3，小写字符-3]" << endl;

	string line;
	getline(cin, line);

	for (int i = 0; i < line.length(); i++)
	{
		char c = line[i];
		if (c >= 'A' && c <= 'Z')
		{
			if (c >= 'X')
			{
				c = c + 3 - 26;
			}
			else
			{
				c = c + 3;
			}
		}
		else if (c >= 'a' && c <= 'z')
		{
			if (c <= 'c')
			{
				c = c - 3 + 26;
			}
			else
			{
				c = c - 3;
			}
		}
		line[i] = c;
	}

	cout << line;

	return 0;
}
