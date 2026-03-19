#include <iostream>
#include <cstddef>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // CLASS-SPECIFIC MEMORY OPERATORS (STATIC)
    static void* operator new(size_t size) {
        std::cout << "Custom new: " << size << " bytes\n";
        return ::operator new(size);  // Call global new
    }

    static void operator delete(void* ptr) noexcept {
        std::cout << "Custom delete\n";
        ::operator delete(ptr);  // Call global delete
    }

    static void* operator new[](size_t size) {
        return ::operator new[](size);
    }

    static void operator delete[](void* ptr) noexcept {
        ::operator delete[](ptr);
    }
};

int main() {
    SafeInt* obj = new SafeInt(42);  // Custom new called
    delete obj;                      // Custom delete called

    SafeInt* arr = new SafeInt[3];   // Array new
    delete[] arr;                    // Array delete
}


/*
OUTPUT:

Custom new: 4 bytes
Custom delete

*/


