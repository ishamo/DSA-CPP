#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* lchild;
	Node* rchild;
	Node():data(int()), lchild(NULL), rchild(NULL){}
};


void createTree(Node* &T)
{
	int n;
	cin >> n;
	if (n == 0) T = NULL;
	else{
		T= new Node;
		T->data = n;
		createTree(T->lchild);
		createTree(T->rchild);
	}
}

void preOrder(Node* T)
{
	if (T){
		cout << T->data;	
		preOrder(T->lchild);
		preOrder(T->rchild);	
	}
}

void inOrder(Node* T){
	if(T){
		inOrder(T->lchild);
		cout<<T->data;
		inOrder(T->rchild);
	}
}
void postOrder(Node* T){
	if(T){
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout<<T->data;
	}
}

int height(Node* T)
{
	int i, j;
 	if(T==NULL) 
		return 0;	
	if (T->lchild) 
		i = height(T->lchild);
	else 
		i = 0;
				
	if (T->rchild) 
		j = height(T->rchild);
	else 
		j = 0;	
	return i>j ? i+1:j+1;
}



int main()
{
	Node* T;
	createTree(T);
	cout<<"先序递归遍历："<<endl;
	preOrder(T);
	cout<<endl;
	cout<<"中序递归遍历："<<endl;
	inOrder(T);
	cout<<endl;
	cout<<"后序递归遍历:"<<endl;
	postOrder(T);
	cout<<endl;
	
	cout << "树高:" << height(T);
	
	return 0;
}



