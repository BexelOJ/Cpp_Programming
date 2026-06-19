#include <iostream>
class Singleton {
    static Singleton* instance;
    Singleton() {
        std::cout << "Instance Created" << std::endl;
    }
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton* getInstance(){
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void display() {
        std::cout << "Instance Displayed" << std::endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->display();
    
    Singleton* s2 = Singleton::getInstance();
    s2->display();

    bool x = (s1 == s2) ? true : false;
    std::cout<<x<< std::endl;
    return 0;
}


