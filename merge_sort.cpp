// merge_sort.cpp
//
// template< class BidirIt >
// void merge_sort( BidirIt first, Bidir last );
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

template<typename BidirIt>
void merge_sort(BidirIt first, BidirIt last)
{
    if(last - first > 1) {
        BidirIt middle = first + (last - first)/2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
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
    cout << "# merge sort" << endl;
    details::merge_sort(v.begin(), v.end());
    for(int x : v)
        cout << x << ' ';
    cout << endl;
}
