// shuffle.cpp
// 
// Defined in header <algorithm>
// template< class RandomIt >
// void random_shuffle( RandomIt first, RandomIt last );
// template< class RandomIt, class RandomFunc >
// void random_shuffle( RandomIt first, RandomIt last, RandomFunc&& r );
// template< class RandomIt, class URNG >
// void random( RandomIt first, RandomIt last, URNG&& g );
// 

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <type_traits>
#include <vector>

namespace details {

  template<typename RandomIt, typename RandomFunc>
  void random_shuffle(RandomIt first, RandomIt last, RandomFunc&& r)
  {
    typename std::iterator_traits<RandomIt>::difference_type i, n;
    n = last - first;
    for(i = n - 1; i > 0; --i) {
      using std::swap;
      swap(first[i], first[r(i+1)]);
    }
  }

  template<typename RandomIt, typename URNG>
  void shuffle(RandomIt first, RandomIt last, URNG&& g)
  {
    typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
    typedef typename std::make_unsigned<diff_t>::type udiff_t;
    typedef typename std::uniform_int_distribution<udiff_t> distr_t;
    typedef typename distr_t::param_type param_t;

    distr_t D;
    diff_t n = last - first;
    for(diff_t i = n - 1; i > 0; --i) {
      using std::swap;
      swap(first[i], first[D(g, param_t(0, i))]);
    }
  }

}

using namespace std;

int main()
{
  vector<int> v(10);
  int i = 0;
  generate(v.begin(), v.end(), [i] () mutable -> int { return i++; });
  for(auto x: v)
    cout << setw(2) << x << ' ';
  cout << endl;
  // apply shuffle
  random_device rd;
  mt19937 g(rd());
  details::shuffle(v.begin(), v.end(), g);
  for(auto x: v)
    cout << setw(2) << x << ' ';
  cout << endl;
}
