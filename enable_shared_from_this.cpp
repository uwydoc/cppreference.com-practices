// enable_shared_from_this.cpp
//
// Defined in <memory>
// template<class T> class enable_shared_from_this;

#include <iostream>
#include <memory>

struct Good : std::enable_shared_from_this<Good>
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};

struct Bad {
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad::~Bad() called" << std::endl; }
};

using namespace std;

int main()
{
    // Good: two shared_ptrs share the same object
    shared_ptr<Good> pt1(new Good);
    shared_ptr<Good> pt2 = pt1->getptr();
    cout << "pt2.use_count " << pt2.use_count() << endl;
    // Bad: each shared_ptr thinks it's the only owner of the object
    shared_ptr<Bad> pt3(new Bad);
    shared_ptr<Bad> pt4 = pt3->getptr();
    cout << "pt4.use_count " << pt4.use_count() << endl;
}
