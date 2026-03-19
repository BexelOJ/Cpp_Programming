#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // UNARY ~ - Bitwise NOT (inverts all bits)
    SafeInt operator~() const {
        return SafeInt(~value);
    }

    // Your existing OR operator
    SafeInt operator|(const SafeInt& other) const {
        return SafeInt(value | other.value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};



int main() {
    SafeInt a(5);   // 000...0101b
    SafeInt b(0);

    (~a).print();   // ~5 = 111...1010b = -6 (two's complement)
    (~b).print();   // ~0 = 111...1111b = -1

    SafeInt c(12);  // 000...1100b
    (~c).print();   // ~12 = 111...0011b = -13
}



/*
OUTPUT:

-6
-1
-13


EXPLANATION:

a(5)  = 00000000000000000000000000000101b
~a    = 11111111111111111111111111111010b = -6 ✓

c(12) = 00000000000000000000000000001100b
~c    = 11111111111111111111111111110011b = -13 ✓


*/

