// decay.cpp
//
// Defined in header <type_traits>
// template< class T>
// struct decay;
//

#include <iostream>
#include <type_traits>

namespace details {

  template<typename T>
  struct decay {
    typedef typename std::remove_reference<T>::type U;
    typedef typename std::conditional<
      std::is_array<U>::value,
      typename std::remove_extent<U>::type*,
      typename std::conditional<
	std::is_function<U>::value,
	typename std::add_pointer<U>::type,
	typename std::remove_cv<U>::type
      >::type
    >::type type;
  };

}

using namespace std;

int main()
{
  typedef int IntType;
  typedef int* IntPtrType;
  typedef int& IntRefType;

  cout << boolalpha
       << is_same<std::decay<IntType>::type, details::decay<IntType>::type>::value << endl
       << is_same<std::decay<IntPtrType>::type, details::decay<IntPtrType>::type>::value << endl
       << is_same<std::decay<IntRefType>::type, details::decay<IntRefType>::type>::value << endl;
}
