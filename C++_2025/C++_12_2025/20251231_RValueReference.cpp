#include <iostream>
#include <cstddef>

class MyVector {
    int* data;
    size_t size;

public:
    // Default constructor
    MyVector(size_t n = 0) : data(nullptr), size(n) {
        if (n > 0) {
            data = new int[n];  // Allocate and initialize [web:20]
            std::fill(data, data + n, 0);
        }
    }

    // Destructor
    ~MyVector() { delete[] data; }

    // Copy constructor (expensive - deep copy)
    MyVector(const MyVector& other) : size(other.size) {
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }

    // Move constructor (cheap - steal resources)
    MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;   // Source becomes empty
        other.size = 0;
    }

    // Print for demo
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyVector v1(1000);           // Uses default ctor with size=1000
    std::cout << "v1 before move: ";
    v1.print();  // Shows 1000 zeros

    MyVector v2(std::move(v1));  // Move ctor - v1.data becomes nullptr
    std::cout << "v2 after move: ";
    v2.print();  // Shows 1000 zeros (stolen from v1)

    return 0;
}
