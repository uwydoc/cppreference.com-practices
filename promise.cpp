// promise.cpp
//
// Defined in header <future>
//

#include <future>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    promise<int> r;
    thread t([&]{
            try {
                throw runtime_error("example");
            } catch(...) {
                try {
                    // store anything thrown in the promise
                    r.set_exception(current_exception());
                } catch(...) {}  // set_exception may throw as well
            }
    });

    try {
        cout << r.get_future().get();
    } catch(const exception& e) {
        cout << "Exception from the thread: " << e.what() << endl;
    }
    t.join();
}
