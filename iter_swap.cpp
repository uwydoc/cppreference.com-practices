// iter_swap.cpp

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

template<typename ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt it = begin; it != end; ++it) {
        std::iter_swap(it, std::min_element(it, end));
    }
}

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-10, 10);
    vector<int> v;
    generate_n(back_inserter(v), 20, bind(dist, gen));
    
    cout << "Before sort: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    selection_sort(v.begin(), v.end());

    cout << "After sort: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}
