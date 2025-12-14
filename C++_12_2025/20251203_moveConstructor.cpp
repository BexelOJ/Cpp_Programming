#include <iostream>

using namespace std;

class Base {
    int* data;
public:
    // Traditional constructor
    Base(int size) {
        data = new int[size];
        cout << "Regular Constructor" << endl;
    }
    
    // Move Constructor ✅
    Base(Base&& other) noexcept : data(other.data) {
        other.data = nullptr;  // Steal resource
        cout << "Move Constructor Called" << endl;
    }
    
    // Move Assignment
    Base& operator=(Base&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
        }
        cout << "Move Assignment Called" << endl;
        return *this;
    }

    void print() {
        if (data) cout << "Valid data" << endl;
        else cout << "NULLPTR data" << endl;
    }

    ~Base() {
        if (data) cout << "Deleting data" << endl;
        delete[] data;
    }

   // ~Base() { delete[] data; }
};

int main() {
    Base b1(10);                    // Regular
    
    // 1. Copy initialization (move)
    Base b2 = std::move(b1);        // ✅ Move Constructor, Copy Initialization
    
    b1.print();  // NULLPTR data  ✅
    b2.print();  // Valid data    ✅

    // 2. Direct initialization  
    Base b3(std::move(b2));         // ✅ Move Constructor, Direct Initialization
    
    // 3. Function return (NRVO + move)
    //  Base b4 = createObj();          // ✅ Move Constructor
    
    // 4. Move assignment
    Base b5(5);
    b5 = std::move(b3);             // ✅ Move Assignment
    

    
    return 0;
}

