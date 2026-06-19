#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // COMPOUND |= - OR THIS value with other.value AND ASSIGN
    SafeInt& operator|=(const SafeInt& other) {
        value |= other.value;  // Modifies this->value
        return *this;          // Enables chaining
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt a(5), b(2);     // 5=101b, 2=010b
    a |= b;                 // 101 | 010 = 111b = 7
    a.print();              // 7

    SafeInt c(8), d(4);     // 8=1000b, 4=0100b
    c |= d;                 // 1000 | 0100 = 1100b = 12
    c.print();              // 12

    // Chaining!
    SafeInt e(1);
    e |= SafeInt(2) |= SafeInt(4);  // 1 | 6 | 4 = 7
    e.print();                      // 7
}


/*
OUTPUT:

7
12
7

EXPLANATION:


*/



