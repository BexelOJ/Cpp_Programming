#include <iostream>

class Singleton {
    Singleton() {
        std::cout << "Constructor Called" << std::endl;
    }

public:
    // Meyers' Singleton - thread-safe, automatic lifetime management
    static Singleton& getInstance() {
        static Singleton instance;  // C++11+ magic static: thread-safe, lazy init
        return instance;
    }

    void display() {
        std::cout << "Instance Created" << std::endl;
    }

    // Prevent copying/assignment (essential for Singleton)
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.display();

    Singleton& s2 = Singleton::getInstance();
    s2.display();

    Singleton& s3 = Singleton::getInstance();
    s3.display();

    return 0;
}
