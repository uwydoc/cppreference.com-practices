// tuple_size.cpp
// Provides access to the number of elements in an std::array as a compile-time
// constant expression

#include <array>
#include <iostream>

template<typename T>
void foo(const T& t)
{
    int a[std::tuple_size<T>::value];
    std::cout << std::tuple_size<T>::value << std::endl;
}

using namespace std;

int main()
{
    array<float, 3> a = {1, 2, 3};
    foo(a);
}
