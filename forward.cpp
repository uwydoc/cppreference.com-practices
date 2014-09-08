// forward.cpp

#include <iostream>
#include <memory>
#include <utility>

struct Foo {
    Foo(int& n) { std::cout << "lvalue overload, n=" << n << std::endl; }
    Foo(int&& n) { std::cout << "rvalue overload, n=" << n << std::endl; }
    Foo() { std::cout << "Foo::Foo()" << std::endl; }
};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

using namespace std;

int main()
{
    int i = 1;
    unique_ptr<Foo> p1 = make_unique<Foo>(i);
    unique_ptr<Foo> p2 = make_unique<Foo>(2);
    unique_ptr<Foo> p3 = make_unique<Foo>();
}
