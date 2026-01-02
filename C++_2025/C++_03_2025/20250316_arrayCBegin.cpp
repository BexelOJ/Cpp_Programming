#include <iostream>
#include <array>

using namespace std;

int main() {
    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

    // Using begin() - You can modify the element
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        *it += 10;  // Modifying elements
    }

    // Output modified array
    std::cout << "Modified array with begin(): ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    // Using cbegin() - You cannot modify the elements
    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        // *it += 10;  // This line would cause a compiler error because `it` is constant
        std::cout << *it << " ";  // You can only read, not modify
    }

    std::cout << std::endl;

    return 0;
}




