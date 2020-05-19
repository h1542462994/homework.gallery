#include <iostream>
#include <sstream>
#include <vector>
#include "max_string.h"
#include "max_number.h"
#include "sorthelper.h"

using namespace std;
int main() {
//    cout << "please input string a:" << endl;
//    string a,b;
//    getline(cin, a);
//    cout << "please input string b:" << endl;
//    getline(cin, b);
//    int** arr = construct_arr(a, b);
//    //cout << "arr:" << endl;
//    //print_arr(arr, a.length(), b.length());
//
//    string c = get_string(arr, a, b);
//    cout << "str:" << endl;
//    cout << c << endl;

//    cout << "please input the numbers:" << endl;
//    string d;
//    getline(cin, d);
//    istringstream istr_stream(d);
//    vector<int> input;
//    int temp;
//    while(istr_stream >> temp){
//        input.push_back(temp);
//    }
//
//    int start = 0; int end = input.size();
//
//    int result = max_number_loop(input, start, end);
//
//    cout << "(loop) max:" << result << endl;
//    cout << "numbers:" << endl;
//    for(int i = start; i < end; ++i){
//        cout << input[i] << " ";
//    }
//    cout << endl;
//
//    result = max_number_division(input , start, end);
//
//    cout << "(division) max:" << result << endl;
//    cout << "numbers:" << endl;
//    for(int i = start; i < end; ++i){
//        cout << input[i] << " ";
//    }
//    cout << endl;
//
//    result = max_number_dy(input, start, end);
//
//    cout << "(dy) max:" << result << endl;
//    cout << "numbers:" << endl;
//    for(int i = start; i < end; ++i){
//        cout << input[i] << " ";
//    }
//    cout << endl;

    sorthelper helper;
    helper.test(10000);

    return 0;
}
