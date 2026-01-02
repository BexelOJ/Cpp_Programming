#include <iostream>

using namespace std;

class Base {
public:
    char z;
    char x;
    int a;
    char y;
    int b;
};

class Derived : public Base {
public:
    int c;
    char e;
    int d;
};

int main() {
    // Creating a Base pointer to a Derived object
    Base *objB1;// = new Derived;
    
    // Creating a Derived pointer to a Derived object
    Derived *objD1 = new Derived;

    // Setting a value for 'a' from the Base class (which is inherited by Derived)
    objB1->a = 10;
    
    // Using static_cast to convert objB1 (Base*) to Derived* to access Derived class members
    Derived* derivedPtr = static_cast<Derived*>(objB1);
    
    // Now we can safely access members from the Derived class
    derivedPtr->c = 50;  // Accessing member 'c' from the Derived class

    cout << objB1->a<< endl; // Output should be value of a = 10

    cout << derivedPtr->c << endl; 

    // Clean up dynamically allocated memory
    //delete objB1;
    delete objD1;

    return 0;
}

Derived *derivedPtr = static_cast<Derived*>(ObjB1);