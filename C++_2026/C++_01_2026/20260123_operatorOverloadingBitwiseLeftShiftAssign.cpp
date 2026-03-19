#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // COMPOUND >>= - Right shift THIS value by other.value positions AND ASSIGN
    SafeInt& operator<<=(const SafeInt& other) {
        value <<= other.value;  // Modifies this->value
        return *this;           // Enables chaining
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(1);
    a <<= b;  
    a.print();

    SafeInt c(8), d(2);
    c <<= d;  
    c.print(); 

    // Chaining works!
    SafeInt e(16);
    e <<= SafeInt(1) <<= SafeInt(1);  
    e.print(); 
}


/*
OUTPUT:

10
32
64

EXPLANATION:



*/


