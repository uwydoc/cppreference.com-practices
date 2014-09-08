// ref_cref.cpp
// Demos the usage of std::ref and std::cref defined in <functional>

#include <functional>
#include <iostream>

void f(int& n1, int& n2, const int& n3)
{
    std::cout << "In function: " << n1 << ' ' << n2 << ' ' << n3 << std::endl;
    ++n1;
    ++n2;
}

using namespace std;

int main()
{
    int n1 = 1, n2 = 2, n3 = 3;
    function<void()> bound_f = bind(f, n1, ref(n2), cref(n3));
    n1 = 10, n2 = 11, n3 = 12;
    cout << "Before function: " << n1 << ' ' << n2 << ' ' << n3 << endl;
    bound_f();
    cout << "After function: " << n1 << ' ' << n2 << ' ' << n3 << endl;
}
