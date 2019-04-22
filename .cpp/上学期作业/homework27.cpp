#include<iostream>
using namespace std;

bool issquareE(int *first, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j && first[size * i + j] != 1)
			{
				return false;
			}
			else if (i != j && first[size * i + j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}
int main()
{
	cout << "判断N*N矩阵是否为单位矩阵，N由控制台输入。" << endl;
	int n;
	cin >> n;
	int *a = new int[n*n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i * n + j];
		}
	}

	if (issquareE(a, n))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}