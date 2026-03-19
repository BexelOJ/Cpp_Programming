#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // 1. ARROW OPERATOR -> 
    SafeInt* operator->() const {
        return const_cast<SafeInt*>(this);
    }

    void print() const {
        std::cout << "Value: " << value << std::endl;
    }
};

// 2. SMART POINTER WRAPPER (Real-world use)
class SmartPtr {
private:
    SafeInt* ptr;
public:
    SmartPtr(SafeInt* p) : ptr(p) {}

    // Delegates arrow to actual object
    SafeInt* operator->() const {
        return ptr;
    }
};

int main() {
    SafeInt obj(42);

    // Direct object usage
    obj->print();      // Works via SafeInt::operator->()

    // Smart pointer usage  
    SmartPtr sp(&obj);
    sp->print();       // Works via SmartPtr::operator->()

    return 0;
}
