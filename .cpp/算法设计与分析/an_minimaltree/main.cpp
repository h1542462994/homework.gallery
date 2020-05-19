#include <iostream>
#include <string>
#include "mat.h"
#include "photoi.h"

using namespace std;
int main() {
    cout << "input the matrix:" << endl;
    auto m = mat<int>::scan_square();
    auto m1 = mat<int>(0,0);
    //m.print();
    cout << endl;
    int length = 0;
    auto p = photoi(m);
    cout << "prim:" << endl;
    p.get_prim(m1, length);
    m1.print();
    cout << endl;
    cout << "prim_length:" << length << endl;

    cout << "kruskal:" << endl;
    p.get_kruskal(m1, length);
    m1.print();
    cout << endl;
    cout << "kruskal_length:" << length << endl;

    return 0;
}
