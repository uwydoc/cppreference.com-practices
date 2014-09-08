// addressof.cpp
//

#include <ios>
#include <iostream>
#include <memory>

class NonAddressable {
private:
    double operator&() const { return 1.0; }
};

namespace details {

template<typename T>
T* addressof(T& t) noexcept {
    return reinterpret_cast<T*>(
            &const_cast<char&>(reinterpret_cast<const volatile char&>(t)));
}

}

using namespace std;

int main()
{
    NonAddressable na;
    //NonAddressable* nap = &na;
    NonAddressable* nap = details::addressof<NonAddressable>(na);
    cout << hex << nap << ' ' << addressof(na) << endl;
}
