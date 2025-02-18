#include <iostream>

using namespace std;

class Box 
{
private:
    double length;
public:
    Box() : length(10.0) {}
    
    // Friend function declaration
    friend void printLength(Box b);
};

// Friend function definition
void printLength(Box &b) 
{
    b.length = this;
    cout << "Length of box: " << b.length << endl;  // Access private member
}

int main() 
{
    Box xy;
    printLength(xy);  // Calling the friend function
    return 0;
}



