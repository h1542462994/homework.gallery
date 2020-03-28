#include <iostream>
#include "matrix.h"
#include <vector>
#include <cmath>

using namespace std;
int main() {
    matrix A = {
            {4, -1, 0, -1, 0, 0},
            {-1, 4, -1, 0, -1, 0},
            {0, -1, 4, -1, 0, -1},
            {-1, 0, -1, 4, -1, 0},
            {0, -1, 0, -1, 4, -1},
            {0, 0, -1, 0, -1, 4}
    };

    matrix b = {
            {0},
            {5},
            {-2},
            {5},
            {-2},
            {6}
    };

    A.print_with_title("A");
    //A.print_with_title("A");
    matrix D = A.get_dialog();
    matrix B = (D ^ -1) * (D - A);
    B.print_with_title("B");
    matrix f = (D ^ -1) * b;
    matrix x0 = {{1},{1},{1},{1},{1},{1}};
    matrix x1 = x0;
    double eps = 0.001;
    double ir = 0;

    //int index = 0;
    vector<double> results;
    do{
        //++index;
        x0 = x1;
        x1 = B * x0 + f;
        ir = (x1 - x0).vector_norm2();

        results.emplace_back(log(ir));
        //cout << index << ":" << ir << endl;
        //x1.print_with_title("x?");

    } while(ir > eps);

    x1.print_with_title("x = ");

    int length = results.size();
    cout << "x = [";
    for (int i = 0; i < length; ++i) {
        cout << (i + 1) << " ";
    }
    cout << "]" << endl << "y = [";
    for (int i = 0; i < length; ++i) {
        cout <<  results[i] << " ";
    }
    cout << "]" << endl;

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
