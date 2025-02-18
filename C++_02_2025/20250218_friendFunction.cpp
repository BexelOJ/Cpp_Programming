#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    // Constructor to initialize length
    Box(int len) : length(len) {}

    // Declare a friend function
    friend int calculateArea(Box b); // Friend function declaration
};

// Friend function definition
int calculateArea(Box b) {
    // Accessing private member of Box class
    return b.length * b.length; // Area of square (length * length)
}

int main() {
    Box box1(5); // Create an object of Box class
    cout << "Area of Box: " << calculateArea(box1) << endl; // Calling friend function

    return 0;
}



