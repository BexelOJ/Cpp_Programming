#include <iostream>

using namespace std;

class Base {
private:
    int a = 10;
    int b = 20;
public: 
    int c = 30;
    Base(int x, int y) : a(x), b(y) {
        cout << "Base Constructor Called" << endl;
    }
    
    // Copy constructor (deep copy)
    Base(const Base& other) {
        cout << "Base Copy Constructor Called" << endl;
        a = (other.a+1);
        b = (other.b+1);
        c = (other.c+1);
    }

    void Display() {
        cout << "Inside Base Class " <<a <<" " <<b <<" "<<c<<endl;
    }
};

int main() {
    // Create object on heap
    Base* b3 = new Base(1, 2);

    // Create a copy on the heap
    Base* b4 = new Base(*b3); // Calls the copy constructor

    // Display both objects
    b3->Display();
    b4->Display();

    // Free the allocated memory
    delete b3;
    delete b4;

    return 0;
}

/*
// Output:

Base Constructor Called
Base Copy Constructor Called
Inside Base Class
1 and 2
Inside Base Class
1 and 2

*/