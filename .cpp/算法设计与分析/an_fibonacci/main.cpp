#include <iostream>
#include <iomanip>
#include "fibonacci.h"
#include "ubigint.h"

using namespace std;
int main() {
    cout << "please input the number to calculate:";
    int x;
    cin >> x;
    ubigint result(0);
    clock_t t1 = clock();
    result = fibonacci_stack(x);
    clock_t t2 = clock();
    cout << "f(" << x << ") = " << result << endl;
    cout << "total time: " << t2 - t1 << "ms";

//    cout << setw(6) << "i" << setw(10) << "loop" << setw(10) << "stack"  << setw(40) << "value" << endl;
//    bool stop = false;
//    for(int i = 10; i < 50; ++i){
//        cout << setw(10) << i;
//        ubigint a = 0;
//        for(int j = 0; j < 2; ++j){
//            clock_t start = clock();
//            if (j == 1){
//                if(!stop){
//                    fibonacci_stack(i);
//                }
//            } else {
//                a = fibonacci_loop(i);
//            }
//            clock_t end = clock();
//            if(stop && j == 1){
//                cout << setw(10) << "-";
//            } else {
//                cout << setw(10) << end - start;
//            }
//
//            if(j == 1 && (end - start) > 10000){
//                stop = true;
//            }
//        }
//        cout << setw(10) << a;
//        cout << endl;
//    }


    //cout << fibonacci_stack(20) << endl;
    //cout << fibonacci_loop(20) << endl;
}
