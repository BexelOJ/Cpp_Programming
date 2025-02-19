#include <iostream>

class Base {
public:
    Base() { std::cout << "Base class constructor\n"; }
    virtual ~Base() { std::cout << "Base class destructor\n"; } // Virtual destructor
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived class constructor\n"; }
    ~Derived() { std::cout << "Derived class destructor\n"; }
};

int main() {
    // Create a Derived object but delete it using a Base pointer
    Base* basePtr1 = new Base();
    Base* basePtr2 = new Derived();
    
    // When the object is deleted, both destructors should be called
    delete basePtr1;
    delete basePtr2;
    
    return 0;
}


/*
Output:

Base class constructor
Base class constructor
Derived class constructor
Base class destructor
Derived class destructor
Base class destructor
*/

