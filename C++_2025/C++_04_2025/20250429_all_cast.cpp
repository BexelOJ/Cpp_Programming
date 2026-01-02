#include <iostream>
using namespace std;

class Base {
public:
    virtual void speak() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void speak() override { cout << "Derived\n"; }
};

int main() {
    // 1. static_cast
    double pi = 3.14;
    int intPi = static_cast<int>(pi);  // Convert double to int
    cout << "static_cast: " << intPi << endl;

    // 2. dynamic_cast
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  // Safe downcast
    if (derivedPtr) {
        cout << "dynamic_cast: ";
        derivedPtr->speak();  // Output: Derived
    }

    // 3. const_cast
    const int a = 10;
    int* modifiable = const_cast<int*>(&a);  // Remove const
    cout << "const_cast before: " << *modifiable << endl;
    *modifiable = 20;  // Undefined behavior if 'a' was really const
    cout << "const_cast after: " << *modifiable << endl;

    // 4. reinterpret_cast
    long address = 123456;
    int* ptr = reinterpret_cast<int*>(address);  // Dangerous, rarely useful in high-level code
    cout << "reinterpret_cast: " << ptr << endl;

    delete basePtr;
    return 0;
}



