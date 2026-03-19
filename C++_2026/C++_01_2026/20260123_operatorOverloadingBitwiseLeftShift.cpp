#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // BINARY << - Left shift THIS value by other.value positions
    SafeInt operator<<(const SafeInt& other) const {
        return SafeInt(value << other.value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(1);  // 5 << 1
    (a << b).print();    // 5 = 101b << 1 = 1010b = 10

    SafeInt c(3), d(2);  // 3 << 2
    (c << d).print();    // 3 = 011b << 2 = 1100b = 12

    SafeInt e(1), f(3);  // 1 << 3
    (e << f).print();    // 1 = 001b << 3 = 1000b = 8
}


/*
OUTPUT:

10
12
8

EXPLANATION:



*/


