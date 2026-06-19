#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // *= modifies THIS object, returns reference for chaining
    SafeInt& operator%=(const SafeInt& other) {
        value %= other.value;
        return *this;
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt a(17), b(3);
    a %= b;  // a.value becomes 17 % 3 = 2
    a.print();  // Output: 2

    /*
    SafeInt c(10);
    c /= c /= SafeInt(2);  // Chaining works: c /= (c /= 2) = 10 /= 2
    c.print();  // Output: 400
    */
}

/*
OUTPUT:

2

*/


