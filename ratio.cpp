// ratio.cpp
//
// Defined in header <ratio>
// template< std::intmax_t Num, std::intmax_t Denom = 1 >
// class ratio;
//

#include <iostream>
#include <ratio>

int main()
{
    typedef std::ratio<12, 15> FooRatioType;

    std::cout << "Num " << FooRatioType::num << ", "
              << "Denom " << FooRatioType::den << '\n';
}
