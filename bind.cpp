// bind.cpp
// Demos the usage of std::bind defined in <functional>

#include <functional>
#include <iostream>
#include <random>

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5
              << std::endl;
}

int g(int n1)
{
    return n1;
}

struct Foo {
    void print_sum(int n1, int n2) {
        std::cout << n1 + n2 << std::endl;
    }
    int data = 10;
};

int main()
{
    using namespace std::placeholders;

    // argument reordering and pass-by-reference
    int n = 7;
    auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
    n = 10;
    f1(1, 2, 1001);  // 1 is bound by _2, 2 is bound by _1, 1001 is not used

    // nested bind subexpressions share the placeholders
    auto f2 = std::bind(f, _3, std::bind(g, _3), _3, 4, 5);
    f2(10, 11, 12);

    // common use case: binding a RNG with a distribution
    std::default_random_engine e;
    std::uniform_int_distribution<> d(0, 10);
    std::function<int()> rnd = std::bind(d, e);
    for (int i = 0; i < 10; ++i)
        std::cout << rnd() << ' ';
    std::cout << std::endl;

    // bind to a member function
    Foo foo;
    auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
    f3(5);

    // bind to member data
    auto f4 = std::bind(&Foo::data, _1);
    std::cout << f4(foo) << std::endl;
}
