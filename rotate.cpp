// rotate.cpp
// 
// Defined in header <algorithm>
// template< class FowardIt >
// ForwardIt rotate( ForwardIt first, ForwardIt n_first, ForwardIt last );
// 

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

namespace details {

  template<typename ForwardIt>
  void rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
  {
    ForwardIt next = n_first;
    while(first != n_first) {
      std::swap(*first++, *next++);
      if(next == last) {
	next = n_first;
      } else if (first == n_first) {
	n_first = next;
      }
    }
  }

}

using namespace std;

int main()
{
  vector<int> v(10);
  int g = 0;
  generate(v.begin(), v.end(), [g] () mutable -> int { return g++; });
  for(auto x: v)
    cout << x << ' ';
  cout << endl;
  details::rotate(v.begin(), v.begin() + 3, v.end());
  for(auto x: v)
    cout << x << ' ';
  cout << endl;
}
