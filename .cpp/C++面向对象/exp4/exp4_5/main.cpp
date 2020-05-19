#include"carray.h"
#include<iostream>
using namespace std;

int main() 
{

    carray<string> c = { "1","2","1","1" };
    cout << "数组的长度为" << c.length() << endl;
    cout << "数组下标1的元素为" << c[1] << endl;
    cout << "打印数组" << endl;
    c.Print();
    int result[10];
    int length;
    length = c.Search("1", result);
    cout << "1的个数为" << length << "个" << endl;
    cout << "分别在下标";
    for (int i = 0; i < length; i++)
    {
        cout << result[i] << ",";
    }
    cout << "处" << endl;

    return 0;
}