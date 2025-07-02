#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {}  // RTTI enabled
};

class Derived : public Base {
public:
    void hello() { std::cout << "Hi from Derived\n"; }
};

int main(){
Base* b = new Derived();  // Condition 1: ✔️
Derived* d = dynamic_cast<Derived*>(b);  // Condition 2: ✔️ RTTI works

if (d)
    d->hello();  // Works!
else
    cout << "dynamic_cast failed" << endl;

return 0;
}

/*
Condition 1:
while using a dynamic_cast, the base class must have at least one virtual function to enable RTTI (Run-Time Type Information).
This is typically done by declaring a virtual destructor in the base class, as shown in the example.
This allows the dynamic_cast to safely downcast from a base class pointer to a derived class pointer.
// If the base class does not have a virtual function, dynamic_cast will fail at runtime and return nullptr.

condition 2:
Base* b = new Derived();
downcast from a base class pointer to a derived class pointer.
object should be of derived type, otherwise dynamic_cast will return nullptr.
if object is of base type or not derived from base, dynamic_cast will return nullptr.
*/

