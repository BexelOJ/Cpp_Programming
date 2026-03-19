#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    // += overload - takes right operand as parameter
   void operator-=(int amount) {
        value -= amount; // value = value + amount
        //return *this;  // Return modified object
    }

    void print() { 
        std::cout << value << std::endl; 
    }
};

int main() {
    Counter c(5);
    c -= 3;    // c.value becomes (5 - 3 = 2)
    c.print(); // Outputs 2

    Counter d(10);
    d -= -2;   // d.value becomes (10 - (-2) = +12)
    d.print(); // Outputs 12
}


/*
OUTPUT:

2
12

*/

