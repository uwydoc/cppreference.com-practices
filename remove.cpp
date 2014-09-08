// remove.cpp
// 
// Defined in header <algorithm>
// template< class ForwardIt, class T >
// ForwardIt remove( ForwardIt first, ForwardIt last, const T& value );
// template< class ForwardIt, class UnaryPredicate >
// ForwardIt remove_if( ForwardIt first, ForwardIt last, UnaryPredicate p);
// 

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace details {

  template<typename ForwardIt, typename T>
  ForwardIt remove(ForwardIt first, ForwardIt last, const T& value)
  {
    ForwardIt result = first;
    for(; first != last; ++first) {
      if(!(*first == value)) {
	*result++ = *first;
      }
    }
    return result;
  }

  template<typename ForwardIt, typename UnaryPredicate>
  ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
  {
    ForwardIt result = first;
    for(; first != last; ++first) {
      if(!p(*first)) {
	*result++ = *first;
      }
    }
    return result;
  }

}

using namespace std;

int main()
{
  vector<int> v(10);
  int g = 0;
  generate(v.begin(), v.end(), [g] () mutable -> int { return g++; });
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  auto last = details::remove(v.begin(), v.end(), 5);
  copy(v.begin(), last, ostream_iterator<int>(cout, " "));
  cout << endl;
  auto last1 = details::remove_if(v.begin(), last, [] (int x) -> bool { return (x % 2); });
  copy(v.begin(), last1, ostream_iterator<int>(cout, " "));
  cout << endl;
}
