// stable_partition.cpp
//
// Defined in header <algorithm>
// template< class BidirIt, class UnaryPredicate >
// BidirIt stable_partition( BidirIt first, BidirIt last, UnaryPredicate p );
//

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

// stable_partition mod, with support for ForwardIt
template<typename ForwardIt, typename UnaryPredicate>
ForwardIt stable_partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    while(first != last && p(*first)) ++first;
    if(first == last) return last;

    ForwardIt result = first++;
    while(true) {
        while(first != last && !p(*first)) ++first;
        if(first == last) break;
        ForwardIt it = first++;
        while(first != last && p(*first)) ++first;
        ForwardIt new_result = result;
        std::advance(new_result, std::distance(it, first));
        std::rotate(result, it, first);
        result = new_result;
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
    forward_list<int> l(v.begin(), v.end());
    for(auto x: l)
        cout << x << ' ';
    cout << endl;
    function<bool(int)> is_odd = [] (int x) { return (x % 2); };
    // stable_partition
    cout << "# stable partition #" << endl;
    auto it = details::stable_partition(l.begin(), l.end(), is_odd);
    for(auto x: l)
        cout << x << ' ';
    cout << endl;
    copy(l.begin(), it, ostream_iterator<int>(cout, " ")); cout << endl;
    copy(it, l.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    // partition
    cout << "# partition #" << endl;
    forward_list<int> l1(v.begin(), v.end());
    auto it1 = std::partition(l1.begin(), l1.end(), is_odd);
    for(auto x: l1)
        cout << x << ' ';
    cout << endl;
    copy(l1.begin(), it1, ostream_iterator<int>(cout, " ")); cout << endl;
    copy(it1, l1.end(), ostream_iterator<int>(cout, " ")); cout << endl;
}
