#include "intSorter.h"
#include<iostream>
using namespace std;

intSorter::intSorter(int * arr, int length, int flag) :arr(arr), length(length), flag(flag)
{
}

void intSorter::sort()
{
	for (int i = 0; i < length - 1; i++)
	{
		int maxindex = i;
		for (int j = i + 1; j < length; j++)
		{
			if (flag == 1 && arr[j] < arr[maxindex])
			{
				maxindex = j;
			}
			else if (flag == -1 && arr[j] > arr[maxindex])
			{
				maxindex = j;
			}
		}
		if (maxindex != i)
		{
			int t = arr[i];
			arr[i] = arr[maxindex];
			arr[maxindex] = t;
		}
	}
}

void intSorter::print()
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
