#include <QCoreApplication>
#include <iostream>

#include "PtrVector.h"

struct A
{
    A(int in): a(in)
    {
        std::cout << "constructor A\n";
    }
    A(const A& in): a(in.a)
    {
        std::cout << "copy constructor A\n";
    }
    ~A()
    {
        std::cout << "destructor A\n";
    }
    int a;
};


int main(int argc, char *argv[])
{
    {
    PtrVector<A> ptrv;
    for(int i = 0; i < 3; ++i)
    {
        A* a = new A(i);
        ptrv.Add(a);
    }
    for(int i = 0; i < ptrv.Size(); ++i)
    {
        std::cout << ptrv.Get(i).a << "\n";
    }

    PtrVector<A> ptrv2(ptrv);
    PtrVector<A> ptrv3 = ptrv;

    std::cout << ptrv.Get(1).a << "\n";
    std::cout << ptrv2.Get(1).a << "\n";
    std::cout << ptrv3.Get(1).a << "\n";

    ptrv2.Get(1).a = 2;
    ptrv3.Get(1).a = 3;

    std::cout << ptrv.Get(1).a << "\n";
    std::cout << ptrv2.Get(1).a << "\n";
    std::cout << ptrv3.Get(1).a << "\n";

    ptrv.Clear();
    }

    return 1;
}
