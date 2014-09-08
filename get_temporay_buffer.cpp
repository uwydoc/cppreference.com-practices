// get_temporary_buffer.cpp
// Defined in header <memory>
//
// tempalte<typename T>
// std::pair<T*, std::ptrdiff_t> get_temporary_buffer(std::ptrdiff_t count);

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
    const string strs[] = {"string", "is", "string", "..."};
    const constexpr size_t size = sizeof(strs) / sizeof(void*);
    if (true) {
        shared_ptr<string> p(get_temporary_buffer<string>(size).first,
                             return_temporary_buffer<string>);
        copy(begin(strs), end(strs), raw_storage_iterator<string*, string>(p.get()));
        for (string* i = p.get(); i != p.get()+size; ++i) {
            cout << *i << endl;
            i->~basic_string<char>();  // must perform to free heap memory
        }
    }
}
