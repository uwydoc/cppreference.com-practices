// mem_fn.cpp
// Demos the usage of std::mem_fn defined in <functional>

#include <functional>
#include <iostream>

struct Foo {
    void sayHi() {
        std::cout << "Hi there!" << std::endl;
    }
    void hiNumber(int i) {
        std::cout << "Hi " << i << std::endl;
    }
    int data = 9;
};

using namespace std;

int main()
{
    Foo f;
    auto hi = mem_fn(&Foo::sayHi);
    hi(f);
    auto hiN = mem_fn(&Foo::hiNumber);
    hiN(f, 10);
    auto access_data = mem_fn(&Foo::data);
    cout << "data: " << access_data(f) << endl;
}
