#include <iostream>
#include <cassert>  // For the assert function

using namespace std;

// Function to add two numbers
int add(int x, int y)
{
    return x + y;
}

// Function to test the add function
void testAdd(int x, int y, int expected)
{
    int result = add(x, y);
    // Assert if the result is not equal to the expected value
    assert(result == expected);
    cout << "Test passed for " << x << " + " << y << " = " << expected << endl;
}

int main()
{
    // Running test cases
    testAdd(2, 3, 5);     // Test case 1: 2 + 3 = 5
    testAdd(-1, 1, 0);    // Test case 2: -1 + 1 = 0
    testAdd(0, 0, 0);     // Test case 3: 0 + 0 = 0
    testAdd(-5, -3, -8);  // Test case 4: -5 + -3 = -8
    testAdd(100, 200, 300); // Test case 5: 100 + 200 = 300

    // Take user input for additional test
    int a, b;
    cout << "Enter two numbers to add: ";
    cin >> a >> b;
    cout << "Addition: " << add(a, b) << endl;

    return 0;
}


