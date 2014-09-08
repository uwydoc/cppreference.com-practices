// initializer_list.cpp

#include <initializer_list>
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <vector>

template<typename T>
struct Foo {
    std::vector<T> v;
    Foo(std::initializer_list<T> l) : v(l) {
        std::cout << "Constructred with a " << l.size() << "-element list"
                  << std::endl;
    }
    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // list-initialization in return statement
                                   // this is NOT a use of std::initializer_list
    }
};

template<typename T>
void templated_fn(T) {
    std::cout << "templated_fn instantiated with type "
              << typeid(T).name() << std::endl;
}

using namespace std;

int main()
{
    Foo<int> f = {1,2,3,4,5};  // direct list-initialization
    f.append({6,7,8});         // list-initialization in function call

    cout << "f.size " << f.c_arr().second << endl;
    for(auto n : f.v)
        cout << n << ' ';
    cout << endl;
    
    cout << "ranged-for over brace-init-list:" << endl;
    for (int i : {-1, -2, -3})  // the rule for auto make this ranged-for work
        cout << i << ' ';
    cout << endl;

    auto a = {10, 11, 12};  // special rule for auto
    cout << "a.size " << a.size() << endl;

    //templated_fn({1, 2, 3});  // compiler error! "{1, 2, 3}" is not an
    //                          // expression, it has no type, so T cannot
    //                          // be deduced
    templated_fn<initializer_list<int> >({1, 2, 3});  // OK
    templated_fn<vector<int> >({1, 2, 3});           // also OK
}
