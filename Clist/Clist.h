#ifndef CLIST_H
#define CLIST_H


#include <cassert>
#include <iostream>
using namespace std;



template <typename T>
struct Node{
    T data;
    Node* next;
    Node():data(T()), next(NULL){}
};

template <typename T>
class Clist
{
public:
        Clist():Head(NULL), Count(0)
        {
        }
        virtual ~Clist()
        {
                if (Head != NULL)
                {
                        Node<T> *p = Head;
                        Head = Head->next;
                        delete p;
                }
        }

public:
        void InsertAt(int i, T data);
        void DeleteAt(int i);
        bool Length()
        {
                return Count;
        }
        void Print();
protected:
        Node<T>* Head;
        int Count;

};

template <typename T>
void Clist<T>::InsertAt(int i, T data)
{
        assert(i >= 0 && i <= Count+1);
        if (i == 0)   //表示链表刚刚创建还没有结点 , 那么我给它一个结点 .
        {
                assert(Count == 0);
                Node<T> *p = new Node<T>;
                p->data = data;
                p->next = NULL;
                Head = p;
                Count += 1;
        }
        else if (i == 1)   //我插的这个结点将会是List的第一个结点(头结点) .
        {
                Node<T> *p = new Node<T>;
                p->data = data;
                p->next = Head;
                Head = p;
                Count += 1;
        }
        else
        {
                Node<T> *p = new Node<T>;
                p->data = data;
                Node<T> *tmp = new Node<T>;
                tmp = Head;
                for (int j = 2; j < i; j ++) tmp = tmp->next;
                p->next  = tmp->next;
                tmp->next = p;
                Count += 1;
        }
}


template <typename T>
void Clist<T>::DeleteAt(int i)
{
        assert( i <= Count && i > 0);
        if (i == 1)                             //表示要删除链表的首元素
        {
                Node<T> *p;
                p = Head;
                Head = Head->next;
                delete p;
                Count -= 1;
        }
        else                                    //删除的是除首元素之外的其它元素
        {
                Node<T> *p;
                Node<T> *q = Head;
                for (int j = 2; j < i; j ++) q = q->next;
                p = q->next;
                q->next = q->next->next;
                delete p;
                Count -= 1;
        }
}

template <typename T>
void Clist<T>::Print()
{
        Node<T> *p = Head;
        while (p != NULL)
        {
                cout << p->data << " ";
                p = p->next;
        }
}



#endif // CLIST_H
