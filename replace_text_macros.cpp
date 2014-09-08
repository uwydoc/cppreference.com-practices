// replace_text_macros.cpp
//
// Demos the usage of text macros

#include <iostream>

// Make function factory and use it
#define FUNCTION(name, a) int func_##name() { return a; }

FUNCTION(abcd, 12);
FUNCTION(fff, 2);
FUNCTION(kkk, 23);

#undef FUNCTION
#define FUNCTION 34
#define OUTPUT(a) std::cout << #a << std::endl

using namespace std;

int main()
{
    cout << "abcd: " << func_abcd() << endl
         << "fff: " << func_fff() << endl
         << "kkk: " << func_kkk() << endl
         << FUNCTION << endl;
    OUTPUT(million);
    
    cout << "file: " << __FILE__ << endl
         << "line: " << __LINE__ << endl
         << "func: " << __func__ << endl
         << "date: " << __DATE__ << endl
         << "time: " << __TIME__ << endl;
}
