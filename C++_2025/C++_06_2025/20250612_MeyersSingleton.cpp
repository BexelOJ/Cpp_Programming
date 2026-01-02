#include <iostream>
using namespace std;

class Singleton {
private:
    // Private constructor
    Singleton() {
        cout << "Constructor Called" << endl;
    }

    // Delete copy constructor and copy assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Static method that returns reference to single instance
    static Singleton& getinstance() {
        static Singleton instance;  // Guaranteed to be lazy-initialized and thread-safe in C++11+
        return instance;
    }

    void showMessage() {
        cout << "Hello from Meyers Singleton" << endl;
    }
};

int main() {
    // Access Singleton instance
    Singleton& s1 = Singleton::getinstance();
    s1.showMessage();

    Singleton& s2 = Singleton::getinstance();
    s2.showMessage();

    // Check if both are same
    cout << "s1 and s2 are " << (&s1 == &s2 ? "Same" : "Different") << " instance" << endl;

    return 0;
}
