// iterator_traits.cpp
// Defined in header <iterator>
//
// template<typename Iterator> struct iterator_traits;
// template<typename T> struct iterator_traits<T*>;
// template<typename T> struct iterator_traits<const T*>;

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

namespace details {

template<typename Iterator>
void reverse(Iterator first, Iterator last)
{
    typename std::iterator_traits<Iterator>::difference_type n = std::distance(
            first, last);
    --n;
    while (n > 0) {
        typename std::iterator_traits<Iterator>::value_type tmp = *first;
        *(first++) = *(--last);
        *last = tmp;
        n -= 2;
    }
}

}

using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5};
    details::reverse(v.begin(), v.end());
    cout << "After details::reverse, v is {";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << "}" << endl;

    list<int> l = {5,4,3,2,1};
    details::reverse(l.begin(), l.end());
    cout << "After details::reverse, l is {";
    for (auto n : l)
        cout << n << ", ";
    cout << "}" << endl;
}
