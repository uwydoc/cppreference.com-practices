// shared_future.cpp
//
// Defined in header <future>
// template< class T > class shared_future;
// template< class T > class shared_future<T&>;
// template<>          class shared_future<void>;
//

#include <chrono>
#include <future>
#include <iostream>

int main()
{
    std::promise<void> ready_promise, t1_ready_promise, t2_ready_promise;
    std::shared_future<void> ready_future(ready_promise.get_future());

    std::chrono::time_point<std::chrono::high_resolution_clock> start;

    auto t1 = [&]() -> std::chrono::duration<double, std::milli>
    {
        t1_ready_promise.set_value();
        ready_future.wait();  // wait for the signal from main
        return std::chrono::high_resolution_clock::now() - start;
    };
    auto t2 = [&]() -> std::chrono::duration<double, std::milli>
    {
        t2_ready_promise.set_value();
        ready_future.wait();  // wait for the signal from main
        return std::chrono::high_resolution_clock::now() - start;
    };

    auto r1 = std::async(std::launch::async, t1);
    auto r2 = std::async(std::launch::async, t2);

    // wait for threads to become ready
    t1_ready_promise.get_future().wait();
    t2_ready_promise.get_future().wait();

    // threads are ready, start the clock
    start = std::chrono::high_resolution_clock::now();

    // signal threads to go
    ready_promise.set_value();

    std::cout << "Thread 1 received the signal "
              << r1.get().count() << " ms after start\n"
              << "Thread 2 received the signal "
              << r2.get().count() << " ms after start\n";
}
