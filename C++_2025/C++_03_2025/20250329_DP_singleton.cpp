#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;  

    Singleton() {    // constructor
        cout << "Constructor Called" << endl;
    }

public:
    Singleton(const Singleton&) = delete;  //  copy constructor is deleted, which prevents objects of the Singleton class from being copied.
    Singleton& operator=(const Singleton&) = delete;  // copy assignment operator is deleted, which prevents assigning one Singleton object to another.

    static Singleton* getinstance()
    {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton" << endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main()
{

    Singleton* s1 = Singleton::getinstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getinstance();
    s2->showMessage();

    cout << "s1 and s2 are " << (s1 == s2 ? "Same" : "Different") << " instance" << endl;
    return 0;
}



