#include <iostream>
#include <algorithm>

class SafeInt {
private:
    int value;
public:
    SafeInt(int v = 0) : value(v) {}

    // < comparison - returns bool
    bool operator>(const SafeInt& other) const {
        return value > other.value;
    }

    void print() const {
        std::cout << value << " ";
    }

};

int main() {
    SafeInt nums[] = { SafeInt(5), SafeInt(2), SafeInt(8) };
    
    /*
    std::sort(nums, nums + 3);  // Works! Uses operator<

    for (auto& n : nums) {
        n.print();  // Output: 2, 5, 8
    }
    std::cout << std::endl;
    */

    SafeInt a(10), b(3);
    std::cout << (a > b) << std::endl;  // 0 (false)
    std::cout << (b > a) << std::endl;  // 1 (true)
}


/*
OUTPUT:

1
0

*/
