#include<iostream>
using namespace std;

double getItem(int i)
{
	return (i % 2 ? 1 : -1)*1.0 / (i * (i + 1));
}
int main()
{
	cout << "求数列前n项和,请输入n:";

	double result = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		result += getItem(i);
	}

	cout << result;

	return 0;

}
