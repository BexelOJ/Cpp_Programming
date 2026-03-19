#include <iostream>

class SafeInt {
private:
    int value;
    mutable int modified;  // For demo
public:
    SafeInt(int v = 0) : value(v), modified(0) {}

    void print() const {
        std::cout << "Value: " << value << ", Modified: " << modified << std::endl;
    }

    int getValue() const { 
        return value; 
    }

    void setValue(int v) { 
        value = v; 
        modified++; 
    }
};

// SMART POINTER WITH DEREFERENCE
class SmartPtr {
private:
    SafeInt* ptr;
public:
    SmartPtr(SafeInt* p) : ptr(p) {}

    // DEREFERENCE OPERATOR *
    SafeInt& operator*() {
        return *ptr;
    }

    const SafeInt& operator*() const {
        return *ptr;
    }

    // ARROW OPERATOR ->
    SafeInt* operator->() {
        return ptr;
    }

    const SafeInt* operator->() const {
        return ptr;
    }
};

int main() {
    SafeInt obj(42);

    SmartPtr sp(&obj);

    // DEREFERENCE WORKS!
    (*sp).print();                    // obj.print()
    std::cout << (*sp).getValue() << std::endl;  // 42

    // MODIFY THROUGH DEREFERENCE
    (*sp).setValue(100);
    sp->print();                      // 100 (arrow chaining)

    return 0;
}


/*
OUTPUT:

Value: 42, Modified: 0
42
Value: 100, Modified: 1

*/


