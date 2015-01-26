#include <iostream>
 
#include "queue.h"
using namespace std;

int main(void)
{
	int x;
	LinkedQueue<int> LQ;
	LQ = LQ.Add(3).Add(4).Add(5);
	cout << LQ.First() << endl;
	cout << LQ.Last() << endl;
	LQ.Delete(x);
	cout << LQ.First() << endl;
	cout << "x = " << x << endl;
	return 0;
}