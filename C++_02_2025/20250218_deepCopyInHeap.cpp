#include <iostream>
using namespace std;

class Base {
private:
    int* a;
    int* b;

public: 
    int c;

    // Constructor to initialize values
    Base(int x, int y) {
        a = new int(x);  // Dynamically allocated memory
        b = new int(y);  // Dynamically allocated memory
        c = 30;
        cout << "Base Constructor Called" << endl;
    }

    // Deep Copy Constructor
    Base(const Base& other) {
        cout << "Base Copy Constructor Called (Deep Copy)" << endl;
        a = new int(*(other.a)+ 3);  // Deep copy the dynamically allocated memory
        b = new int(*(other.b) + 3);  // Deep copy the dynamically allocated memory
        c = other.c + 3;
    }

    // Destructor to free dynamically allocated memory
    ~Base() {
        delete a;
        delete b;
        cout << "Base Destructor Called" << endl;
    }

    // Display function
    void Display() const {
        cout << "a: " << *a << ", b: " << *b << ", c: " << c << endl;
    }
};

int main() {
    Base* b1 = new Base(1, 2);  // Heap-based object
    Base* b2 = new Base(*b1);   // Deep copy constructor called

    b1->Display();
    b2->Display();

    delete b1; // Free memory for b1
    delete b2; // Free memory for b2
    return 0;
}

/*
Output:

Base Constructor Called
Base Copy Constructor Called (Deep Copy)
a: 1, b: 2, c: 30
a: 4, b: 5, c: 33
Base Destructor Called
Base Destructor Called
*/


