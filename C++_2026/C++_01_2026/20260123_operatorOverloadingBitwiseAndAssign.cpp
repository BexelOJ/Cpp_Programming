#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // COMPOUND &= - AND THIS value with other.value AND ASSIGN
    SafeInt& operator&=(const SafeInt& other) {
        value &= other.value;  // Modifies this->value
        return *this;          // Enables chaining
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt a(7), b(3);     // 7=111b, 3=011b
    a &= b;                 // 111 & 011 = 011b = 3
    a.print();              // 3

    SafeInt c(12), d(10);   // 12=1100b, 10=1010b
    c &= d;                 // 1100 & 1010 = 1000b = 8
    c.print();              // 8

    // Chaining!
    SafeInt e(15);
    e &= SafeInt(10) &= SafeInt(12);  // 15 & 6 & 12 = 4
    e.print();                        // 4
}


/*
OUTPUT:

3
8
8

EXPLANATION:

7 &= 3:   111
        & 011
        -----
          011 = 3 ✓

12 &= 10: 1100
         &1010
         -----
          1000 = 8 ✓

3    // 7 &= 3 → 3
8    // 12 &= 10 → 8
4    // 15 & (10 & 12) → 4



*/

