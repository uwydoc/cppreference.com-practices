// unique.cpp
//
// Defined in header <algorithm>
// template< class ForwardIt >
// ForwardIt unique( ForwardIt first, ForwardIt last );
// template< class ForwardIt, class BinaryPredicate >
// ForwardIt unique( ForwardIt first, ForwardIt last, BinaryPredicate pred );
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace details
{

// first form, use operator== to compare two elements
template<typename ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt it = first;
    while (++first != last) {
        if (!(*first == *it)) {
            *(++it) = *first;
        }
    }
    return ++it;
}

// second form, use specified `pred' to compare
template<typename ForwardIt, typename BinaryPred>
ForwardIt unique(ForwardIt first, ForwardIt last, BinaryPred pred)
{
    if (first == last)
        return last;

    ForwardIt it = first;
    while (++first != last) {
        if (!pred(*first, *it)) {
            *(++it) = *first;
        }
    }
    return ++it;
}

}

using namespace std;

int main()
{
    vector<int> v1 = {1,2,2,3,1,1,1,2,2,1};
    vector<int> v2 = v1;
    for (auto &i : v1)
        cout << i << ' ';
    cout << endl;

    auto last = details::unique(v1.begin(), v1.end());
    for (auto it = v1.begin(); it != last; ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    auto ge2 = [] (int x) -> bool { return (x >= 2); };
    transform(v2.begin(), v2.end(), ostream_iterator<bool>(cout, " "), ge2);
    cout << endl;
    last = details::unique(v2.begin(), v2.end(),
                           [ge2] (int x, int y) { return (ge2(x) && ge2(y)); });
    for (auto it = v2.begin(); it != last; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}
