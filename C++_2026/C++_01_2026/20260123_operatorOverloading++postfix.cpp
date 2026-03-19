#include <iostream>

class Base {
public:
    int x = 10;

    Base(int val = 10) :x(val) {}

    /*
    // Prefix ++b1 (member function, NO parameters)
    Base& operator++() {
        ++x;  // Increment member variable
        return *this;  // Return reference to self
    }
    */

    // POSTFIX b1++  ← ADD THIS
    Base operator++(int) {      // 'int' distinguishes postfix
        Base old = *this;       // Save old value
        ++x;                    // Increment (use prefix)
        return old;             // Return old value
    }

    void display() {
        std::cout << "Value of x = " << x << std::endl;
    }
};

int main() {
    Base b1;
    b1.display();  // Value of x = 10

   // ++b1;          // Calls operator++()
   // b1.display();  // x = 11

    b1++;
    b1.display();  // Value of x = 11

    return 0;
}


