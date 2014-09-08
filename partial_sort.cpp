// partial_sort.cpp
//
// Defined in header <algorithm>
// template< class RandomIt >
// void partial_sort( RandomIt first, RandomIt middle, RandomIt last );
// template< class RandomIt, class Compare >
// void partial_sort( RandomIt first, RandomIt middle, RandomIt last, Compare comp );
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

//TODO BUG exists!
template<typename RandomIt>
void partial_sort(RandomIt first, RandomIt middle, RandomIt last)
{
    std::sort(first, middle);
    std::sort(middle, last);
    // custom merge
    RandomIt n_first = middle;
    while(first != middle && n_first != last) {
        if(*n_first < *first) {
            std::swap(*first, *n_first++);
        }
        ++first;
    }
}

}

using namespace std;

int main()
{
    const int size = 10;
    vector<int> v(size);
    generate(v.begin(), v.end(), [] () { return rand() % size; });
    for(int x : v)
        cout << setw(2) << x << ' ';
    cout << endl;
    details::partial_sort(v.begin(), v.begin() + 5, v.end());
    for(int x : v)
        cout << setw(2) << x << ' ';
    cout << endl;
}
