#include <iostream>

using namespace std;

class Base {
private:
    int a;
    int b;

public: 
    int c;

    // Parameterized constructor to initialize the object
    Base(int x, int y) : a(x), b(y), c(30) {
        cout << "Base Constructor Called" << endl;
    }

    // Custom copy constructor (Deep Copy)
    Base(const Base& other) {
        cout << "Base Copy Constructor Called" << endl;
        // Deep copy for each member
        a = other.a +2;
        b = other.b +2;
        c = other.c +2;
    }

    // Display function
    void Display() const {
        cout << "Inside Base Class" << endl;
        cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    }
};

int main() {
    // Create a stack-allocated object
    Base b1(1, 2);
    
    // Create another stack-allocated object using the custom copy constructor (deep copy)
    Base b2 = b1;  // This will invoke the copy constructor

    // Display both objects
    cout << "b1: ";
    b1.Display();
    cout << "b2: ";
    b2.Display();

    return 0;
}



/*
Output:

Base Constructor Called
Base Copy Constructor Called
b1: Inside Base Class
a: 1, b: 2, c: 30
b2: Inside Base Class
a: 1, b: 2, c: 30
*/

