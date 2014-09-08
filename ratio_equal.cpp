// ratio_equal.cpp
//
// Defined in header <ratio>
// template< class R1, class R2 >
// struct ratio_equal : std::integral_constant;
//

#include <iostream>
#include <ratio>
#include <type_traits>

namespace details {

template<typename R1, typename R2>
struct ratio_equal
    : public std::integral_constant <
                  bool,
                  R1::num == R2::num && R1::den == R2::den
             > {};

}

int main()
{
    std::cout << std::boolalpha
              << details::ratio_equal<std::ratio<2,3>, std::ratio<4,6>>::value
              << std::endl
              << details::ratio_equal<std::ratio<2,3>, std::ratio<3,7>>::value
              << std::endl;
}
