#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // COMPOUND ^= - XOR THIS value with other.value AND ASSIGN
    SafeInt& operator^=(const SafeInt& other) {
        value ^= other.value;  // Modifies this->value
        return *this;          // Enables chaining
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt a(5), b(3);     // 5=101b, 3=011b
    a ^= b;                 // 101 ^ 011 = 110b = 6
    a.print();              // 6

    SafeInt c(12), d(10);   // 12=1100b, 10=1010b
    c ^= d;                 // 1100 ^ 1010 = 0110b = 6
    c.print();              // 6

    // Chaining!
    SafeInt e(7);
    e ^= SafeInt(3) ^= SafeInt(1);  // 7 ^ 2 ^ 1 = 4
    e.print();                      // 4
}


/*
OUTPUT:

6
6
5

EXPLANATION:

5 ^= 3:   101
        ^ 011
        -----
          110 = 6 ✓

12 ^= 10: 1100
         ^1010
         -----
          0110 = 6 ✓


*/


