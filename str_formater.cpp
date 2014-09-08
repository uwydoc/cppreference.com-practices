// str_formater.cpp
// Simple formater that produces a string object corresponding to the
// format specified.

#include <iostream>
#include <sstream>
#include <utility>

void StringFormater(std::ostream& out, const char* format)
{
    out << format;
}

template<typename T, typename... Args>
void StringFormater(std::ostream& out, const char* format, const T& t,
                    Args... args)
{
    for (; *format != '\0'; ++format) {
        if (*format == '?') {
            if (*(format+1) != '?') {
                out << t;
                StringFormater(out, format+1, std::forward<Args>(args)...);
                return;
            } else {
                ++format;
            }
        }
        out << *format;
    }
}

using namespace std;

int main()
{
    ostringstream oss;
    StringFormater(oss, "? parameter pack. how do you do?? i am ?.", "hello",
                   "neo");
    cout << oss.str() << endl;
}
