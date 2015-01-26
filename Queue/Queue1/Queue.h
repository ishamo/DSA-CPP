#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#include <cassert>
using namespace std;

struct Node{
        int data;
        Node* next;
};

class Queue{            //队尾入队,队头出队
public:
        Queue():first(NULL), last(NULL), Count(0){}
        ~Queue();

        void Push(int x);
        int Pop();
        void Print();
private:
        Node* first;         //first指向队列的头元素
        Node* last;          //last指向队列的尾元素
        int Count;
};

void Queue::Push(int x)         //入队
{
        assert(Count >= 0);
        if (Count == 0)
        {
                Node *p = new Node;
                p->data = x;
                p->next = NULL;
                first = p;
                last = p;
                Count = 1;
        }
        else
        {
                Node *p = new Node;
                p->data = x;
                p->next = NULL;
                last->next = p;
                last = p;
                Count ++;
        }
}

int Queue::Pop()        //出队
{
        int ret;
        assert(Count >= 0);
        if (Count == 0)         //表明队列本来就是空的
        {
                ret = -1;
                return ret;             //队列为空的话返回-1
        }
        else
        {
                ret = first->data;
                Node*  p = first;
                first = first->next;
                delete p;
                Count --;
                return ret;
        }
}

void Queue::Print()
{
        Node* p = first;
        while (p != NULL)
        {
                cout << p->data << " ";
                p = p->next;
        }
}

Queue::~Queue()
{
     /*   while (Count != 0)
        {
                Node* p = first;
                first = first->next;
                delete p;
                Count --;
        } */
}
#endif // QUEUE_H_INCLUDED
