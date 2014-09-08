// list.cpp
//
// Demos some member functions of std::list
//

#include <iostream>
#include <list>


std::ostream& operator<<(std::ostream& out, const std::list<int>& list)
{
    for (auto &i : list)
        out << i << ' ';
    return out;
}

using namespace std;

int main()
{
    list<int> l1 = {5,9,0,1,3};
    list<int> l2 = {8,7,2,6,4};

    // list::sort
    l1.sort();
    l2.sort();
    cout << "l1: " << l1 << endl
         << "l2: " << l2 << endl;
    // list::merge
    // algorithm used is the same as the one used in Merge-Sort
    l1.merge(l2);
    cout << "l1: " << l1 << endl
         << "l2: " << l2 << endl;
    // remove and remove_if
    l1.remove(2);
    l1.remove_if([] (int x) -> bool { return (x > 7); });
    cout << "l1: " << l1 << endl;
}
