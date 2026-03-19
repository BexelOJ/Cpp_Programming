#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // Logical AND - both must be non-zero
    bool operator&&(const SafeInt& other) const {
        return (value != 0) && (other.value != 0);
    }

    void print() const { 
        std::cout << value << std::endl; 
    }
};


int main() {
    SafeInt a(5), b(3), c(0), d(7);

    std::cout << (a && b) << std::endl;  // 1 (true: 5 && 3 both non-zero)
    std::cout << (a && c) << std::endl;  // 0 (false: 5 && 0)
    std::cout << (c && d) << std::endl;  // 0 (false: 0 && 7)
    std::cout << std::boolalpha;              // Human-readable, all below
    std::cout << (a && b) << std::endl;  // true
}


/*
OUTPUT:

1
0
0
true

*/


