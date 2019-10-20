#include<iostream>
#include"minilist.h"

using namespace std;

int main() 
{
	minilist<int> list;
	list.append(1);
	list.append(3);
	list.append(5);

	cout << "count = " << list.length() << endl;
	cout << "element = " << endl;
	cout << list << endl;
	cout << "insert 10 at index:2" << endl;
	list.insertAt(10, 2);
	cout << list << endl;
	
	list.reserve();
	cout << list << endl;
}