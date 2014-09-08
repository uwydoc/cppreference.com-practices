// set.cpp
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {5,3,4,1,2};
    for (auto& var : v)
        cout << var << ' ';
    cout << endl;
    set<int> s(v.begin(), v.end());
    s.insert(7);
    s.insert(0);
    for (auto& var : s)
        cout << var << ' ';
    cout << endl;
}
