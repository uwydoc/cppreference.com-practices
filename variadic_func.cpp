// variadic_func.cpp
// Show how to define and implement variadic function (with variable number
// of arguments)

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdarg>

namespace details {

// dummy clone of std::printf, with basic supported type
void printf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    std::ostringstream oss;
    for (; *fmt != '\0'; ++fmt) {
        if (*fmt != '%') {
            oss << *fmt;
        } else {
            switch (*(++fmt)) {
            case 'd':
                oss << va_arg(args, int);
                break;
            case 'c':
                oss << static_cast<char>(va_arg(args, int));
                break;
            case 'f':
                oss << va_arg(args, double);
                break;
            case '%':
                oss << '%';
                break;
            default:
                throw std::runtime_error("unsupported format symbol encountered");
            }
        }
    }
    std::cout << oss.str();
}

}

using namespace std;

int main()
{
    printf("hello. i am %d years old. i am %.2fm tall. and i am of gender %c\n",
           22, 1.74, 'm');
    details::printf("hello. i am %d years old. i am %fm tall. and i am of "
                    "gender %c\n", 22, 1.74, 'm');
}
