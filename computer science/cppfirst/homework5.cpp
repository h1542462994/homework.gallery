#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

int main() 
{
	typedef long double ld;
	cout << "这是一个根据泰勒公式求sin(x)的近似值的一个小程序." << endl
		<< "现在，请输入自变量x的值和绝对误差限eps:";
	double x, eps;
	cin >> x >> eps;

	if (x < 0 || x > 10)
	{
		cout << "x error" << endl;
	}
	else if (eps <= 0)
	{
		cout << "error,the eps should be a positive value.";
	}
	else
	{
		ld result = 0, t, c_head = x, c_tail = 1;
		int f = 1;
		int i = 1;
		do
		{
			t = f * c_head / c_tail;
			result += t;

			i++;
			f = -f;
			c_head *= x * x;
			c_tail *= (2 * i - 2) * (2 * i - 1);

		} while (abs(t) > eps);


		cout << setiosflags(ios::fixed);
		cout << setprecision(3) << result << endl;
	}

	return 0;
}