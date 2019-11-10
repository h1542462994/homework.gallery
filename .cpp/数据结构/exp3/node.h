// ---- Foundation ----
// Created by cht.
// #relates
// node: 节点
// node_fac: node生成器
// #endrelates
#pragma once
#include<initializer_list>
#include<stdexcept>
#include"callbacks.h"

using namespace std;

template <typename T>
class node {
public:
    explicit node(T value, node<T>* next = nullptr):value(value), next(next){}
    T value;
    node<T>* next;
private:

};

class node_fac{
public:
    template <typename T>
    static node<T>* create(initializer_list<T> data){
        auto head = new node<T>(*data.begin());
        auto c = head;
        for(auto p = data.begin() + 1; p < data.end(); ++p){
            c = append(c,*p);
        }
        return head;
    }

    template <typename T, typename T2>
    static node<T>* create(T2 begin, T2 end){
        auto head = new node<T>(*begin);
        auto c = head;
        for(auto p = begin+1;p< end;++p){
            c = append(c,*p);
        }
        return head;
    }

    template <typename T>
    static node<T>* append(node<T>* pre, node<T>* next){
        pre->next = next;
        return next;
    }

    template <typename T>
    static node<T>* append(node<T>* pre, T value){
        auto c = new node<T>(value);
        return append(pre,c);
    }

    template <typename T>
    static void insert(node<T>* pre, node<T>* next, node<T>* insert){
        pre->next = insert;
        insert->next = next;
    }

    template <typename T>
    static void insert(node<T>* pre,node<T>* next, T value){
        auto c = new node<T>(value);
        insert(pre,next,c);
    }

    template <typename T>
    static void remove_next(node<T>* pre){
        node<T>* to_remove = pre->next;
        if(to_remove == nullptr){
            throw logic_error("the removed node is nullptr");
        }
        node<T>* next = to_remove->next;
        pre->next = next;
        delete to_remove;
    }

    template <typename T>
    static node<T>* offset(node<T>* n,int length){
        while(length > 0){
            if(n == nullptr){
                throw overflow_error("node is nullptr in loop");
            }
            n=n->next;
            --length;
        }
        return n;
    }

    template <typename T>
    static node<T>* remove_where(node<T>* head, node<T>* to_remove){
        if(head == nullptr || to_remove == nullptr){
            throw logic_error("node head/to_remove is nullptr");
        } else if(head == to_remove){
            auto c = head->next;
            delete head;
            return c;
        } else {
            auto c = head;
            while(c!= nullptr){
                auto p1 = c;
                auto p2 = c->next;
                if(p2 == to_remove){
                    p1->next = p2->next;
                    delete p2;
                    return head;
                }
                c = c->next;
            }
        }

    }

    template <typename T>
    static node<T>* remove_at(node<T>* head, int index){
        if(index < 0){
            throw range_error("index must be a optimistic number or zero.");
        } else if(index == 0){
            return remove_where(head,head);
        }
        auto c = head;
        while(index > 1){
            if(c== nullptr){
                throw overflow_error("the removed node is nullptr");
            }
            c=c->next;
            --index;
        }

        auto p1 = c->next;
        auto p2 = p1->next;
        c->next = p2;
        delete p1;
        return head;
    }

    template <typename T>
    static void for_any(node<T>* head, action_callback<T>& callback){
        while(head!=nullptr){
            callback.call(head->value);
            head = head->next;
        }
    }

    template <typename T>
    static void destroy(node<T>* head){
        node<T>* curr = head;
        node<T>* temp = nullptr;
        while(curr != nullptr){
            temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
private:

};