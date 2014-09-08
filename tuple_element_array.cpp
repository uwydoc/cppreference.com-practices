// tuple_element_array.cpp
//
// Defined in header <array>
// template< std::size_t I, class T, std::size_t N >
// struct tuple_element<I, array<T,N> >;
//

#include <array>
#include <iostream>
#include <typeinfo>

// Possible implementation
namespace details {

template <std::size_t N, typename T>
struct tuple_element;

template <std::size_t I, typename T, std::size_t N>
struct tuple_element<I, std::array<T,N> >
{
    using type = T;
};

};

using namespace std;

int main()
{
    array<int, 3> a = {1, 2, 3};
    typedef details::tuple_element<0, decltype(a)>::type IntType;
    IntType i = 3;
    cout << typeid(IntType).name() << endl;
}
