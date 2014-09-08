// decay_eq.cpp
// Judge whether two types equals each other, via std::decay defined in
// <type_traits>

#include <iostream>
#include <type_traits>

template<typename T, typename U>
struct decay_eq :
    std::integral_constant<
        bool,
        std::is_same<typename std::decay<T>::type,
                     typename std::decay<U>::type>::value
    >
{};

using namespace std;

int main()
{
    cout << boolalpha
         << decay_eq<int*, int[]>::value << endl;
}
