#include <iostream>

class Singleton {
    static Singleton* instance;
    Singleton() {
        std::cout << "Constructor called" << std::endl;
    }
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton;
        }
        return instance;
    }

    void showMessage() {
        std::cout << " Message Displayed " << std::endl;
    }
    static int getInstancePtr() {
        int s = sizeof(*instance);
        return s;
    }

};

Singleton* Singleton::instance = nullptr;

int main() {
    std::cout << Singleton::getInstancePtr() << std::endl;

    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    std::cout << Singleton::getInstancePtr() << std::endl;

    Singleton* s2 = Singleton::getInstance();
    s2->showMessage();

    bool r = (s1 == s2) ? true : false;
    std::cout << r << std::endl;
    return 0;
}






