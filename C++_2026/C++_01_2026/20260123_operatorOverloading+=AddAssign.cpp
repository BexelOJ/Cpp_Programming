#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    // += overload - takes right operand as parameter
    Counter& operator+=(int amount) {
        value += amount; // value = value + amount
        return *this;  // Return modified object
    }

    void print() { 
        std::cout << value << std::endl; 
    }
};

int main() {
    Counter c(5);
    c += 3;    // c.value becomes 8
    c.print(); // Outputs 8

    Counter d(10);
    d += -2;   // d.value becomes 8
    d.print(); // Outputs 8
}


