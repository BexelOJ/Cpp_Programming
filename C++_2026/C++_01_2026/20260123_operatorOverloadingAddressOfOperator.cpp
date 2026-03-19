#include <iostream>

class SafeInt {
public:
    int value;
    SafeInt(int v = 0) : value(v) {}

    // ✅ Const-correct address-of
    const SafeInt* operator&() const {
        return reinterpret_cast<const SafeInt*>(&value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt obj(42);
    const SafeInt* ptr = &obj;  // Now works!
    std::cout << ptr->value << std::endl;  // 42
}


/*
OUTPUT:

42

*/


