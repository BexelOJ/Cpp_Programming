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
    std::cout<<add5(15)<<std::endl; // Call the functor with 15
    int result = add5(10);  // Call the functor with 10
    std::cout << "Result: " << result << std::endl;  // Output: 15

    Adder b(25); // object created with value = 25;
    std::cout << b(35) << std::endl;  // output 60 // 25 + 35

    return 0;
}


/*

OUTPUT:
 
20
Result: 15
60

*/

/*

Adder add5(5);    // Object created (state: value=5)
add5(15);         // Calls: add5.operator()(15)

Surface syntax:  add5(15)     // Looks like function call
Actual call:     add5.operator()(15)  // Method call on object

add5 is the object. 
15 is the parameter passed to its operator() method.
The beauty of functors: object syntax looks like function call

*/


