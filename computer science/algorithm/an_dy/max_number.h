//
// Created by t1542 on 2020/5/18.
//
#include <vector>
#pragma once

using namespace std;

// 使用二层循环求最大字段和的问题
int max_number_loop(vector<int>& input, int& start, int& end){
    int length = input.size();
    int max = input[0];
    start = 0; end = 1;
    for(int i = 0; i < length; ++i){
        int temp = 0;
        for(int j = i; j < length; ++j){
            temp += input[j];
            if(temp > max){
                max = temp;
                start = i;
                end = j + 1;
            }
        }
    }

    return max;
}

// 使用分治法求最大字段和的问题
int max_number_division(vector<int>& input, int& start, int& end){
    // stop condition:;;;
    if(start == end - 1){
        return input[start];
    }

    int middle = (start + end) / 2;
    int max_start = middle;
    int max_end = middle + 1;
    // condition1: through middle
    int max = input[middle];
    int temp = max;
    for(int i = middle - 1; i >= start; --i){
        temp = temp + input[i];
        if(temp > max){
            max = temp;
            max_start = i;
        }
    }
    temp = max;
    for(int j = middle + 1; j < end; ++j){
        temp = temp + input[j];
        if(temp > max){
            max = temp;
            max_end = j + 1;
        }
    }

    int temp_start = start;
    int temp_end = middle;
    int temp_max;

    if(temp_start + 1 <= temp_end){
        // condition 2: left?
        temp_max = max_number_division(input, temp_start, temp_end);
        if(temp_max > max){
            max_start = temp_start;
            max_end = temp_end;
            max = temp_max;
        }
    }

    temp_start = middle + 1;
    temp_end = end;
    if(temp_start + 1 <= temp_end){
        // condition 3: right?
        temp_max = max_number_division(input, temp_start, temp_end);
        if(temp_max > max){
            max_start = temp_start;
            max_end = temp_end;
            max = temp_max;
        }
    }


    start = max_start;
    end = max_end;
    return max;
}

// 使用动态规划求最大字段和的问题
int max_number_dy(vector<int>& input, int& start, int & end){
    int max_start = 0;
    int max_end = 1;
    int max = input[0];

    int temp_start = max_start;
    int temp_end = max_end;
    int temp = max;
    for (int i = 1 ; i < input.size();++i){
        if(temp < 0){ // deprecate
            temp_start = i;
            temp_end = i + 1;
            temp = input[i];
        } else {
            temp_end = i + 1;
            temp = temp + input[i];
        }
        if(temp > max){
            max = temp;
            max_start = temp_start;
            max_end = temp_end;
        }
    }

    start = max_start;
    end = max_end;
    return max;
}