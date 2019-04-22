/**
 * @description:很久前的一个题目，好像是计算身高体重的.
 */
#include<iostream>
using namespace std;

int main()
{
	cout << "这是一个测试你体型的小程序，输出为[标准，过胖，过瘦]其中之一。" << endl
		<< "现在，请输入你的身高(cm)和体重(kg)：";
	double height, weight;
	cin >> height >> weight;
	bool isinvalid = false;
	if (height <= 50 || height >= 250)
	{
		cout << "something unexpected happened:your height is invalid" << endl;
		isinvalid = true;
	}
	if (weight <= 25 || weight >= 500)
	{
		cout << "something unexpected happened:your weight is invalid" << endl;
		isinvalid = true;
	}
	if (!isinvalid)
	{
		double dvalue = weight - (height - 110);
		if (dvalue >= 5.0)
		{
			cout << "过胖" << endl;
		}
		else if (dvalue <= -5.0)
		{
			cout << "过瘦" << endl;
		}
		else
		{
			cout << "标准" << endl;
		}

	}

	return 0;
}