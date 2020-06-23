#include<iostream>
#include<cstdlib>
#include"intSorter.h"
using namespace std;

int main()
{
	int a[100];
	cout << "请输入元素的个数：" << endl;
	int n;
	cin >> n;
	cout << "请输入排序的方法(输出1选择升序，输入-1选择降序)：" << endl;
	int flag;
	cin >> flag;
	cout << "请输入数组元素（以空格隔开）" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	intSorter sorter(a, n, flag);
	sorter.sort();
	sorter.print();

	system("pause");
	return 0;
}