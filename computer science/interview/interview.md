```cpp
#include <iostream>
#include <string>

using namespace std;

int contains(string str, char c) {
    for(int i = 0; i < str.length(); ++i) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

class str_range {
public:
    str_range(string str, int startIndex, int endIndex) {
        this->str = str;
        this->startIndex = startIndex;
        this->endIndex = endIndex;
    }
    
    str_range(str_range& source) {
        this->str = source.str;
        this->startIndex = source.startIndex;
        this->endIndex = source.endIndex;
    }
    
    string str;
    int startIndex;
    int endIndex;
    
    char first() {
        return str[startIndex];
    }
    
    string sub() {
        return str.substr(startIndex, endIndex);
    }
    
    int length() {
        return endIndex - startIndex;
    }
};



int get_equal_length(str_range& range1, str_range& range2) {
    // 结束条件
    if(range1.length() == 1) {
        return contains(range2.sub(), range1.first());
    } else if(range2.length() == 1) {
        return contains(range1.sub(), range2.first());
    }
    str_range range3 = range1;
    range3.startIndex += 1;
    str_range range4 = range2;
    range4.startIndex += 1;
    if(range1.first() == range2.first()) {
        // 相等的清康
        return 1 + get_equal_length(range3, range4);
    } else {
        // 不相等的情况
        return max(get_equal_length(range3, range2), get_equal_length(range1, range4));
    }
    
}


int main() {
    //int a;
    //cin >> a;
    string str1, str2;
    cin >> str1 >> str2;
    str_range range1 = str_range(str1, 0, str1.size());
    str_range range2 = str_range(str2, 0, str2.size());
    
    int equal_length = get_equal_length(range1, range2);
    
    cout << equal_length << endl;
}
```