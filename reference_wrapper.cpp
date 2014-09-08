// reference_wrapper.cpp
// Demos the usage of std::reference_wrapper defined in <functional>

#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main()
{
    list<int> l = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
    
    vector<reference_wrapper<int>> v1(l.begin(), l.end());
    random_shuffle(v1.begin(), v1.end());

    vector<reference_wrapper<int>> v2(v1.begin(), v1.end());
    partition(v2.begin(), v2.end(), [](int n) { return n<0; });

    cout << "Contents of the list: ";
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Contents of the list, shuffled: ";
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "Shuffled elements, partitioned: ";
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
