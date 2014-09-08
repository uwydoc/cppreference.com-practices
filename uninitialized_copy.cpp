// uninitialized_copy.cpp
// Defined in header <memory>
//
// template<typename InputIt, typename ForwardIt>
// ForwardIt uninitialized_copy(InputIt first, InputIt last, ForwardIt d_first);

#include <algorithm>
#include <iostream>
#include <memory>

namespace details {

// Possible implementation of std::uninitialized_copy
template<typename InputIt, typename ForwardIt>
ForwardIt uninitialized_copy(InputIt first, InputIt last, ForwardIt d_first)
{
    typedef typename std::iterator_traits<ForwardIt>::value_type value_type;
    for (; first != last; ++first, ++d_first) {
        ::new (static_cast<void*>(std::addressof(*d_first))) value_type(*first);
    }
    return d_first;
}

}

using namespace std;

int main()
{
    vector<string> v = {"This", "is", "an", "example"};
    string* p = NULL;
    size_t sz = 0;
    tie(p, sz) = get_temporary_buffer<string>(v.size());
    sz = min(sz, v.size());
    details::uninitialized_copy(v.begin(), v.begin()+sz, p);
    for (string* i = p; i != p+sz; ++i) {
        cout << *i << ' ';
        //delete i;  // Error! cannot be released using delete
        i->~basic_string<char>();  // must invoke destructor manually, otherwise
                                   // memory leak in heap is to occur
    }
    cout << endl;
    return_temporary_buffer(p);
}
