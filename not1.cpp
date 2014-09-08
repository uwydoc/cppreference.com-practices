// not1.cpp
// Demos the usage of std::not1 defined in <functional>

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

struct LessThan7 : std::unary_function<int, bool>
{
    bool operator()(int i) const { return i < 7; }
};

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    cout << count_if(v.begin(), v.end(), not1(LessThan7())) << endl;

    function<bool(int)> less_than_9 = [](int x) { return x < 9; };
    cout << count_if(v.begin(), v.end(), not1(less_than_9)) << endl;
}
