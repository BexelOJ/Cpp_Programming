#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // BINARY ^ - XOR THIS value with other.value
    SafeInt operator^(const SafeInt& other) const {
        return SafeInt(value ^ other.value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(3);     // 5=101b, 3=011b
    (a ^ b).print();        // 101 ^ 011 = 110b = 6

    SafeInt c(12), d(10);   // 12=1100b, 10=1010b
    (c ^ d).print();        // 1100 ^ 1010 = 0110b = 6

    SafeInt e(7), f(1);     // 7=111b, 1=001b
    (e ^ f).print();        // 111 ^ 001 = 110b = 6
}


/*
OUTPUT:

6
6
6

*/

