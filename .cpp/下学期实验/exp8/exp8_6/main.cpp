#include<iostream>
#include<iomanip>
using namespace std;

int main() 
{
	double each = 0.01, sum_a = 0.0, sum_b = 0.0;
	cout << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2);
	for (int i = 0; i < 30; i++)
	{
		sum_a += each;
		sum_b += 100000;
		each *= 2;

		cout << "第" << setw(2) << i + 1 << "天，陌生人得到的钱为："
			<< setw(12) << sum_a << "元" << "   第"
			<< setw(2) << i + 1 << "天，富翁得到的总钱数为：" << setw(12) << sum_b << endl;
	}

	cout << endl
		<< "第30天后，陌生人得到的总钱数为:" << setw(12) << sum_a << endl
		<< "第30天后，富翁能得到的总钱数为:" << setw(12) << sum_b << endl
		<< "第30天后，富翁亏损的总钱数为:  " << setw(12) << sum_a - sum_b << endl
		<< "富翁哭哭哭哭哭哭了" << endl;

	//system("pause");
	return 0;
}