#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // COMPOUND >>= - Right shift THIS value by other.value positions AND ASSIGN
    SafeInt& operator>>=(const SafeInt& other) {
        value >>= other.value;  // Modifies this->value
        return *this;           // Enables chaining
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(1);
    a >>= b;  // 5 >> 1 = 2, a.value becomes 2
    a.print(); // 2

    SafeInt c(8), d(2);
    c >>= d;  // 8 >> 2 = 2, c.value becomes 2
    c.print(); // 2

    // Chaining works!
    SafeInt e(16);
    e >>= SafeInt(1) >>= SafeInt(1);  // 16>>1>>1 = 4
    e.print(); // 4
}


/*
OUTPUT:

2
2
16

EXPLANATION:



*/


