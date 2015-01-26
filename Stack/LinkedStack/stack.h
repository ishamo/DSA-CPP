template<class T>
class LinkedStack;


template<class T>
class Node{
	friend LinkedStack<T>;
private:
	T data;
	Node<T> *link;
};

template<class T>
class LinkedStack{
public:
	LinkedStack(){top = NULL;}
	~LinkedStack();
	bool IsEmpty() const {return top == NULL;}
	T Top() const;
	LinkedStack<T>& Add(const T& x);
	LinkedStack<T>& Delete(T& x);
private:
	Node<T> *top;
};

template<class T>
LinkedStack<T>::~LinkedStack()
{
	Node<T> *next;
	while (top){
		next = top->link;
		delete top;
		top = next;
	}
}

template<class T>
T LinkedStack<T>::Top() const
{
	if (IsEmpty()) exit(0);
	return top->data;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Add(const T& x)
{
	Node<T> *p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
}

template<class T>
LinkedStack<T>& LinkedStack<T>::Delete(T& x)
{
	if (IsEmpty()) exit(0);
	x = top->data;
	Node<T> *p = top;
	top = top->link;
	delete p;
	return *this;
}





