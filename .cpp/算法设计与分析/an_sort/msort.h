//
// Created by t1542 on 2020/3/16.
//
//
// Created by cht on 2019/12/18.
//
#pragma once
#include<iostream>
using namespace std;

void m_swap(int* first, int* second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

bool compare(int first, int second, int direction = 0){
    if(direction >= 0 && first > second)
        return true;
    if(direction < 0 && first < second)
        return true;
    return false;
}

void m_bubble_sort(int* start, int* end, int direction = 0){
    for(int* pi = start; pi < end - 1 ; ++pi){
        for(int* pj = end - 1; pj > pi; --pj){
            if(compare(*(pj - 1),*pj, direction))
                m_swap(pj - 1, pj);
        }
    }
}

void m_select_sort(int* start, int* end, int direction = 0){
    for(int* pi = start; pi < end - 1; ++pi){
        int* temp = pi;
        for(int* pj = pi + 1; pj < end; ++pj){
            if(compare(*temp, *pj))
                temp = pj;
        }
        m_swap(pi, temp);
    }
}

void m_insert_sort(int* start, int* end, int direction = 0){
    for(int* pi = start + 1; pi < end; ++pi){
        int temp = *pi;
        int* pj = pi;
        for(pj = pi; pj > start; pj--){
            if(compare (*(pj-1), temp) )
                *pj = *(pj-1);
            else
                break;
        }
        *(pj) = temp;
    }
}

int* quick_v(int* start, int* end, int direction = 0){
    int* first = start;
    int temp = *start;
    --end;
    ++start;
    while(start < end){
        while(start < end && compare(*start, temp)){
            start++;
        }
        while(start <= end && compare(temp,*end)){
            end--;
        }
        if(start < end){
            int t = *start;
            *start = *end;
            *end = t;
            ++start;
            --end;
        }
    }
    int t = *end;
    *end = *first;
    *first = t;
    return end;
}

int m_line_select(int* start, int* end, int i, int direction = 0){
    int* p = quick_v(start, end, direction);
    int* target = start + i;
    if(p == target){
        return *p;
    } else if(target < p){
        return m_line_select(start, p, i, direction);
    } else {
        return m_line_select(p+1, end, i - (p - start), direction );
    }
}

void m_quick_sort(int* start, int* end, int direction = 0){
    if(start < end - 1){
        int* middle = quick_v(start, end, direction);
        m_quick_sort(start, middle ,direction);
        m_quick_sort(middle+1, end, direction);
    }
}

void adjust_heap(int* a, int node, int size){
    int left = 2*node + 1;
    int right = 2*node +2;
    int max = node;
    if(left < size && a[left] > a[max])
        max = left;
    if(right < size && a[right] > a[max])
        max = right;
    if(max != node){
        m_swap(a+max,a+node);
        adjust_heap(a, max, size);
    }
}

void m_heap_sort(int* start, int* end, int direction = 0){
    int len = end - start;
    for(int i = len/2 - 1; i >= 0; --i)
        adjust_heap(start, i, len);
    for(int i = len-1; i >= 0; --i){
        m_swap(start, start+i);
        adjust_heap(start, 0, i);
    }
}

void m_rx_sort(int* start, int* end, int d){
    int k = 10;
    int length = end - start;
    int* counts = new int[k];
    int* temp = new int[length];
    int index;
    int pval = 1;
    for(int i = 0 ;i < d; i++){
        for (int j = 0; j < k; ++j)
            counts[j] = 0;
        for(int*p = start; p < end; ++p){
            index = (*p / pval) % k;
            counts[index]++;
        }
        for(int j = 1; j < k;++j){
            counts[j] += counts[j-1];
        }
        for(int*p = end-1; p >= start;--p){
            index = (*p / pval) % k;
            temp[counts[index] - 1] = *p;
            counts[index]--;
        }

        for(int *p =start; p < end; ++p) {
            *p = temp[p - start];
        }
        pval*= k;
    }
    delete[] counts;
    delete[] temp;
}

void m_merge(int* start, int* end){
    int* mid = start + (end - start)/2;
    int* p1 = start;
    int* p2 = mid;
    int len = end-start;
    int* temp_arr = new int[len];
    int* p3 = temp_arr;
    while(p1 < mid && p2 < end) {
        if ((*p1 <= *p2)) {
            *p3 = *p1;
            ++p3;
            ++p1;
        } else if ((*p1 > *p2)) {
            *p3 = *p2;
            ++p3;
            ++p2;
        }
    }
    while(p1 < mid){
        *p3 = *p1;
        ++p3;
        ++p1;
    }
    while(p2 < mid){
        *p3 = *p2;
        ++p3;
        ++p2;
    }
    for (int i = 0; i < len;++i) {
        start[i] = temp_arr[i];
    }
    delete[] temp_arr;
}

void m_merge_sort(int* start, int* end){
    if(start >= end-1){
        return;
    } else {
        int* mid = start + (end - start)/2;
        m_merge_sort(start, mid);
        m_merge_sort(mid, end);
        m_merge(start, end);
    }
}

void m_count_sort(int* start, int* end, int max_n){
    int length = end - start;
    int* counter = new int[max_n];
    for (int i = 0; i < max_n; ++i) {
        counter[i] = 0;
    }
    int* container = new int[length];
    for(int* p = start; p < end; ++p){
        ++counter[*p];
    }
    for(int i = 1; i < max_n; ++i){
        counter[i] += counter[i - 1];
    }
    for(int* p = end - 1; p >= start; --p){
        //cout << *p << endl;
        container[--counter[*p]] = *p;
    }
    for(int i = 0; i < length; ++i){
        start[i] = container[i];
    }
    delete[] container;
    delete[] counter;
}