#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // BINARY << - Left shift THIS value by other.value positions
    SafeInt operator>>(const SafeInt& other) const {
        return SafeInt(value >> other.value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(1);  // 5 >> 1
    (a >> b).print();    // 5 = 101b >> 1 = 0010b = 2

    SafeInt c(3), d(2);  // 3 >> 2
    (c >> d).print();    // 3 = 011b >> 2 = 0000b = 0

    SafeInt e(8), f(3);  // 8 >> 3
    (e >> f).print();    // 1 = 1000b >> 3 = 0001b = 1
}


/*
OUTPUT:

2
0
1

EXPLANATION:



*/


