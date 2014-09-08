// uninitialized_fill.cpp
// Defined in header <memory>
//
// template<typename ForwardIt, typename T>
// void uninitialized_fill(ForwardIt first, ForwardIt last, const T& value);

#include <iostream>
#include <iterator>
#include <memory>
#include <string>

namespace details {

// Possible implementation of std::uninitialized_fill
template<typename ForwardIt, typename T>
void uninitialized_fill(ForwardIt first, ForwardIt last, const T& value)
{
    typedef typename std::iterator_traits<ForwardIt>::value_type value_type;
    for (; first != last; ++first) {
        ::new (static_cast<void*>(std::addressof(*first))) value_type(value);
    }
}

}

using namespace std;

int main()
{
    const constexpr size_t size = 4;
    if (true) {
        shared_ptr<string> p(get_temporary_buffer<string>(size).first,
                             return_temporary_buffer<string>);
        details::uninitialized_fill(p.get(), p.get()+size, "cppref");
        for (string* i = p.get(); i != p.get()+size; ++i) {
            cout << *i << endl;
            i->~basic_string<char>();
        }
    }
}
