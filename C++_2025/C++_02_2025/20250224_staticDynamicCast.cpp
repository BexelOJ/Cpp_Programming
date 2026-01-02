#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}  // Virtual destructor for polymorphism
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived class!" << endl;
    }
};

class AnotherClass : public Derived {
public:
    void print() {
        cout << "Another class!" << endl;
    }
};

int main() {
    Base* objB1 = new Derived;
    Derived* derivedPtr;

    // Static cast (unsafe)
    derivedPtr = static_cast<Derived*>(objB1); // This will succeed, but is unsafe if objB1 is not actually a Derived object
    derivedPtr->print(); // Output: Derived class!

    // Dynamic cast (safe)
    derivedPtr = dynamic_cast<Derived*>(objB1); // This will succeed because objB1 points to a Derived object
    if (derivedPtr) {
        derivedPtr->print(); // Output: Derived class!
    }

    // Another example with invalid cast
    Base* objB2 = new AnotherClass;
    derivedPtr = dynamic_cast<Derived*>(objB2); // This will fail and set derivedPtr to nullptr
    if (derivedPtr == nullptr) {
        cout << "Dynamic cast failed, objB2 is not of type Derived." << endl;
    }

    delete objB1;
    delete objB2;
    return 0;
}

