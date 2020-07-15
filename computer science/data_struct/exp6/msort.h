//
// Created by cht on 2019/12/18.
//
#pragma once

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
        for(pj = pi; pj >= start; pj--){
            if(compare (*(pj-1), temp) )
                *pj = *(pj-1);
            else
                break;
        }
        *(pj) = temp;
    }
}

int* quick_v(int* start, int* end, int direction = 0){
    int temp = *start;
    while(start < end){
        while(start < end && !compare(temp,*end)){
            end--;
        }
        *start = *end;
        while(start < end && !compare(*start, temp)){
            start++;
        }
        *end = *start;
    }
    *start = temp;
    return start;
}

void _m_quick_sort(int* start, int* end, int direction = 0){
    if(start < end){
        int* middle = quick_v(start, end, direction);
        _m_quick_sort(start, middle-1 ,direction);
        _m_quick_sort(middle+1, end, direction);
    }
}

void m_quick_sort(int* start, int* end, int direction = 0){
    _m_quick_sort(start, end-1);
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