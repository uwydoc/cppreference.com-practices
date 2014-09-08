// function_arithmetic.cpp
// Demos the usage of some functions objects that represent common arithmetic
// and logical operations, such as plus, divides, equal_to, logical_and,
// defined in <functional>

#include <functional>
#include <iostream>

using namespace std;

int main()
{
    cout << boolalpha
         << "plus(3, 2) = " << plus<int>()(3, 2) << endl
         << "divides(10, 4) = " << divides<int>()(10, 4) << endl
         << "equal_to(5, 5) = " << equal_to<int>()(5, 5) << endl
         << "logial_and(true, false) = " << logical_and<bool>()(true, false) << endl
         << "bit_and(1, 3) = " << bit_and<int>()(1, 3) << endl;
}
