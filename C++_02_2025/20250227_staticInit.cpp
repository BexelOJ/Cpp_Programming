#include <iostream>

using namespace std;

class Base{
private:
    const int a;    // Const variable, can only be initialized via constructor.
    static int b;   // Static member variable.
    const int &c = a;
public:
    Base(int x) : a(x)  // Initializing const variable a using constructor.
    {
        cout << "Parameterized Constructor called" << endl;
    }

    // Optional: A method to get the value of a and b to demonstrate functionality.
    void display() {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }

    // Optional: Static function to manipulate static b.
    static void setB(int val) {
        b = val;
    }
};

// Definition of the static member variable outside the class.
int Base::b = 20;

int main()
{
    Base b1(10);
    b1.display();  // Display values of a and b

    Base::setB(100);  // Modify static b using the static function.
    b1.display();  // Display updated values of a and b

    return 0;
}


