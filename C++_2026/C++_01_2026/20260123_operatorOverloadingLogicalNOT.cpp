#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // Logical AND - both must be non-zero
    bool operator!() const {
        return (value == 0);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(3), c(0), d(7);

    std::cout << !a << std::endl;  // 0 (false: !true)
    std::cout << !b << std::endl;  // 0 (false: !true)
    std::cout << !c << std::endl;  // 1 (true: !false)
    std::cout << std::boolalpha;              // Human-readable, all below
    std::cout << !d << std::endl;  // false (!true)
}


/*
OUTPUT:

0
0
1
false

*/


