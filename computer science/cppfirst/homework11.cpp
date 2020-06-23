#include<iostream>
#include<string>
using namespace std;

int main()
{
	int characters[5] = { 0 };
	string comments[5] = { "uppercase","lowercase","number","blank","other" };

	cout << "请以此输入3行文本，将统计各种字符的个数并输出。" << endl;

	for (int i = 0; i < 3; i++)
	{
		string line;
		getline(cin, line); //从istream读取一行文本string，返回istream;

		for (int i = 0; i < line.length(); i++)
		{
			char c = line[i];
			if (c >= 'A' && c <= 'Z')
			{
				characters[0]++;
			}
			else if (c >= 'a' && c <= 'z')
			{
				characters[1]++;
			}
			else if (c >= '0' && c <= '9')
			{
				characters[2] ++;
			}
			else if (c == ' ')
			{
				characters[3] ++;
			}
			else
			{
				characters[4] ++;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << comments[i] << ':' << characters[i] << endl;
	}

	return 0;
}
