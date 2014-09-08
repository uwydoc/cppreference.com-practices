// lambda_func.cpp
// Demos the usage of lambda function

#include <iostream>

using namespace std;

int main()
{
    auto f = []() { return true; };
    cout << boolalpha
         << f() << endl;
}
