#include <iostream>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v) : value(v) {}

    // Overload % for remainder
    SafeInt operator%(const SafeInt& other) const {
        if (other.value == 0) {
            throw std::runtime_error("Division by zero");
        }
        return SafeInt(value % other.value);
    }

    void print() const {
        std::cout << value << std::endl;
    }
};

int main() {
    SafeInt a(10), b(3);
    SafeInt result = a % b;  // 10 % 3 = 1
    result.print();  // Output: 1
}


/*
OUTPUT:

1

*/


