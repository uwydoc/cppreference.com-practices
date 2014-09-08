// next_permutation.cpp
//
// Defined in header <algorithm>
// template< class BidirIt >
// bool next_permutation( BidirIt first, BidirIt last );
// template< class BidirIt, class Compare >
// bool next_permutation( BidirIt first, BidirIt last, Compare comp );
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

template<typename BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    if(first == last) return false;

    BidirIt it = last; --it;
    while(it != first) {
        BidirIt it1 = it;
        if(*--it < *it1) {
            BidirIt it2 = last;
            while(!(*it < *--it2)) ;
            std::swap(*it, *it2);
            std::reverse(it1, last);
            return true;
        }
    }
    std::reverse(first, last);
    return false;
}

}

using namespace std;

int main()
{
    const int max = 20;
    vector<int> v(max/2);
    srand(time(0));
    generate(v.begin(), v.end(), [] () { return rand()%max; });
    for(int x : v)
        cout << x << ' ';
    cout << endl;
    cout << "# next_permutation" << endl;
    bool ret = details::next_permutation(v.begin(), v.end());
    for(int x : v)
        cout << x << ' ';
    cout << endl;
    cout << "# result " << boolalpha << ret << endl;
}
