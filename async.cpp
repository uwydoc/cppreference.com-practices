// async.cpp
//
// Defined in header <future>
// template< class Function, class... Args >
// std::future<typename std::result_of<Function(Args...)>::type>
// async( Function&& f, Args&&... args );
// template< class Function, class... Args >
// std::future<typename std::result_of<Function(Args...)>::type>
// async( std::launch policy, Function&& f, Args&&... args );
//

#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <vector>

template<typename RAIter>
int parallel_sum(RAIter first, RAIter last)
{
    typename RAIter::difference_type size = last - first;
    if(size < 10000)
        return std::accumulate(first, last, 0);

    RAIter middle = first + size/2;
    std::future<int> fut = std::async(std::launch::async,
                                      parallel_sum<RAIter>, first, middle);
    return parallel_sum(middle, last) + fut.get();
}

int main()
{
    std::vector<int> v(1000000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
}
