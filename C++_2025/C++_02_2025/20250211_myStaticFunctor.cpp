#include <iostream>

class Adder {
public:
    // Member variable to hold the value to be added
    int value = 0;

    // Constructor to initialize the value
    Adder(int val) : value(val) {}

    // Overload operator() to make the object callable like a function
    int operator()(int x) 
    {
        return value+x;   
    }
};

int main() 
{
    Adder add5(5);  // Creates an Object and set stateValue as 5.
    Adder add6(6);  // Creates an Object and set stateValue as 6.
    Adder add10(10);  // Creates an Object and set stateValue as 10.

    int result1 = add5(10);  // Calls the Function Object 'functor' with 10 as the parameter.
    int result2 = add5(20);  // Calls the Function Object 'functor' with 20 as the parameter.
    int result3 = add5(30);  // Calls the Function Object 'functor' with 30 as the parameter.
    std::cout << "Result1_5 : " << result1 << std::endl;  // Result: 15
    std::cout << "Result2_5 : " << result2 << std::endl;  // Result: 25
    std::cout << "Result3_5 : " << result3 << std::endl<< std::endl;  // Result: 35

    int result4 = add6(10);  // Call the functor add6 with 10
    int result5 = add6(20);
    int result6 = add6(30);
    std::cout << "Result4_6 : " << result4 << std::endl;  // Result: 16
    std::cout << "Result5_6 : " << result5 << std::endl;  // Result: 26
    std::cout << "Result6_6 : " << result6 << std::endl<< std::endl;  // Result: 36

    int result7 = add10(10);  // Call the functor add10 with 10
    int result8 = add10(20);
    int result9 = add10(30);
    std::cout << "Result7_10 : " << result7 << std::endl;  // Result: 20
    std::cout << "Result8_10 : " << result8 << std::endl;  // Result: 30
    std::cout << "Result9_10 : " << result9 << std::endl<< std::endl;  // Result: 40

    return 0;
}

/*
OUTPUT:

Result1_5 : 15
Result2_5 : 25
Result3_5 : 35

Result4_6 : 16
Result5_6 : 26
Result6_6 : 36

Result7_10 : 20
Result8_10 : 30
Result9_10 : 40

*/

