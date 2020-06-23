#include <iostream>
#include "matrix.h"

using namespace std;
int main() {
    matrix<float> m(4,5);
    m.set({{1.1348, 3.8326, 1.1651, 3.4017, 9.5342},
           {0.5301, 1.7875, 2.5330, 1.5435, 6.3941},
           {3.4129, 4.9317, 8.7643, 1.3142, 18.4231},
           {1.2371, 4.9998, 10.6721, 0.0147, 16.9237}});
    m.set_x({"x1","x2","x3","x4"});
    matrix<float> m2 = m;

    m.print_m_with();
    cout << ">>>>gs<<<<" << endl;
    m.gs();
    m.print_m_with();
    m.p_solve();
    cout << ">>>>main_gs<<<<" << endl;
    m2.main_gs();
    m2.print_m_with();
    m2.p_solve();

    //cout << "hello world!" << endl;
    return 0;
}
