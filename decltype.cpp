// decltype.cpp
//
// decltype specifier
// Inspects the declared type of an entity or queries the return type of an
// expression
//

#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

int main()
{
    int i = 1;
    cout << boolalpha
         << typeid(decltype(i)).name() << endl
         << typeid(decltype((i))).name() << endl
         << is_same<decltype(i), decltype((i))>::value << endl
         << is_same<decay<decltype(i)>::type, decay<decltype((i))>::type>::value << endl;
}
