// find_end.cpp
//
// Defined in header <algorithm>
// template< class ForwardIt1, class ForwardIt2 >
// ForwardIt1 find_end( ForwardIt1 first, ForwardIt1 last,
//                      ForwardIt2 s_first, ForwardIt2 s_last );
// template< class ForwardIt1, class ForwardIt2, class BinaryPredicate >
// ForwardIt1 find_end( ForwardIt1 first, ForwardIt1 last,
//                      ForwardIt2 s_first, ForwardIt2 s_last,
//                      BinaryPredicate p );
// 

#include <algorithm>
#include <iostream>
#include <string>

namespace details {

template<typename ForwardIt1, typename ForwardIt2>
ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                    ForwardIt2 s_first, ForwardIt2 s_last)
{
    if (s_first == s_last)
        return last;

    ForwardIt1 result = last;
    while (1) {
        ForwardIt1 new_result = std::search(first, last, s_first, s_last);
        if (new_result == last) {
            return result;
        } else {
            result = new_result;
            first = result;
            ++first;
        }
    }
}

template<typename ForwardIt1, typename ForwardIt2, typename BinaryPredicate>
ForwardIt1 find_end(ForwardIt1 first, ForwardIt1 last,
                    ForwardIt2 s_first, ForwardIt2 s_last,
                    BinaryPredicate p)
{
    if (s_first == s_last)
        return last;

    ForwardIt1 result = last;
    while (1) {
        ForwardIt1 new_result = std::search(first, last, s_first, s_last, p);
        if (new_result == last) {
            return result;
        } else {
            result = new_result;
            first = result;
            ++first;
        }
    }
}

}

using namespace std;

int main()
{
    string s1 = "world world!";
    string s2 = "rld";
    auto it = search(s1.begin(), s1.end(), s2.begin(), s2.end());
    cout << "search: " << string(it, s1.end()) << endl;
    auto it1 = details::find_end(s1.begin(), s1.end(), s2.begin(), s2.end());
    cout << "find_end: " << string(it1, s1.end()) << endl;
}
