#include<iostream>
using namespace std;

void getrow_maxofsquare(int(*n)[3], int re[])
{
	for (int i = 0; i < 3; i++)
	{
		int max = **n;
		for (int j = 1; j < 3; j++)
		{
			if (*(*n + j) > max)
			{
				max = *(*n + j);
			}
		}
		re[i] = max;
		if (i < 2)
		{
			n++;
		}
	}
}
int main()
{
	cout << "求3*3矩阵每行最大值" << endl;

	int sq[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> sq[i][j];
		}
	}

	int re[3];
	getrow_maxofsquare(sq, re);

	for (int i = 0; i < 3; i++)
	{
		cout << re[i] << " ";
	}

	return 0;
}