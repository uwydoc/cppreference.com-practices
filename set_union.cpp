// set_union.cpp
//
// Defined in header <algorithm>
// template< class InputIt1, class InputIt2, class OutputIt >
// OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2,
//                     InputIt2 last2, OutputIt d_first );
// template< class InputIt1, class InputIt2, class OutputIt, class Compare >
// OutputIt set_union( InputIt1 first1, InputIt1 last1, InputIt2 first2,
//                     InputIt2 last2, OutputIt d_first, Compare comp );
// 

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

template<typename InputIt1, typename InputIt2, typename OutputIt>
OutputIt set_union(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                   InputIt2 last2, OutputIt d_first)
{
    while(first1 != last1 && first2 != last2) {
        if(*first1 < *first2) {
            *d_first = *first1++;
        } else {
            *d_first = *first2;
            if(!(*first2 < *first1)) {
                ++first1;
            }
            ++first2;
        }
        ++d_first;
    }
    if(first1 != last1) {
        return std::copy(first1, last1, d_first);
    } else if(first2 != last2) {
        return std::copy(first2, last2, d_first);
    }
}

}

using namespace std;

int main()
{
    const int max = 20;
    vector<int> v1(max/4), v2(max/4);
    srand(time(0));
    auto mkrand = [] () { return rand()%max; };
    generate(v1.begin(), v1.end(), mkrand); sort(v1.begin(), v1.end());
    generate(v2.begin(), v2.end(), mkrand); sort(v2.begin(), v2.end());
    cout << "# raw" << endl;
    for(int x : v1)
        cout << x << ' ';
    cout << endl;
    for(int x : v2)
        cout << x << ' ';
    cout << endl;
    cout << "# set_union" << endl;
    vector<int> v(v1.size() + v2.size());
    auto last = details::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(),
                                   v.begin());
    copy(v.begin(), last, ostream_iterator<int>(cout, " "));
    cout << endl;
}
