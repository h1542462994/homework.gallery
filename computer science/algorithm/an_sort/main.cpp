#include <iostream>
#include <sstream>
#include "msort.h"
#include "sorthelper.h"

using namespace std;
int main() {
    string a;
    while(cout << "please input the index:",cin >> a && a != "q"){
        int v[] = {4, 59, 7, 23, 61, 55, 46};
        int element_count = 7;
        stringstream s(a);
        int at;
        s >> at;
        int result = m_line_select(v, v+ element_count, at - 1, 0);
        cout << "the element at " << at << " is " << result << endl;
    }

    cout << "input the size and the index:" ;
    int size; int index;
    cin >> size >> index;

    sorthelper helper;
    helper.test_select(10000, index-1);

//    cout << "input the range [0,x] and the size:";
//    int max_n, size;
//    cin >> max_n >> size;
//
//    sorthelper sorthelper(max_n);
//    sorthelper.test_a_size(size);

    return 0;
}
