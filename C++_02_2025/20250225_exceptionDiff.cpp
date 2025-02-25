#include <iostream>
#include <stdexcept>

void testException(int type) {
    if (type == 1)
        throw std::out_of_range("Out of range exception");
    else if (type == 2)
        throw std::invalid_argument("Invalid argument exception");
    else
        throw "Unknown exception type";  // Throwing a string
}

int main() {
    try {
        testException(3);  // Change this value to 2 or 3 to test different cases
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const char* msg) {
        std::cout << "Caught a string exception: " << msg << std::endl;
    }

    return 0;
}

