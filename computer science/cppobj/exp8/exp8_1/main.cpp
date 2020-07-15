#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
    fstream frw;
    fstream f2;
    int data[20];
    cout << "请输入20个数字:";
    for (int i = 0; i < 20; i++)
    {
        cin >> data[i];
    }
    cout << "我们正在向a.dat写入前10个数字的数据，请稍后." << endl;
    frw.open("a.dat", ios::out | ios::binary);
    for (int i = 0; i < 10; i++)
    {
        cout << data[i] << " ";
        frw.write((char*)(data + i), sizeof(int));
    }
    frw.close();
    cout << endl;

    cout << "我们正在向b.dat写入后10个数字的数据，请稍后." << endl;
    frw.open("b.dat", ios::out | ios::binary);
    for (int i = 10; i < 20; i++)
    {
        cout << data[i] << " ";
        frw.write((char*)(data + i), sizeof(int));
    }
    cout << endl;
    frw.close();

    cout << "我们正在从a.dat读取所有的数据，并追加到b.dat." << endl;
    frw.open("a.dat",ios::in | ios::binary);
    f2.open("b.dat", ios::app | ios::binary);
    int buffer = 0;
    while (frw.read((char*)&buffer,sizeof(int)) && !frw.eof())
    {
        cout << buffer << " ";
        f2.write((char*)& buffer, sizeof(int));
    }
    cout << endl;
    frw.close();
    f2.close();

    int offset = 0;
    frw.open("b.dat", ios::in | ios::binary);
    while (frw.read((char*)(data+offset),sizeof(int)) && !frw.eof())
    {
        cout << data[offset] << " ";
        offset++;
    }
    cout << endl;
    frw.close();
    
    cout << "正在排序，请稍后." << endl;
    sort(data, data + offset);

    cout << "正在向b.dat写所有数据" << endl;
    frw.open("b.dat", ios::out | ios::binary);
    for (int i = 0; i < offset; i++)
    {
        cout << data[i] << " ";
        frw.write((char*)(data + i), sizeof(int));
    }
    cout << endl;
    frw.close();

    return 0;
}
