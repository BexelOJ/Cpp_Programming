#include <iostream>
using namespace std;

class Adder {
public:
    // Member variable to hold the value to be added
    int value;

    // Constructor to initialize the value
    Adder(int val) : value(val) {}

    // Overload operator() to make the object callable like a function
    int operator()(int x) 
    {
        return value+=x;  // 
    }
};

int main() 
{
    Adder add5(5);  // Create a functor that adds 5
    Adder add6(6);
    Adder add10(10);

    int result1 = add5(10);  // Call the functor with 10
    int result2 = add5(20);
    int result3 = add5(30);
    cout << "Result1_5 : " << result1 <<endl;  // Result: 15
    cout << "Result2_5 : " << result2 <<endl;  // Result: 35
    cout << "Result3_5 : " << result3 <<endl<<endl;  // Result: 65

    int result4 = add6(10);  // Call the functor with 10
    int result5 = add6(20);
    int result6 = add6(30);
    cout << "Result4_6 : " << result4 <<endl;  // Result: 16
    cout << "Result5_6 : " << result5 <<endl;  // Result: 36
    cout << "Result6_6 : " << result6 <<endl<<endl;  // Result: 66

    int result7 = add10(10);  // Call the functor with 10
    int result8 = add10(20);
    int result9 = add10(30);
    cout << "Result7_10 : " << result7 <<endl;  // Result: 20
    cout << "Result8_10 : " << result8 <<endl;  // Result: 40
    cout << "Result9_10 : " << result9 <<endl<<endl;  // Result: 70

    return 0;
}

