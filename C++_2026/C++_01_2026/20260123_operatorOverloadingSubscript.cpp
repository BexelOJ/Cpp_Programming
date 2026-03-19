#include <iostream>
#include <stdexcept>

class MyArray {
    int* data;
    size_t size;
public:
    // Non-const: returns reference (lvalue - can modify)
    int& operator[](size_t index) {
        return data[index];  // Bounds checking recommended
    }

    // Const: returns const reference (rvalue - read-only)
    const int& operator[](size_t index) const {
        return data[index];
    }
};

class SafeArray {
private:
    int* arr;
    size_t sz;

public:
    SafeArray(size_t size) : sz(size) {
        arr = new int[sz]();
    }

    ~SafeArray() { delete[] arr; }

    // Modifiable access
    int& operator[](size_t i) {
        if (i >= sz) throw std::out_of_range("Index out of bounds");
        return arr[i];
    }

    // Read-only access
    const int& operator[](size_t i) const {
        if (i >= sz) throw std::out_of_range("Index out of bounds");
        return arr[i];
    }

    size_t size() const { return sz; }
};

int main() {
    SafeArray vec(5);

    vec[0] = 100;           // Uses non-const overload
    vec[1] = 200;

    std::cout << vec[0] << ", " << vec[1] << std::endl;  // 100, 200

    const SafeArray& cvec = vec;
    std::cout << cvec[0] << std::endl;  // Uses const overload

    return 0;
}

/*
OPUTPUT:

100, 200
100

*/

