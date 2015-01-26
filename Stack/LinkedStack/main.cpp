#include <iostream>
#include "stack.h"
using namespace std;

int main(void)
{
	int x;
	LinkedStack<int> LS;
	LS = LS.Add(3).Add(4).Add(5);
	cout << LS.Top() << endl;
	LS = LS.Delete(x);
	cout << LS.Top() << endl;
	cout << "x = " << x << endl;
	return 0;
}