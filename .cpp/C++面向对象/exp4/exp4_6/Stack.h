#include<exception>
#include<vcruntime.h>

template<typename T>
class Node {
public:
    //节点初始化
    Node(T value, Node<T>* node) :value(value),node(node)//此构造函数只能使用初始化表来初始化，因为要兼容引用T。
    {
    }
    T getValue()
    {
        return this->value;
    }
    Node<T>* getNode() 
    {
        return this->node;
    }

private:
    T value;
    Node* node;
};

template<typename T>
class Stack 
{
public:
    Stack()
    {
        last = NULL;
    }
    bool empty() 
    {
        return last == NULL;
    }
    T peek() 
    {
        if (last == NULL)
        {
            throw new exception("栈顶为空");
        }
        else
        {
            return *last->getValue();
        }
    }
    bool tryPeek(T& value) 
    {
        if (last == NULL)
        {
            return false;
        }
        else
        {
            value = peek();
            return true;
        }
    }
    void push(T value) 
    {
        Node<T>* newlast = new Node<T>(value, last);
        last = newlast;
    }
    T pop()
    {
        if (last == NULL)
        {
            throw new exception("栈顶为空");
        }
        else
        {
            T value = last->getValue();
            Node<T>* pre = last->getNode();
            delete last;
            last = pre;
            return value;
        }
    }
    bool tryPop(T& value) 
    {
        if (last == NULL)
        {
            return false;
        }
        else
        {
            value = pop();
            return true;
        }
    }
    int size() 
    {
        Node<T>* node = last;
        int length = 0;

        while (node != NULL)
        {
            ++length;
            node = last->getNode();
        }
        return length;
    }
private:
    Node<T>* last;
};