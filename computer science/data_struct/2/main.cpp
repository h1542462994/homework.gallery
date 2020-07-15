#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void bubblesort(T start, T end, int direction = 0) 
{
	int length = end - start;
	for (int pointi = 0; pointi < length - 1; pointi++)
	{
		for (T pointj = end - 1; pointj > start + pointi; pointj--) 
		{
			if ((direction > 0 && pointj[0] > pointj[-1]) || (direction <= 0 && pointj[0] < pointj[-1])) 
			{
				swap(pointj[0], pointj[-1]);
			}
		}
	}
}

int main() 
{
	int arrayInt[] = { 10,7,6,8,2,6,13,17 };
	int size = 8;
	vector<int> vectorInt = { 1,9,22,14,8,4,11,6 };

	bubblesort(arrayInt, arrayInt + size);
	bubblesort(vectorInt.begin(), vectorInt.end());
	for (int i = 0; i < 8; i++)
	{
		cout << arrayInt[i] << " ";
	}
	for (int i = 0; i < vectorInt.size(); i++)
	{
		cout << vectorInt[i] << " ";
	}
	cout << endl;
}