#include <iostream>

class Adder 
{
public:
    // Member variable to hold the value to be added
    int value;

    // Constructor to initialize the value
    Adder(int val) : value(val) {}

    // Overload operator() to make the object callable like a function
    int operator()(int x) 
    {
        return x + value;  // Add 'value' to 'x'
    }
};

int main() 
{
    Adder add5(5);  // Create a functor that adds 5

    int result = add5(10);  // Call the functor with 10
    std::cout << "Result: " << result << std::endl;  // Output: 15

    return 0;
}


