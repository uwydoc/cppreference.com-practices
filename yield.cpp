// yield.cpp
//
// Defined in header <thread>
//

#include <chrono>
#include <iostream>
#include <thread>

void little_sleep(std::chrono::microseconds usec)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start + usec;
    do {
        std::this_thread::yield();
    } while(std::chrono::high_resolution_clock::now() < end);
}

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();
    int usec = 100;
    cout << "sleep for " << usec << endl;
    little_sleep(chrono::microseconds(usec));
    auto elapsed = chrono::high_resolution_clock::now() - start;
    cout << "waited for "
         << chrono::duration_cast<chrono::microseconds>(elapsed).count()
         << " microseconds" << endl;
}
