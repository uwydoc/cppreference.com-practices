// packaged_task.cpp
//
// Defined in header <future>
// template< class >
// class packaged_task;  // not defined
// template< class R, class Args... >
// class packaged_task<R(Args...)>;
//

#include <chrono>
#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

void task_lambda()
{
    std::packaged_task<int(int,int)> task([] (int a, int b) {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return ::pow(a, b);
    });
    std::future<int> fut = task.get_future();
    std::thread task_t(std::move(task), 2, 9);
    std::cout << "task_lambda:\t" << fut.get() << '\n';
    task_t.join();
}

void task_bind()
{
    std::packaged_task<int()> task(std::bind(::pow, 2, 10));
    std::future<int> fut = task.get_future();
    task();
    std::cout << "task_bind:\t" << fut.get() << '\n';
}

void task_thread()
{
    std::packaged_task<int(int,int)> task(::pow);
    std::future<int> fut = task.get_future();
    std::thread task_t(std::move(task), 2, 11);
    task_t.join();
    std::cout << "task_thread:\t" << fut.get() << '\n';
}

int main()
{
    task_bind();
    task_lambda();
    task_thread();
}
