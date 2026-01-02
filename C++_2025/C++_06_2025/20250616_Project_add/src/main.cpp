#include <iostream>
#include "add.hpp"
#include "multiply.hpp"

int main() {
    int x = 0, y = 0;
    std::cout << "Enter two Numbers: " << std::endl;
    std::cin >> x >> y;
    std::cout << "Add: " << add(x, y) << std::endl;
    std::cout << "Multiply: " << multiply(x, y) << std::endl;
    return 0;
}


