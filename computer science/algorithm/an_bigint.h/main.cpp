#include <iostream>
#include "big_int.h"
#include <string>

using namespace std;
int main() {
    cout << "please input the number a and b" << endl;
    string a,b;
    cin >> a >> b;
    big_int av = big_int::parse(a);
    big_int bv = big_int::parse(b);
    big_int result = av * bv;
    cout << "result is " << result << endl;

    return 0;
}
