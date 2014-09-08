// sizeof... .cpp
// Demos the usage of sizeof... keyword

#include <iostream>

template<typename... Args>
void foo()
{
    if (sizeof...(Args) == 0) {
        std::cout << "empty template parameters" << std::endl;
    } else {
        std::cout << "template parameters with size " << sizeof...(Args)
                  << std::endl;
    }
}

using namespace std;

int main()
{
    foo();
    foo<int>();
    foo<bool,char>();
}
