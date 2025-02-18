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

    // No explicit copy constructor, shallow copy by default
    void Display() const {
        cout << "a: " << *a << ", b: " << *b << ", c: " << c << endl;
    }

    // Destructor to free dynamically allocated memory
    ~Base() {
        delete a;
        delete b;
        cout << "Base Destructor Called" << endl;
    }
};

int main() {
    Base* b1 = new Base(1, 2);  // Heap-based object
    Base* b2 = b1;              // Shallow copy (b2 points to the same memory as b1)

    b1->Display();
    b2->Display();

    delete b1; // Frees the memory for b1 (and b2 points to the same memory)
    return 0;
}
