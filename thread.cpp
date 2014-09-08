// thread.cpp
//
// Defined in header <thread>
//

#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <system_error>
#include <thread>
#include <utility>

void f1(int n)
{
    for(int i = 0; i < 5; ++i) {
        std::cout << "Thread " << n << " executing" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void f2(int& n)
{
    for(int i = 0; i < 5; ++i) {
        std::cout << "Thread 2 executing" << std::endl;
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

using namespace std;

int main()
{
    int n = 0;
    try {
        thread t1;
        cout << "thread" << endl;
        thread t2(f1, n+1);
        cout << "thread(f, args...)" << endl;
        thread t3(f2, std::ref(n));
        cout << "thread(f, args...) with args wrapped by std::ref" << endl;
        thread t4(std::move(t3));
        cout << "thread(thread&& other)" << endl;
        t2.join();
        t4.join();
    } catch(const system_error& e) {
        cerr << "system error occured: " << e.what() << endl;
        throw;
    }
    cout << "Final value of n is " << n << endl;
}
