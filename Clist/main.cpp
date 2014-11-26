#include "Clist.h"
#include <iostream>
using namespace std;

int main()
{
        Clist<int> L;
        L.InsertAt(0, 2);
        L.InsertAt(1, 1);
        L.InsertAt(3, 4);
        L.InsertAt(3, 3);
        L.Print();
        return 0;
}
