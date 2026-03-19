#include <iostream>

class Functor {
public:
    // Overload operator() with parameters
    int operator()(int x) {
        return x * 2;
    }

    // Multiple overloads
    double operator()(double x, double y) {
        return x + y;
    }
};

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}
    int getValue() const { 
        return value; 
    }

    void setValue(int v) { 
        value = v; 
    }
};

// FUNCTOR - Callable SmartPtr!
class SmartPtr {
private:
    SafeInt* ptr;
public:
    SmartPtr(SafeInt* p) : ptr(p) {}

    // EXISTING: * and ->
    SafeInt& operator*() { 
        return *ptr; 
    }
    
    SafeInt* operator->() { 
        return ptr; 
    }

    // NEW: () FUNCTION CALL!
    SafeInt& operator()(int index = 0) {
        std::cout << "Called with index: " << index << std::endl;
        return *ptr;  // Return reference
    }
};

int main() {
    SafeInt obj(42);
    SmartPtr sp(&obj);

    // All three work!
    sp(10);           // () functor call ✓
    (*sp).setValue(100);  // * dereference ✓
    sp->setValue(200);    // -> arrow ✓

    std::cout << obj.getValue() << std::endl;  // 200
}

/*
OUTPUT:

Called with index: 10
200

*/

