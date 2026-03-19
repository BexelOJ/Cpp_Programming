#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // Bitwise AND - & between integer values
    SafeInt operator&(const SafeInt& other) const {
        return SafeInt(value & other.value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};


int main() {
    SafeInt a(5), b(3);  // 5 = 101b, 3 = 011b

    SafeInt result = a & b;  // 101 & 011 = 001 = 1
    result.print();          // Output: 1

    SafeInt c(12), d(10);    // 12=1100b, 10=1010b
    SafeInt e = (c & d);
    //(c & d).print();         // 1100 & 1010 = 1000 = 8
    e.print();
}


/*
OUTPUT:

1
8

*/

