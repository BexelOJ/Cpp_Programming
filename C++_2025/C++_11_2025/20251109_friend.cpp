// Friebnd Function Demonstration
#include <string>
#include <iostream>

using namespace std;

class Base {
    int value;
public:
    Base(int a) :value(a) {
        cout << "Base (Parameterized) Constructor Called"<<endl;
    }

    void display() {
        cout << "Displaying the value: "<<value<< endl;
    }

    ~Base(){
        cout << "Distructor called" << endl;
    }
};

class Derived: public Base {

public:

};


int main() {
    int n = 0;
    
    cout << "Enter the value: " << endl;
    cin >> n;

    Base b1(n);
    b1.display();

    Base* bptr1 = new Base(n);
    bptr1->display();

    delete bptr1;

    return 0;
}




