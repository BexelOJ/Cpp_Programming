#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // *= modifies THIS object, returns reference for chaining
    SafeInt& operator*=(const SafeInt& other) {
        value *= other.value;
        return *this;
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt a(5), b(3);
    a *= b;  // a.value becomes 5 * 3 = 15
    a.print();  // Output: 15

    SafeInt c(10);
    c *= c *= SafeInt(2);  // Chaining works: c *= (c *= 2) = 10 *= 2
    c.print();  // Output: 400
}


/*
OUTPUT:

15
400

*/

