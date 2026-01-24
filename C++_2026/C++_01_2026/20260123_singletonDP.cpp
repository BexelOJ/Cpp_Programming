#include <iostream>

class Singleton {
    static Singleton* instance;
    Singleton() {
        std::cout << "Constructor Called"<<std::endl;
    }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void display() {
        std::cout << "Instance Created" << std::endl;
    }

    ~Singleton() {
        std::cout << "Destructor Called" << std::endl;
    }

};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance(); // new instance created.
    s1->display();

    Singleton* s2 = Singleton::getInstance();  // s2 points to the same instance. 
    s2->display();

    Singleton* s3 = Singleton::getInstance();  // s3 also points to the same instance.
    s3->display();
    
    std::cout << ((s1 == s2) ? "Same Instance" : "Different Instance") << std::endl;

    delete s1;

    return 0;
}

