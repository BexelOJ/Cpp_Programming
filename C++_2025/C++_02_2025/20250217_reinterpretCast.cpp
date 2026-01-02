#include <iostream>

class Base {
public:
    Base() { std::cout << "Base class constructor\n"; }
    ~Base() { std::cout << "Base class destructor\n"; }  // Non-virtual destructor
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived class constructor\n"; }
    ~Derived() { std::cout << "Derived class destructor\n"; }
};

int main() {
    Base* basePtr = new Derived();
    
    // Manually call the Derived destructor (bypassing the base class destructor)
    delete reinterpret_cast<Derived*>(basePtr);  // This calls the Derived destructor only
    
    return 0;
}

