#include <iostream>
using namespace std;

class Base {
private:
    int a;
    int* ptr;

public:
    // Default constructor
    Base(int val = 0) {
        a = val;
        ptr = new int[10];  // Allocate memory for 10 integers
        for (int i = 0; i < 10; ++i)
            ptr[i] = 0;     // Initialize with 0
    }

    // Copy constructor for deep copy
    Base(const Base& other) {
        a = other.a;
        ptr = new int[10];  // Allocate new memory
        for (int i = 0; i < 10; ++i)
            ptr[i] = other.ptr[i];  // Deep copy values
    }

    // Assignment operator overload for deep copy
    Base& operator=(const Base& other) {
        if (this == &other)
            return *this; // Avoid self-assignment

        a = other.a;

        // Free old memory
        delete[] ptr;

        // Allocate new memory and copy
        ptr = new int[10];
        for (int i = 0; i < 10; ++i)
            ptr[i] = other.ptr[i];

        return *this;
    }

    // Destructor
    ~Base() {
        delete[] ptr;
    }

    // Method to set values
    void set(int index, int value) {
        if (index >= 0 && index < 10)
            ptr[index] = value;
    }

    // Method to print values
    void print() const {
        for (int i = 0; i < 10; ++i)
            cout << ptr[i] << " ";
        cout << endl;
    }
};

int main() {
    Base b1;
    b1.set(0, 100);
    b1.set(1, 200);

    Base b2 = b1; // Calls copy constructor

    b2.set(0, 999); // Modify b2, should not affect b1

    cout << "b1: "; b1.print();
    cout << "b2: "; b2.print();

    return 0;
}
