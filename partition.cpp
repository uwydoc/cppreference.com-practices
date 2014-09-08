// partition.cpp
//
// Defined in header <algorithm>
// template< class BidirIt, class UnaryPredicate >
// BidirIt partition( BidirIt first, BidirIt last, UnaryPredicate p );
// template< class ForwardIt, class UnaryPredicate >
// ForwardIt partition( ForwardIt first, ForwardIt last, UnaryPredicate p );
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

namespace details {

//template<typename BidirIt, typename UnaryPredicate>
//BidirIt partition(BidirIt first, BidirIt last, UnaryPredicate p)
//{
//    while(true) {
//        while(first != last && p(*first)) ++first;
//        if(first == last--) break;
//        while(last != first && !p(*last)) --last;
//        if(last == first) break;
//        std::swap(*first++, *last);
//    }
//    return first;
//}

template<typename ForwardIt, typename UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    while(first != last && p(*first)) ++first;
    if(first == last) return last;

    ForwardIt result  = first;
    while(first != last) {
        if(p(*first)) {
            std::swap(*first++, *result++);
        } else {
            ++first;
        }
    }
    return result;
}

}

using namespace std;

int main()
{
    vector<int> v(10);
    int i = 0;
    generate(v.begin(), v.end(), [i] () mutable { return i++; });
    for(auto x: v)
        cout << x << ' ';
    cout << endl;
    auto it = details::partition(v.begin(), v.end(), [] (int x) { return (x % 2); });
    for(auto x: v)
        cout << x << ' ';
    cout << endl;
    copy(v.begin(), it, ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(it, v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
