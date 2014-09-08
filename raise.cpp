// raise.cpp
//
// Defined in header <csignal>
// int raise(int sig);
//

#include <csignal>
#include <iostream>

void signal_handler(int sig)
{
    std::cout << "Received signal " << sig << std::endl;
}

int main()
{
    std::signal(SIGTERM, signal_handler);
    std::cout << "Sending signal " << SIGTERM << std::endl;
    std::raise(SIGTERM);
}
