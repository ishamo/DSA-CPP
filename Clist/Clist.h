#ifndef CLIST_H
#define CLIST_H

#define NULL 0

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
        Clist();
        virtual ~Clist();

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

#endif // CLIST_H
