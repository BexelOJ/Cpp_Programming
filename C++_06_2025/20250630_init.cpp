#include <iostream>
#include <mutex>
#include <thread>

std::once_flag flag;

void init() {
std::cout << "Initialized once\n";
}

void worker() {
std::call_once(flag, init);
std::cout << "Worker running\n";
}

int main() {
std::thread t1(worker);
std::thread t2(worker);
t1.join();
t2.join();
}
