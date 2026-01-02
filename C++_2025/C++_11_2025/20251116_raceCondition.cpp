#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;

void shared_print(string msg, int id) {
    std::lock_guard<std::mutex> guard(mu); // RAII
    //mu.lock();
    std::cout << msg << id << std::endl;
    //mu.unlock();
}

void function_one() {
    for (int i = 0; i > -100; i--) {
        shared_print(string("From t1: "), i);
    }
}

int main() {
    std::thread t1(function_one);

    for (int i = 0; i < 100; i++) {
        shared_print(string("From main: "), i);
    }

    t1.join();

    return 0;
}



