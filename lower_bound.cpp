// lower_bound.cpp
//
// Defined in header <algorithm>
// template< class ForwardIt, class T >
// ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value );
// template< class ForwardIt, class T, class Compare >
// ForwardIt lower_bound( ForwardIt first, ForwardIt last, const T& value,
//                        Compare comp );
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

template<typename ForwardIt, typename T>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);

    while(count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if( *it < value) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }

    return first;
}

}

using namespace std;

int main()
{
    const int max = 20;
    vector<int> v(max/2);
    srand(time(0));
    generate(v.begin(), v.end(), [] () { return rand()%max; });
    sort(v.begin(), v.end());
    for(int x : v)
        cout << x << ' ';
    cout << endl;
    int var = rand() % max;
    auto it = details::lower_bound(v.begin(), v.end(), var);
    cout << "# lower_bound(" << var << ")" << endl;
    copy(v.begin(), it, ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(it, v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
