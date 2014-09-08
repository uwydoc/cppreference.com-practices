// current_exception.cpp
// Defined in header <exception>
// Get the current active exception object and return a std::shared_ptr to it

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

void handle_exception(std::exception_ptr eptr)
{
    try {
        if (eptr != std::exception_ptr()) {
            std::rethrow_exception(eptr);
        }
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

using namespace std;

int main()
{
    exception_ptr eptr;
    try {
        string().at(1);  // throw std::out_of_range
    } catch (...) {
        eptr = current_exception();  // capture
    }
    handle_exception(eptr);
}  // destructor for std::out_of_range called here, when eptr is destructed
