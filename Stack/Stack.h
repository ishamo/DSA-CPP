#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <cassert>
using namespace std;


struct Node{
        int data;
        Node* next;
};

class Stack{
public:
        Stack():Count(0), top(NULL){}
        ~Stack();
        void Push(int x);
        int Pop();
        void Print();
private:
        int Count;
        Node* top;
};

void Stack::Push(int x)
{
        if (Count == 0)         //表明栈为空,那么我插入的这个结点就成为了第一个结点
        {
                Node* p = new Node;
                p->data = x;
                p->next = NULL;
                top = p;
                Count  = 1;
        }
        else
        {
                Node *p = new Node;
                p->data = x;
                p->next = top;
                top = p;
                Count += 1;
        }
}

int Stack::Pop()
{
        int ret;
        if (Count != 0 && top != NULL)
        {
                ret = top->data;
                Count --;
                Node *p = top;
                top = top->next;
                delete p;
                return ret;
        }
        return -1;       //返回-1表示栈为空,却返回了值 . 可以用来作为判断.
}

Stack::~Stack()
{
        while (top != NULL)
        {
                Node* tmp = top;
                top = top->next;
                delete tmp;
        }
}

void Stack::Print()
{
        Node* p = top;
        while (p != NULL)
        {
                cout << p->data << " ";
                p = p->next;
        }
}

#endif // STACK_H_INCLUDED
