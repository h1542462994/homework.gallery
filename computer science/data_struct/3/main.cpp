#include<iostream>
#include"minilist.h"

using namespace std;

int main() 
{

	minilist<int> list1 = { 1,8,2 };
	minilist<int> list2 = { 5,9,12 };

	list1.mySort();
	cout << list1 << endl;


	list1.join_sort(list2);

	cout << list1 << endl;

	system("pause");
}