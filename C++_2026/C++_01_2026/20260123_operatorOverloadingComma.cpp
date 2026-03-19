#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // COMMA OPERATOR - Evaluate left, then right, return right
    SafeInt operator,(const SafeInt& other) const {
        return other;  // Discard left result, return right
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(10), c;

    c = (a, b);      // Evaluates a (discards), then b, assigns b to c
    c.print();       // 10

    SafeInt result = (SafeInt(1), SafeInt(2), SafeInt(3));
    result.print();  // 3 (rightmost result)
}


/*
OUTPUT:

10
3

*/

