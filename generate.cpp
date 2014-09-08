// generate.cpp
// 
// Defined in header <algorithm>
// template< class ForwardIt, class Generator >
// void generate( ForwardIt first, ForwardIt last, Generator g );
// 

#include <algorithm>
#include <iostream>
#include <vector>

#include <cstdlib>

namespace details {

  template<typename ForwardIt, typename Generator>
  void generate(ForwardIt first, ForwardIt last, Generator g)
  {
    for(; first != last; ++first)
      *first = g();
  }

}

using namespace std;

int main()
{
  vector<int> v(5);
  details::generate(v.begin(), v.end(), std::rand);
  for(auto x: v)
    cout << x << ' ';
  cout << endl;
}
