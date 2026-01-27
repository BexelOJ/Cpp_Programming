#include <iostream>
#include <thread>

int main() {
    std::cout << "Cores Available: " << std::thread::hardware_concurrency << std::endl;
    return 0;
}

