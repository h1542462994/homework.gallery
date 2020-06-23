#include"Stack.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
    Stack<string&> stack;
    string a = "hello", b = "world", c = "echo";

    //for (int i = 0; i < 10; i++)
    //{
    //	stack.push(i);
    //}
    stack.push(a);
    stack.push(b);
    stack.push(c);

    string value;
    while (stack.tryPop(value))
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}