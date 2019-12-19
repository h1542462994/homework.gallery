#include <iostream>
#include <ctime>
#include <sys/utime.h>
#include "sorthelper.h"
#include "msort.h"

using namespace std;
int main() {
    for(int i = 6000; i < 54000; i+= 4000){
        test_a_size(i);
        cout << endl;
    }
}
