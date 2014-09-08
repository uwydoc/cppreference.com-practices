// no_except.cpp

#include <iostream>

struct Foo {
    Foo() { throw 1; }  // constructor that throws
};

// Whether foo is declared noexcept depends on if the expression T() would
// throw any exceptions
template<typename T>
void foo() noexcept(noexcept(T())) {
    std::cout << "foo()" << std::endl;
}

void bar() noexcept(true) { std::cout << "bar()" << std::endl; }
void caz() noexcept {  // declared as noexcept, but actually throws
    std::cout << "caz()" << std::endl;
    throw 1;
}

using namespace std;

int main()
{
    foo<int>();
    foo<Foo>();
    bar();
    caz();
}
