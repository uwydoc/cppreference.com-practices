// tuple_element_pair.cpp
//
// Defined in header <utility>
// template<typename T1, typename T2>
// struct tuple_element<0, std::pair<T1,T2> >;
// template<typename T1, typename T2>
// struct tuple_element<1, std::pair<T1,T2> >;
//

#include <iostream>
#include <string>
#include <tuple>
#include <utility>

namespace details {

template<std::size_t, typename T>
struct tuple_element;

template<typename T1, typename T2>
struct tuple_element<0, std::pair<T1,T2> >
{
    using type = T1;
};

template<typename T1, typename T2>
struct tuple_element<1, std::pair<T1,T2> >
{
    using type = T2;
};

}

template<std::size_t N, typename T1, typename T2>
static auto constexpr get(std::pair<T1,T2> const& p)
    -> typename details::tuple_element<N, decltype(p)>::type
{
    return N == 0 ? p.first : p.second;
}

using namespace std;

int main()
{
    auto p = make_pair(1, string("one"));
    cout << get<0>(p) << " = " << get<1>(p) << endl;
}
