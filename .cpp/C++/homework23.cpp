#include<iostream>
using namespace std;

void min_max_mean(int a[], int n, int *max_val, int *min_val, int *mean_val)
{
	int min = a[0]; int max = a[0]; int sum = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
		sum += a[i];
	}
	*max_val = max; *min_val = min; *mean_val = sum / n;
	return;
}
int main()
{
	int min, max, average;
	int n; int a[100];
	cout << "统计数组最小，最大，平均值" << endl;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	min_max_mean(a, n, &max, &min, &average);

	cout << "max=" << max << " min=" << min << " average=" << average << endl;

	return 0;
}