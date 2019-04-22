#include<iostream>
#include<iomanip>
using namespace std;

void print_pascal_triangle(int lines)
{
	int data[20][20] = { 0 };
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				data[i][j] = 1;
			}
			else if (i > 0)
			{
				data[i][j] = data[i - 1][j - 1] + data[i - 1][j];
			}

			cout << setw(7) << data[i][j];
		}
		cout << endl;
	}


}
int main()
{
	cout << "打印n层的杨辉三角，请输入n:";
	int n;
	cin >> n;

	print_pascal_triangle(n);

	return 0;
}