#include <iostream>
using namespace std;

class Base {
private:
    int a;
    int b;

public: 
    int c;

    // Constructor to initialize values
    Base(int x, int y) : a(x), b(y), c(30) {
        cout << "Base Constructor Called" << endl;
    }

    // No explicit copy constructor, shallow copy by default
    void Display() const {
        cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    }
};

int main() {
    Base b1(1, 2); // Stack-based object
    Base b2 = b1;  // Shallow copy (uses default copy constructor)

    b1.Display();
    b2.Display();
    return 0;
}
/*
Output:

Base Constructor Called
a: 1, b: 2, c: 30
a: 1, b: 2, c: 30
*/

