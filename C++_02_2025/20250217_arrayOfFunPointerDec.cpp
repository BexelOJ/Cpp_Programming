#include <iostream>

using namespace std;

// Declare and assign function pointers in one line
int (*fptr[4])(int, int) = {&add, &sub, &mul, &divi}; // Function pointer array with initialization

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
        cout << "Error: Division by zero!" << endl;
        return 0; // Avoid division by zero
    }
}

int main() {
    int a = 0, b = 0;
    
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;

    // Use function pointers to call the functions
    cout << "Addition Result: " << fptr[0](a, b) << endl;
    cout << "Subtraction Result: " << fptr[1](a, b) << endl;
    cout << "Multiplication Result: " << fptr[2](a, b) << endl;
    cout << "Division Result: " << fptr[3](a, b) << endl;

    return 0;
}

