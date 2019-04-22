#include<iostream>
using namespace std;

int main()
{
	cout << "找出二维数组的鞍点，并输出其位置，本题数组规模为3*3" << endl;
	int a[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];

	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		int maxindexcolumn = 0;
		for (int j = 1; j < 3; j++)
		{
			if (a[i][j] > a[i][maxindexcolumn])
			{
				maxindexcolumn = j;
			}
		}

		int minindexrow = i;
		for (int j = 0; j < 3; j++)
		{
			if (a[j][maxindexcolumn] < a[minindexrow][maxindexcolumn])
			{
				minindexrow = j;
			}
		}

		if (minindexrow == i)
		{
			sum++;
			cout << minindexrow << ' ' << maxindexcolumn << endl;
			break;
		}
	}
	if (sum == 0)
	{
		cout << "不存在" << endl;
	}

	return 0;
}