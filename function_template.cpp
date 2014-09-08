// function_template.cpp
// Deoms the applications of function template

#include <iostream>

template<typename To, typename From>
To convert(From f)
{
    return static_cast<To>(f);
}

template<>
int convert(float f)
{
    std::cout << "int convert<float> called" << std::endl;
    return static_cast<int>(f);
}

template<>
char convert(int f)
{
    std::cout << "char convert<int> called" << std::endl;
    return static_cast<char>(f);
}

using namespace std;

int main()
{
    int i = convert<int>(1.1f);
    char c = convert<char>(97);
    float f = convert<float>(3.14);
    cout << i << ' ' << c << ' ' << f << endl;
}
