// reverse.cpp
// 
// Defined in header <algorithm>
// template< class BidirIt >
// void reverse( BidirIt first, BidirIt last );
// 

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

namespace details {

  template<typename BidirIt>
  void reverse(BidirIt first, BidirIt last)
  {
    while(first != last && first != --last) {
      std::iter_swap(first++, last);
    }
  }

}

using namespace std;

int main()
{
  cout << '#' << endl;
  vector<int> v(10);
  generate(v.begin(), v.end(), [] () { return (rand() % 20); });
  for(auto x: v)
    cout << setw(2) << x << ' ';
  cout << endl;
  details::reverse(v.begin(), v.end());
  for(auto x: v)
    cout << setw(2) << x << ' ';
  cout << endl;

  cout << '#' << endl;
  list<int> l(9);
  generate(l.begin(), l.end(), [] () { return (rand() % 20); });
  for(auto x: l)
    cout << setw(2) << x << ' ';
  cout << endl;
  details::reverse(l.begin(), l.end());
  for(auto x: l)
    cout << setw(2) << x << ' ';
  cout << endl;
}
