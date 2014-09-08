// parameter_pack.cpp
// Demos the usage of parameter pack in function template

#include <iostream>

// Base function
void FormatPrint(const char* format)
{
    std::cout << format;
}

template<typename T, typename... Args>
void FormatPrint(const char* format, T t, Args... args)
{
    for (; *format != '\0'; ++format) {
        if (*format == '?') {
            if (*(format+1) != '?') {
                std::cout << t;
                FormatPrint(format+1, args...);
                return;
            } else {
                ++format;
            }
        }
        std::cout << *format;
    }
}

using namespace std;

int main()
{
    FormatPrint("Neo: ? parameter pack. i am ?. how do you do??\n"
                "Parameter Pack: i am fine. thanks ?.\n",
                "hello", "neo", "neo");
}
