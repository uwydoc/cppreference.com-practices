// chrono.cpp

#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << std::chrono::seconds(3).count() << '\n';
}
