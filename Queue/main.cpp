#include "Queue.h"
int main()
{
        Queue Q;
        Q.Push(1);
        Q.Push(2);
        Q.Push(3);
        Q.Print();
        cout << "\n==========\n";
        int Out1 = Q.Pop();
        int Out2 = Q.Pop();
        int Out3 = Q.Pop();

        cout << Out3<< endl;
        Q.Print();

        return 0;
}
