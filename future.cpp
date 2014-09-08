// future.cpp
//
// Defined in header <future>
// template< class T > class future;
// template< class T > class future<T&>;
// template<>          class future<void>;
//

#include <chrono>
#include <future>
#include <iostream>
#include <thread>

int main()
{
    // future for a packaged_task
    std::packaged_task<int()> task([](){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return 7;
    });
    std::future<int> f1 = task.get_future();
    std::thread(std::move(task)).detach();

    // future from an async
    std::future<int> f2 = std::async(std::launch::async, [](){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return 8;
    });

    // future from a promise
    std::promise<int> p;
    std::future<int> f3 = p.get_future();
    std::thread([&p](){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            p.set_value(9);
    }).detach();

    std::cout << "Waiting...\n" << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();
    std::cout << "Done!\nResults are: ";
    std::cout << f1.get() << ' ' << f2.get() << ' ' << f3.get() << '\n';
}
