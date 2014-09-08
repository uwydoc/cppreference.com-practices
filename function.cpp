// function.cpp
// test std::function that is capable of wrapping around any callable objects,
// such as, normal function, member function, lambda expressino and bind 
// expression, etc.

#include <functional>
#include <iostream>

#include <boost/lexical_cast.hpp>

void print_num(int i)
{
    std::cout << i << std::endl;
}

struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { print_num(num_ + i); }
    static void s_print_add(const Foo* f, int i) {
        print_num(f->num_ + i);
    }
    int num_;
};

using namespace std;
using namespace boost;

int main()
{
    // store a free function
    function<void(int)> f_display = print_num;
    f_display(-9);
    // store a lambda
    function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
    // store the result of a call to std::bind
    function<void()> f_display_77 = bind(print_num, 77);
    f_display_77();
    // store a call to a member function
    function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    Foo foo(123);
    f_add_display(foo, 1);
    //// store a static member function with object bound
    //function<void(int)> f_add_display_123 = bind(Foo::s_print_add, &foo);
    //f_add_display_123(10);
    // demo bad_function_call
    function<void()> f_null;
    try {
        f_null();
    } catch (const bad_function_call& e) {
        cerr << "bad function call: " << e.what() << endl;
        cout << boolalpha;
        cout << "f_null == nullptr is " << (f_null == nullptr) << endl;
    }
}
