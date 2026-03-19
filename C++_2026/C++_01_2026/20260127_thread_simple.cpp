#include <iostream>
#include <thread>

void counter() {  // worker thread
    for (int i = 0; i < 100; i++) {
        std::cout << "Value of i in counter() is : " << i << std::endl;
    }
}
int main() {
    unsigned int c1 = std::thread::hardware_concurrency();
    std::cout << "Cores Available: " << c1 << std::endl;
    
    std::thread t1(counter);
    
    t1.join();
    //t1.detach();
    for (int i = 0; i < 100; i++) {
        std::cout << "Main i : " << i << std::endl;
    }
    
    unsigned int c2 = std::thread::hardware_concurrency();
    std::cout << "Cores Available: " << c2 << std::endl;
    
    return 0;
}

