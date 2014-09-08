// integral_constant.cpp
// Possible implementation of std::integral_constant defined in <type_traits>

#include<iostream>
#include<type_traits>

namespace details {

template<typename T, T v>
struct integral_constant {
    static constexpr T value = v;
    typedef T value_type;
    typedef integral_constant type;
    constexpr operator value_type() const { return value; }
};

}

int main()
{
    typedef std::integral_constant<int, 2> IntTwoType;
    typedef std::integral_constant<int, 4> IntFourType;
    static_assert(std::is_same<IntTwoType, IntFourType>::value,
                  "IntTwoType and IntFourType are of different types");
    static_assert(IntTwoType::value*2 == IntFourType::value,
                  "2*2 != 4");
    typedef details::integral_constant<int, 2> IntTwoTypeMod;
    static_assert(std::is_same<IntTwoType, IntTwoTypeMod>::value,
                  "IntTwoType and IntTwoTypeMod are of different types");
}
