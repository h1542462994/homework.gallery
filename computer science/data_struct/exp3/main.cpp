#include <iostream>
#include "i_queue.h"
#include "i_dstack.h"

using namespace std;

template <typename T>
void remove_target(i_queue<T>& queue, T target){
    i_queue<T>* other = new list_queue<T>();
    bool find = false;
    while(!queue.empty()){
        auto front = queue.front();
        if((!find && target!=front) || find){
            other->push(front);
        } else {
            find = true;
        }
        queue.pop();
    }

    while(!other->empty()){
        queue.push(other->front());
        other->pop();
    }

    delete other;

}

template <typename T>
void read_queue(i_queue<T>& queue){
    while(!queue.empty()){
        cout << queue.front() << " " ;
        queue.pop();
    }
    cout << endl;
}

void test_remove_target(){
    cout << "test remove_target" << endl;
    i_queue<int>* queue = new list_queue<int>();
    for(int i = 0; i< 10;++i){
        queue->push(i);
    }
    remove_target(*queue,7);
    read_queue(*queue);

    delete queue;
}

void test_dstack(){
    cout << "test dstack" << endl;
    i_dstack<int>* dstack = new array_stack<int>();
    for(int i = 0;i< 5 ;++i){
        dstack->push(i);
    }
    for (int i = 11; i < 20; ++i) {
        dstack->push(i,dstack_direct::second);
    }

    cout << "first stack:" << endl;
    while(!dstack->empty()){
        cout << dstack->top() << " ";
        dstack->pop();
    }
    cout << endl;
    cout << "second stack:" << endl;
    while(!dstack->empty(dstack_direct::second)){
        cout << dstack->top(dstack_direct::second) << " ";
        dstack->pop(dstack_direct::second);
    }
    cout << endl;

}

int main(){
    test_remove_target();
    test_dstack();

    return 0;
}