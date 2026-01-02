#include <iostream>
#include <stdexcept>  // For standard exceptions like std::out_of_range

// Function that may throw an exception
void mayThrowException(bool condition) {
    if (condition) {
        throw std::out_of_range("Out of range error occurred!");
    }
    std::cout << "No error!" << std::endl;
}

int main() {
    try {
        mayThrowException(true);  // Will throw exception
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Caught some other exception" << std::endl;
    }

    return 0;
}

