// typeid.cpp
// Demos the usage of the typeid expression

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    cout << typeid(int).name() << endl
         << typeid(int*).name() << endl
         << typeid(const int).name() << endl
         << typeid(volatile int).name() << endl
         //<< typeid(static int).name() << endl
         //<< typeid(extern int).name() << endl
         << typeid(const volatile int*).name() << endl;
}
