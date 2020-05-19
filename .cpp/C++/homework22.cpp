#include<iostream>
#include<iomanip>
using namespace std;

bool isprimenumber(int value)
{
	if (value <= 1)
	{
		return false;
	}
	else
	{
		int i = 2;
		while (i * i <= value)
		{
			if (value % i == 0)
			{
				return false;
			}
			i++;
		}
		return true;
	}
}
int *selectprime(int *source, int length, int*count)
{
	int *result = new int[length];
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (isprimenumber(source[i]))
		{
			result[index] = source[i];
			index++;
		}
	}

	*count = index;
	return result;
}
void sort_insert(int source[], int length)
{
	//当前有序列的长度
	for (int j = 1; j < length; j++)
	{
		int insert_at = j;
		for (int i = 0; i < j; i++)
		{
			if (source[i] > source[j])
			{
				insert_at = i;
				break;
			}
		}
		if (insert_at != j)
		{
			int temp = source[j];
			for (int i = j - 1; i >= insert_at; i--)
			{
				source[i + 1] = source[i];
			}
			source[insert_at] = temp;
		}
	}
}
int main()
{
	cout << "输入数组，找出其中的质数并排序输出,输入长度n和对应的数组." << endl;
	int a[100], n;
	cin >> n;
	int prime_count;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int *result = selectprime(a, n, &prime_count);
	sort_insert(result, prime_count);

	for (int i = 0; i < prime_count; i++)
	{
		cout << setw(5) << result[i];
	}

	return 0;
}