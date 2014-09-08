// search_n.cpp
//
// Defined in header <algorithm>
// template< class InputIt, class Size, class T >
// search_n( InputIt first, InputIt last, Size count, const T& value );
//

#include <algorithm>
#include <iostream>
#include <string>

namespace details {

template<typename InputIt, typename Size, typename T>
InputIt search_n(InputIt first, InputIt last, Size count, const T& value)
{
    if (count <= 0)
        return last;

    InputIt result = first;
    Size n = 0;
    for (; first != last; ++first) {
        if (*first == value) {
            if (n == 0)
                result = first;
            if (++n == count)
                return result;
        } else {
            n = 0;
            result = first;
        }
    }
    return last;
}

}

using namespace std;

int main()
{
    string str = "hlelllo";
    auto it = details::search_n(str.begin(), str.end(), 2, 'l');
    cout << string(it, str.end()) << endl;
}
