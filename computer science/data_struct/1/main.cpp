#include<iostream>
using namespace std;

int main() {
	bool dooropen[150] = { 0 };
	for (int step = 2; step <= 150; step++)
	{
		for (int i = step; i <= 150; i+=step)
		{
			dooropen[i - 1] = !dooropen[i - 1];
		}
	}

	for (int i = 0; i < 150; i++)
	{
		cout << dooropen[i] ? "1" : "0";
	}
	cout << endl;

    return 0;
}