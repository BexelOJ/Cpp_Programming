#include <iostream>

using namespace std;

class Base {
private:
    int a;
    int b;
public: 
    int c;
    Base(){cout << "Base Default Constructor Called" << endl;}
    Base(int x, int y) : a(x), b(y) {
        cout << "Base Parameterized Constructor Called" << endl;
    }
    
    // No explicit copy constructor, this will be shallow copy
    void Display() {
        cout << "Inside Base Class" << endl;
        cout << a << " and " << b << endl;
    }
};

int main() {
    // Create object on stack
    Base sb(50,60);
    sb.Display(); 

    Base sc = sb;
    sc.Display();

    // Create object on heap
    Base* b1 = new Base();
    Base* b2 = new Base(1,2);
    Base* b3 = new Base(3,4);
    
    // Create another object and assign b3 to b4, invoking shallow copy
    Base* b4 = b3; // Shallow copy - both b3 and b4 point to the same object

    // Display both objects 
    cout << "b3: ";
    b3->Display();
    cout << "b4: ";
    b4->Display();

    b3->c=50;
    cout<<b3->c<<endl;
    cout<<b4->c+30<<endl;

    //cout<<b3->a<<endl;
    // No need for explicit copy constructor because b4 is just another pointer to b3 (shallow copy)
    // Free the allocated memory
    delete b4;  // is same as delete b3
    // Deletes the object that both b3 and b4 point to

    delete b1;
    delete b2;

    return 0;
}

/*
Output:

Base Parameterized Constructor Called
Inside Base Class
50 and 60
Inside Base Class
50 and 60
Base Default Constructor Called
Base Parameterized Constructor Called
Base Parameterized Constructor Called
b3: Inside Base Class
3 and 4
b4: Inside Base Class
3 and 4
50
80

*/


