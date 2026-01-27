#include <iostream>

// Functions for addition, subtraction, multiplication, and division
int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int divi(int x, int y) {
    if (y != 0) {
        return x / y;
    } else {
        std::cout << "Error: Division by zero!" << std::endl;
        return 0; // Avoid division by zero
    }
}

// Declare and assign function pointers in one line
int (*fptr[4])(int, int) = { &add, &sub, &mul, &divi };

int main() {
    int a = 0, b = 0;
    
    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> a >> b;

    // Use function pointers to call the functions
    std::cout << "Addition Result: " << fptr[0](a, b) << std::endl;
    std::cout << "Subtraction Result: " << fptr[1](a, b) << std::endl;
    std::cout << "Multiplication Result: " << fptr[2](a, b) << std::endl;
    std::cout << "Division Result: " << fptr[3](a, b) << std::endl;

    return 0;
}

/*
OUTPUT:
Enter two numbers:
4 2
Addition Result: 6
Subtraction Result: 2
Multiplication Result: 8
Division Result: 2

*/

