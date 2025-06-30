#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
private:
    static Singleton* instance;
    static std::once_flag initFlag;

    // Private constructor
    Singleton() {
        std::cout << "Singleton created\n";
    }

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        std::call_once(initFlag, []() {
            instance = new Singleton();
        });
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something with singleton\n";
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::initFlag;

void worker() {
    Singleton::getInstance()->doSomething();
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);
    std::thread t3(worker);

    t1.join();
    t2.join();
    t3.join();
}

