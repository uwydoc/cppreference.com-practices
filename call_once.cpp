// call_once.cpp
//
// Defined in header <mutex>
// template< class Function, class... Args >
// void call_once( std::once_flag& flag, Function&& f, Args&&... args );
//

#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;

void do_once(int index)
{
    std::call_once(flag, [=]() {
            std::cout << "Called once #" << index << '\n';
    });
}

std::once_flag flag1, flag2;

void do_twice(int index)
{
    std::call_once(flag1, [](int index) {
        std::cout << "Called twice 1st #" << index << '\n';
    }, index);
    std::call_once(flag2, [](int index) {
        std::cout << "Called twice 2nd #" << index << '\n';
    }, index);
}

int main()
{
    std::thread t1(do_twice, 1);
    std::thread t2(do_twice, 2);
    std::thread t3(do_twice, 3);
    std::thread t4(do_twice, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
