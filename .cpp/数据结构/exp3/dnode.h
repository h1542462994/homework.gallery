// ---- Foundation ----
// Created by cht.
// #relates
// dnode: 双端节点
// dnode_fac: dnode工厂类
// #endrelates
#pragma once
#include <stdexcept>
#include "callbacks.h"

using namespace std;

template <typename T>
class dnode{
public:
    explicit dnode(T value, dnode<T>* pre = nullptr, dnode<T>* next = nullptr): value(value), pre(pre), next(next){

    }
    T value;
    dnode<T>* pre;
    dnode<T>* next;
private:

};

class dnode_fac{
public:
    template <typename T>
    static dnode<T>* create(initializer_list<T> data){
        auto first = new dnode<T>(*data.begin());
        auto c= first;
        for(auto p = data.begin()+1; p != data.end(); ++p){
            c= append_back(c,*p);
        }
        return first;
    }

    template <typename T>
    static dnode<T>* append_back(dnode<T>* pre, dnode<T>* next){
        pre->next = next;
        next->pre = pre;
        return next;
    }

    template <typename T>
    static dnode<T>* append_pre(dnode<T>* next, dnode<T>* pre){
        next->pre = pre;
        pre->next = next;
        return pre;
    }

    template <typename T>
    static dnode<T>* append_back(dnode<T>* pre, T value){
        auto c = new dnode<T>(value);
        return append_back(pre,c);
    }

    template <typename T>
    static dnode<T>* append_pre(dnode<T>* next, T value){
        auto c = new dnode<T>(value);
        return append_pre(next,c);
    }

    template <typename T>
    static dnode<T>* for_any(dnode<T>* first,action_callback<T>& callback){
        while(first!=nullptr){
            callback.call(first->value);
            first= first->next;
        }
    }

    template<typename T>
    static dnode<T>* for_any_flag(dnode<T>* first,action_callback<T>& callback){
        auto curr = first;
        while(curr!= nullptr){
            callback.call(curr->value);
            curr = curr->next;
            if(curr == first){
                break;
            }
        }
    }

    template <typename T>
    static bool unique(dnode<T>* head){
        return head->next == nullptr || head->next == head;
    }

    template<typename T>
    static void join(dnode<T>* pre, dnode<T>* next){
        pre->next = next;
        next->pre = pre;
    }

    template <typename T>
    static dnode<T>* remove_front(dnode<T>* front){
        auto c = front;
        auto p = front->next;
        if(p != nullptr){
            p->pre = nullptr;
        }
        delete c;
        return p;
    }

    template <typename T>
    static dnode<T>* remove_back(dnode<T>* back){
        auto c= back;
        auto p = back->pre;
        if(p != nullptr){
            p->next = nullptr;
        }
        delete c;
        return p;
    }

    template <typename T>
    static dnode<T>* remove_self_return_pre(dnode<T>* self){
        auto prev_node = self->pre;
        if(prev_node == nullptr){
            throw logic_error("the prev_node of self is nullptr");
        }
        auto next_node = self->next;
        prev_node->next = next_node;
        if(next_node != nullptr){
            next_node->pre = prev_node;
        }
        delete self;

        return prev_node;
    }

    template <typename T>
    static dnode<T>* remove_self_return_next(dnode<T>* self){
        auto prev_node = self->pre;
        auto next_node = self->next;
        if (next_node == nullptr){
            throw logic_error("the next_node of self is nullptr");
        }
        if(prev_node != nullptr){
            prev_node->next = next_node;
        }
        next_node->pre = prev_node;
        delete self;

        return next_node;
    }

    template <typename T>
    static void remove(dnode<T>* self){
        auto prev_node = self->pre;
        auto next_node = self->next;
        if(prev_node != nullptr){
            prev_node -> next = next_node;
        }
        if(next_node != nullptr){
            next_node->pre = prev_node;
        }
        delete self;
    }

    template <typename T>
    static dnode<T>* offset(dnode<T>* n,int offset){
        if(offset == 0){
        } else if (offset > 0){
            while(offset > 0){
                n = n->next;
                --offset;
            }
        } else  {
            while(offset < 0){
                n = n ->pre;
                ++offset;
            }
        }
        return n;
    }

    template <typename T>
    static void destroy(dnode<T>* head){
        dnode<T>* curr = head;
        dnode<T>* temp = nullptr;
        while(curr!= nullptr){
            temp = curr;
            curr = curr->next;
            if(curr == head){
                break;
            }
            delete temp;
        }
    }
};