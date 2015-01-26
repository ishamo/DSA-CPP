#include "Stack.h"

int main()
{
        Stack S;
        S.Push(1);
        S.Push(2);
        S.Push(3);
        int Out = S.Pop();
        cout << Out << endl;
        S.Print();

        return 0;
}
