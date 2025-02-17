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
    
    // No explicit copy constructor, this will be shallow copy
    void Display() {
        cout << "Inside Base Class" << endl;
        cout << a << " and " << b << endl;
    }
};

int main() {
    // Create object on heap
    Base* b3 = new Base(1, 2);

    // Create another object and assign b3 to b4, invoking shallow copy
    Base* b4 = b3; // Shallow copy - both b3 and b4 point to the same object

    // Display both objects
    cout << "b3: ";
    b3->Display();
    cout << "b4: ";
    b4->Display();

    // No need for explicit copy constructor because b4 is just another pointer to b3 (shallow copy)
    // Free the allocated memory
    delete b3;  // Deletes the object that both b3 and b4 point to

    return 0;
}

/*
Output:

Base Constructor Called
b3: Inside Base Class
1 and 2
b4: Inside Base Class
1 and 2

*/