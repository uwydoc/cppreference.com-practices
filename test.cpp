// test.cpp
//

#include <algorithm>
#include <array>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <thread>
#include <typeinfo>
#include <type_traits>
#include <utility>

#include <math.h>

namespace details {

template<typename T1, typename T2>
struct decay_is_same
    : std::integral_constant<
        bool,
        std::is_same<
            typename std::decay<T1>::type,
            typename std::decay<T2>::type
        >::value
      >
{};

template<typename T>
typename std::decay<T>::type decay_cp(T&& t)
{
    return std::forward<T>(t);
}

}

void foo(int n)
{
    std::cout << "Thread " << n << std::endl;
}

int fake_pow(int a, int b)
{
    return pow(a, b);
}

using namespace std;

int main()
{
    typedef int IntType;
    typedef int* IntPtrType;
    typedef int& IntRefType;

    cout << boolalpha
         << is_same<IntType, IntPtrType>::value << ' '
         << is_same<IntType, IntRefType>::value << ' '
         << is_same<IntPtrType, IntRefType>::value << endl;
    cout << boolalpha
         << details::decay_is_same<IntType, IntPtrType>::value << ' '
         << details::decay_is_same<IntType, IntRefType>::value << ' '
         << details::decay_is_same<IntPtrType, IntRefType>::value << endl;

    // array::max_size
    array<int, 3> a = {1,2,3};
    cout << a.size() << ' ' <<  a.max_size() << ' '
         << numeric_limits<tuple_element<0, decltype(a)>::type>::max() << endl;
    // std::copy_n
    string s1 = "hello";
    string s2 = "world";
    auto it = copy_n(s1.begin(), 0, s2.begin());
    cout << boolalpha
         << (it == s1.begin()) << ' '
         << (it == s2.begin()) << endl;
    cout << s2 << endl;
    copy_n(s1.begin(), 2, s2.begin());
    cout << s2 << endl;
    // std::rotate
    string s3 = "hello world";
    auto first = s3.begin();
    auto n_last = s3.begin() + 3;
    auto n_first = s3.begin() + 4;
    auto last = s3.end();
    rotate(first, n_first, last);
    cout << s3 << endl
         << string(first, last) << endl
         << string(n_first, last) << endl
         << string(first, n_first) << endl;
    cout << boolalpha
         << (n_first == s3.begin()) << ' '
         << (n_last == s3.end()) << endl;
    // iterator_traits
    cout << boolalpha
         << details::decay_is_same<
                iterator_traits<deque<int>::iterator>::iterator_category,
                random_access_iterator_tag
            >::value << endl;
    // std::thread
    cout << "hw_con: " << std::thread::hardware_concurrency() << endl;
    thread t(foo, 2);
    t.join();
    // std::bind
    auto fn = bind(::pow, 2, 4);
    cout << "bind(pow, 2, 4): " << fn() << endl;
}
