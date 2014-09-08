// decay_mod.cpp
// Possible implementation of std::decay defined in <type_traits>

#include <iostream>
#include <type_traits>
#include <typeinfo>

template<typename T>
struct decay_mod {
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

using namespace std;

int main()
{
    typedef int IntType;
    typedef int* IntPtrType;
    typedef int IntArrayType[10];
    typedef void (*FuncType)();

    cout << boolalpha
         << is_same<decay<IntType>::type, decay_mod<IntType>::type >::value << endl
         << is_same<decay<IntPtrType>::type, decay_mod<IntPtrType>::type>::value << endl
         << is_same<decay<IntArrayType>::type, decay_mod<IntArrayType>::type>::value << endl
         << is_same<decay<FuncType>::type, decay_mod<FuncType>::type>::value << endl
         << is_same<decay<FuncType>::type, decay_mod<IntArrayType>::type>::value << endl;

    cout << boolalpha
         << typeid(decay<IntType>::type).name() << ' '
         << typeid(decay_mod<IntType>::type).name() << endl
         << typeid(decay<IntPtrType>::type).name() << ' '
         << typeid(decay_mod<IntPtrType>::type).name() << endl
         << typeid(decay<IntArrayType>::type).name() << ' '
         << typeid(decay_mod<IntArrayType>::type).name() << endl
         << typeid(decay<FuncType>::type).name() << ' '
         << typeid(decay_mod<FuncType>::type).name() << endl;
}
