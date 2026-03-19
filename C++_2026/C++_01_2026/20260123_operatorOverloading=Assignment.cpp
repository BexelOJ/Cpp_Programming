#include <iostream>
#include <cstring>

class SafeInt {
   
public:
    int* data;  // Dynamic memory - NEEDS deep copy!

    SafeInt(int v = 0) {
        data = new int(v);  // Allocate new memory
        std::cout << "Constructor: " << *data << std::endl;
    }

    // DEEP COPY ASSIGNMENT
    SafeInt& operator=(const SafeInt& other) {
        if (this != &other) {  // Self-assignment check
            delete data;       // Delete OLD memory
            data = new int(*other.data);  // Allocate NEW memory + copy
        }
        return *this;
    }

    // Destructor for Rule of Three
    ~SafeInt() {
        delete data;
        std::cout << "Destructor called" << std::endl;
    }

    void print() const {
        std::cout << *data << std::endl;
    }
};

int main() {
    SafeInt a(42), b(100);

    a = b;  // Deep copy: a gets NEW memory with 100
    a.print();  // 100

    *b.data = 999;  // Modify b
    a.print();  // Still 100 (independent!)

    return 0;
}


/*
OUTPUT:

Constructor: 42
Constructor: 100
100
100
Destructor called
Destructor called

EXPLANATION:



*/

